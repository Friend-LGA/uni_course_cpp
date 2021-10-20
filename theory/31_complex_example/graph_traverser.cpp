#include "graph_traverser.hpp"

using Graph = uni::Graph;
using VertexId = uni::Graph::VertexId;

namespace {

void validate_vertex_existance(const Graph& graph, const VertexId id) {
  assert(graph.find_vertex(id).has_value() &&
         "Vertex with provided id doesn't exist");
}

}  // namespace

namespace uni {

void GraphTraverser::traverse(const VertexId& from_vertex_id,
                              const VertexCallback& vertex_callback,
                              const EdgeCallback& edge_callback) const {
  validate_vertex_existance(graph_, from_vertex_id);
  // ... some complex logic ...
}

void GraphTraverser::traverse_bfs(const VertexId& from_vertex_id,
                                  const VertexCallback& vertex_callback,
                                  const EdgeCallback& edge_callback) const {
  validate_vertex_existance(graph_, from_vertex_id);
  // ... some complex logic ...
}

void GraphTraverser::traverse_dfs(const VertexId& from_vertex_id,
                                  const VertexCallback& vertex_callback,
                                  const EdgeCallback& edge_callback) const {
  validate_vertex_existance(graph_, from_vertex_id);
  // ... some complex logic ...
}

std::optional<std::vector<Graph::Vertex>> GraphTraverser::path_dijkstra(
    const VertexId& from_vertex_id,
    const VertexId& to_vertex_id) const {
  validate_vertex_existance(graph_, from_vertex_id);
  validate_vertex_existance(graph_, to_vertex_id);
  // ... some complex logic ...
  return std::nullopt;
}

}  // namespace uni
