#include "graph_traverser.hpp"

namespace {

void validate_vertex_pos(size_t pos, const uni::Graph& graph) {
  assert(pos < graph.size() && "Vertex position is out of range");
}

}  // namespace

namespace uni {

void GraphTraverser::traverse(size_t from_pos, VertexCallback vertex_callback, EdgeCallback edge_callback) const {
  validate_vertex_pos(from_pos, graph_);
  // ... some complex logic ...
}

void GraphTraverser::traverse_bfs(size_t from_pos, VertexCallback vertex_callback, EdgeCallback edge_callback) const {
  validate_vertex_pos(from_pos, graph_);
  // ... some complex logic ...
}

void GraphTraverser::traverse_dfs(size_t from_pos, VertexCallback vertex_callback, EdgeCallback edge_callback) const {
  validate_vertex_pos(from_pos, graph_);
  // ... some complex logic ...
}

std::optional<std::vector<Graph::Vertex>> GraphTraverser::path_dijkstra(size_t from_pos, size_t to_pos) const {
  validate_vertex_pos(from_pos, graph_);
  validate_vertex_pos(to_pos, graph_);
  // ... some complex logic ...
  return std::nullopt;
}

}  // namespace uni
