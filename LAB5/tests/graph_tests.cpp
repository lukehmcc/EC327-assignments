#include "../src/lab5_problem1.h"
#include <gtest/gtest.h>

class GraphTest : public ::testing::Test {
protected:
  Graph G;
  void SetUp() override {
    G += 1;
    G += 2;
    G += 3;
  }
};

// Test empty graph
TEST_F(GraphTest, EmptyGraph) {
  Graph empty;
  EXPECT_EQ(empty.numVertices(), 0);
  EXPECT_EQ(empty.numEdges(), 0);
  EXPECT_FALSE(empty.hasEdge(1, 2));
}

// Test vertex addition
TEST_F(GraphTest, AddVertex) {
  EXPECT_EQ(G.numVertices(), 3);
  G += 4;
  EXPECT_EQ(G.numVertices(), 4);
}

// Test duplicate vertex
TEST_F(GraphTest, DuplicateVertexThrows) {
  EXPECT_THROW({ G += 2; }, std::logic_error);
}

// Test edge operations
TEST_F(GraphTest, AddAndCheckEdge) {
  EXPECT_FALSE(G.hasEdge(1, 2));
  G.addEdge(1, 2);
  EXPECT_TRUE(G.hasEdge(1, 2));
  EXPECT_TRUE(G.hasEdge(2, 1)); // Undirected
  EXPECT_EQ(G.numEdges(), 1);
}

// Test invalid edge cases
TEST_F(GraphTest, InvalidEdgeThrows) {
  // Non-existent vertex
  EXPECT_THROW({ G.addEdge(1, 99); }, std::invalid_argument);

  // Duplicate edge
  G.addEdge(1, 2);
  EXPECT_THROW({ G.addEdge(2, 1); }, std::invalid_argument);
}

// Test large graph
TEST_F(GraphTest, LargeGraph) {
  Graph large;
  for (int i = 0; i < 1000; i++) {
    large += i;
  }
  EXPECT_EQ(large.numVertices(), 1000);

  for (int i = 0; i < 999; i++) {
    large.addEdge(i, i + 1);
  }
  EXPECT_EQ(large.numEdges(), 999);
  EXPECT_TRUE(large.hasEdge(500, 501));
}

// Test special vertex values
TEST_F(GraphTest, SpecialVertices) {
  Graph special;
  special += 0;
  special += -1;
  special.addEdge(0, -1);
  EXPECT_TRUE(special.hasEdge(0, -1));
  EXPECT_EQ(special.numVertices(), 2);
}

// Test edge count stability
TEST_F(GraphTest, EdgeCountStability) {
  size_t before = G.numVertices();
  G.addEdge(1, 2);
  EXPECT_EQ(G.numVertices(), before);
}

// Test multiple edges
TEST_F(GraphTest, MultipleEdges) {
  G.addEdge(1, 2);
  G.addEdge(2, 3);
  EXPECT_EQ(G.numEdges(), 2);
  EXPECT_FALSE(G.hasEdge(1, 3));
}
