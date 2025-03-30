#include "../src/lab5_problem2.h"
#include <gtest/gtest.h>

class GraphTest : public ::testing::Test {
protected:
  Graph G;
  void SetUp() override {
    // Basic graph from first example
    G += 3;
    G += 4;
    G += 5;
    G += 6;
    G += 7;
    G += 8;
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(3, 6);
    G.addEdge(6, 7);
    G.addEdge(3, 8);
  }
};

// Test empty graph case
TEST_F(GraphTest, TwoHopEmptyGraph) {
  Graph empty;
  EXPECT_TRUE(empty.twoHopNeighbors(1).empty());
}

// Test non-existent vertex
TEST_F(GraphTest, TwoHopNonExistentVertex) {
  EXPECT_TRUE(G.twoHopNeighbors(99).empty());
}

// Test vertex with no edges
TEST_F(GraphTest, TwoHopNoEdges) {
  G += 9; // Isolated vertex
  EXPECT_TRUE(G.twoHopNeighbors(9).empty());
}

// Test vertex with only direct neighbors (no two-hop)
TEST_F(GraphTest, TwoHopOnlyDirectNeighbors) {
  G.addEdge(5, 9); // Add edge from leaf node
  EXPECT_TRUE(G.twoHopNeighbors(5).empty());
}

// Test basic two-hop neighbors (from example)
TEST_F(GraphTest, TwoHopBasicCase1) {
  std::set<int> expected = {5, 7};
  EXPECT_EQ(G.twoHopNeighbors(3), expected);
}

// Test basic two-hop neighbors (from example)
TEST_F(GraphTest, TwoHopBasicCase2) {
  std::set<int> expected = {6, 8};
  EXPECT_EQ(G.twoHopNeighbors(4), expected);
}

// Test two-hop neighbors with cycle
TEST_F(GraphTest, TwoHopWithCycle) {
  G.addEdge(5, 3); // Create cycle
  std::set<int> expected = {4, 6, 7, 8};
  EXPECT_EQ(G.twoHopNeighbors(5), expected);
}

// Test two-hop neighbors with multiple paths
TEST_F(GraphTest, TwoHopMultiplePaths) {
  G.addEdge(4, 7); // Add alternative path
  std::set<int> expected = {5, 6, 7, 8};
  EXPECT_EQ(G.twoHopNeighbors(3), expected);
}

// Test two-hop neighbors with duplicate paths
TEST_F(GraphTest, TwoHopDuplicatePaths) {
  G.addEdge(4, 6); // Creates multiple two-hop paths to 6
  std::set<int> result = G.twoHopNeighbors(3);
  EXPECT_EQ(result.count(6), 1); // Should still appear only once
}

// Test two-hop neighbors from second example graph
TEST_F(GraphTest, TwoHopSecondExample) {
  Graph G2;
  G2 += 3;
  G2 += 4;
  G2 += 9;
  G2 += 6;
  G2.addEdge(3, 4);
  G2.addEdge(4, 9);
  G2.addEdge(3, 9);
  G2.addEdge(9, 6);
  G2.addEdge(3, 6);

  std::set<int> expected1 = {4, 6, 9};
  EXPECT_EQ(G2.twoHopNeighbors(3), expected1);

  std::set<int> expected2 = {3, 6, 9};
  EXPECT_EQ(G2.twoHopNeighbors(4), expected2);
}

// Test two-hop neighbors with disconnected components
TEST_F(GraphTest, TwoHopDisconnected) {
  G += 10;
  G += 11;
  G += 12;
  G.addEdge(10, 11);
  G.addEdge(11, 12);

  std::set<int> expected = {12};
  EXPECT_EQ(G.twoHopNeighbors(10), expected);
  EXPECT_TRUE(G.twoHopNeighbors(12).empty());
}

// Test two-hop neighbors with self-loops (if allowed)
TEST_F(GraphTest, TwoHopWithSelfLoops) {
  G.addEdge(3, 3); // Self-loop
  std::set<int> result = G.twoHopNeighbors(3);
  EXPECT_EQ(result.count(3), 0); // Should not include self
}
