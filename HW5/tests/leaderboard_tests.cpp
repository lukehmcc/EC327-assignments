#include "../src/Leaderboard.h"
#include <gtest/gtest.h>

class LeaderboardTest : public ::testing::Test {
protected:
  Leaderboard lb;

  void SetUp() override {
    // Initialize with some test data
    lb.addOrUpdatePlayer("Alice", 100);
    lb.addOrUpdatePlayer("Bob", 200);
    lb.addOrUpdatePlayer("Charlie", 50);
  }
};

// Test adding new players
TEST_F(LeaderboardTest, AddNewPlayer) {
  lb.addOrUpdatePlayer("Diana", 300);
  auto top = lb.getTopN(4);
  ASSERT_EQ(top[0].first, "Diana");
  ASSERT_EQ(top[0].second, 300);
}

// Test updating existing players
TEST_F(LeaderboardTest, UpdatePlayer) {
  lb.addOrUpdatePlayer("Bob", 250); // Update Bob's score
  auto top = lb.getTopN(3);
  ASSERT_EQ(top[0].first, "Bob");
  ASSERT_EQ(top[0].second, 250);
}

// Test removing players
TEST_F(LeaderboardTest, RemovePlayer) {
  lb.removePlayer("Alice");
  auto top = lb.getTopN(3);
  ASSERT_EQ(top.size(), 2);
  ASSERT_EQ(top[0].first, "Bob");
}

// Test getTopN with N larger than board size
TEST_F(LeaderboardTest, GetTopN_LargerThanSize) {
  auto top = lb.getTopN(10);
  ASSERT_EQ(top.size(), 3);
}

// Test getTopN with N=0
TEST_F(LeaderboardTest, GetTopN_Zero) {
  auto top = lb.getTopN(0);
  ASSERT_TRUE(top.empty());
}

// Test getTopN with negative N
TEST_F(LeaderboardTest, GetTopN_Negative) {
  auto top = lb.getTopN(-1);
  ASSERT_TRUE(top.empty());
}

// Test empty leaderboard
TEST_F(LeaderboardTest, EmptyLeaderboard) {
  Leaderboard empty;
  auto top = empty.getTopN(3);
  ASSERT_TRUE(top.empty());
}

// Test multiple players with same score
TEST_F(LeaderboardTest, SameScorePlayers) {
  lb.addOrUpdatePlayer("Diana", 200); // Same as Bob
  auto top = lb.getTopN(4);
  ASSERT_EQ(top[0].second, 200);
  ASSERT_EQ(top[1].second, 200);
}

// Test removing non-existent player
TEST_F(LeaderboardTest, RemoveNonExistentPlayer) {
  EXPECT_NO_THROW(lb.removePlayer("NonExistent"));
  ASSERT_EQ(lb.getTopN(3).size(), 3);
}

// Test descending order
TEST_F(LeaderboardTest, DescendingOrder) {
  auto top = lb.getTopN(3);
  ASSERT_GE(top[0].second, top[1].second);
  ASSERT_GE(top[1].second, top[2].second);
}

// Test large N values
TEST_F(LeaderboardTest, LargeN) {
  for (int i = 0; i < 1000; ++i) {
    lb.addOrUpdatePlayer("Player" + std::to_string(i), i);
  }
  auto top = lb.getTopN(500);
  ASSERT_EQ(top.size(), 500);
  ASSERT_EQ(top[0].second, 999); // Highest score
}

// Test score zero and negative scores
TEST_F(LeaderboardTest, EdgeScores) {
  lb.addOrUpdatePlayer("Zero", 0);
  lb.addOrUpdatePlayer("Negative", -5);
  auto top = lb.getTopN(5);
  ASSERT_EQ(top.back().first, "Negative");
  ASSERT_EQ(top.back().second, -5);
}
