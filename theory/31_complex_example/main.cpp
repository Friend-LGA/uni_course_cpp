#include "graph.hpp"
#include "graph_generator.hpp"
#include "graph_traverser.hpp"

int main() {
  const auto graph_generator = uni::GraphGenerator({.depth = 10});
  const auto graph = graph_generator.generate();
  const auto graph_traverser = uni::GraphTraverser(graph);

  graph_traverser.traverse(
      0,
      [](uni::Graph::Vertex& vertex) {
        // ... some logic ...
      },
      [](uni::Graph::Edge& edge) {
        // ... some logic ...
      });

  return 0;
}
