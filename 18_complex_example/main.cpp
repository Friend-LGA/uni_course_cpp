#include "graph.hpp"
#include "graph_traverser.hpp"

int main() {
  auto graph = uni::Graph<int, int>();
  auto graph_traverser = uni::GraphTraverser(graph);

  return 0;
}
