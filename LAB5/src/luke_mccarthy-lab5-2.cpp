#include "lab5_problem2.h"
Graph &Graph::operator+=(int ID) {
  if (vertices.count(ID) > 0) {
    throw std::logic_error("Vertex already exists");
  }
  vertices.insert(ID);
  return *this;
}
bool Graph::hasEdge(int ID1, int ID2) {
  std::pair<int, int> edge = std::minmax(ID1, ID2);
  return (edges.count(edge) == 1) ? true : false;
}
void Graph::addEdge(int ID1, int ID2) {
  if (vertices.count(ID1) == 0 || vertices.count(ID2) == 0) {
    throw std::invalid_argument("One or both vertices do not exist");
  }
  // making sure to sort here to have have dupes
  std::pair<int, int> edge = std::minmax(ID1, ID2);
  if (edges.count(edge) > 0) {
    throw std::invalid_argument("Edge already exists");
  }
  edges.insert(edge);
}
int Graph::numVertices() { return vertices.size(); }
int Graph::numEdges() { return edges.size(); }
set<int> Graph::twoHopNeighbors(int ID) {
  set<int> firstLevelNeighbors = findNeighbors(ID);
  set<int> secondLevelNeighbors = {};
  for (int subID : firstLevelNeighbors) {
    set<int> tmp = findNeighbors(subID);
    secondLevelNeighbors.insert(tmp.begin(), tmp.end());
    secondLevelNeighbors.erase(ID);
  }
  return secondLevelNeighbors;
}
set<int> Graph::findNeighbors(int ID) {
  // first check if ID exists
  if (vertices.count(ID) == 0) {
    return {};
  }
  // Collects all neighboring points
  set<int> neighbors = {};
  for (pair<int, int> edge : edges) {
    if (edge.first == ID) {
      neighbors.insert(edge.second);
    } else if (edge.second == ID) {
      neighbors.insert(edge.first);
    }
  }
  return neighbors;
}
