#ifndef GRAPH_TRAVERSER_H
#define GRAPH_TRAVERSER_H

#include <memory>
#include <optional>
#include <vector>

#include "graph.hpp"

namespace uni {

class GraphTraverser {
 public:
  // https://en.cppreference.com/w/cpp/keyword/using
  using VertexCallback = void (*)(Graph::Vertex);
  using EdgeCallback = void (*)(Graph::Edge);

  explicit GraphTraverser(const Graph& graph) : graph_(graph) {}

  void traverse(size_t from_pos, VertexCallback vertex_callback, EdgeCallback edge_callback) const;
  void traverse_bfs(size_t from_pos, VertexCallback vertex_callback, EdgeCallback edge_callback) const;
  void traverse_dfs(size_t from_pos, VertexCallback vertex_callback, EdgeCallback edge_callback) const;

  std::optional<std::vector<Graph::Vertex>> path_dijkstra(size_t from_pos, size_t to_pos) const;

 private:
  const Graph& graph_;
};

}  // namespace uni

#endif  // GRAPH_TRAVERSER_H
