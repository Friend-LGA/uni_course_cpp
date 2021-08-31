#ifndef GRAPH_TRAVERSER_H
#define GRAPH_TRAVERSER_H

#include <memory>
#include <optional>
#include <vector>

#include "graph.hpp"

namespace uni {

template <typename G>
class GraphTraverser {
 public:
  using VertexIterator = typename G::VertexIterator;
  using EdgeIterator = typename G::EdgeIterator;
  using VertexCallback = void (*)(VertexIterator);
  using EdgeCallback = void (*)(EdgeIterator);

  explicit GraphTraverser(const G& graph) : graph_(graph) {}

  void traverse(VertexIterator from_iter, VertexCallback vertex_callback, EdgeCallback edge_callback) const {
    //
  }

  void traverse_bfs(VertexIterator from_iter, VertexCallback vertex_callback, EdgeCallback edge_callback) const {
    //
  }

  void traverse_dfs(VertexIterator from_iter, VertexCallback vertex_callback, EdgeCallback edge_callback) const {
    //
  }

  std::optional<std::vector<VertexIterator>> path_dijkstra(VertexIterator from_iter, VertexIterator to_iter) const {
    return std::nullopt;
  }

 private:
  const G& graph_;
};

}  // namespace uni

#endif  // GRAPH_TRAVERSER_H
