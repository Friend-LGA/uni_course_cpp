#pragma once

#include <memory>
#include <optional>
#include <vector>

#include "graph.hpp"

namespace uni {

class GraphTraverser {
 public:
  using VertexCallback = void (*)(Graph::Vertex&);
  using EdgeCallback = void (*)(Graph::Edge&);

  explicit GraphTraverser(const Graph& graph) : graph_(graph) {}

  void traverse(const Graph::VertexId& from_vertex_id,
                const VertexCallback& vertex_callback,
                const EdgeCallback& edge_callback) const;

  void traverse_bfs(const Graph::VertexId& from_vertex_id,
                    const VertexCallback& vertex_callback,
                    const EdgeCallback& edge_callback) const;

  void traverse_dfs(const Graph::VertexId& from_vertex_id,
                    const VertexCallback& vertex_callback,
                    const EdgeCallback& edge_callback) const;

  std::optional<std::vector<Graph::Vertex>> path_dijkstra(
      const Graph::VertexId& from_vertex_id,
      const Graph::VertexId& to_vertex_id) const;

 private:
  const Graph& graph_;
};

}  // namespace uni
