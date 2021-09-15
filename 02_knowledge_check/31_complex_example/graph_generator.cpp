#include "graph_generator.hpp"

#include "graph.hpp"

namespace uni {

using VertexId = Graph::VertexId;

Graph GraphGenerator::generate() const {
  auto graph = Graph();
  VertexId prev_vertex_id;
  for (int i = 0; i < options_.depth; i++) {
    const auto vertex = graph.add_vertex();
    if (i > 0) {
      graph.add_edge(prev_vertex_id, vertex.id);
    }
    prev_vertex_id = vertex.id;
  }
  return graph;
}

}  // namespace uni
