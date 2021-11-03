#pragma once

#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

namespace uni {

class Graph {
 public:
  using VertexId = int;
  using EdgeId = int;

  struct Vertex {
    VertexId id;
    std::vector<EdgeId> edge_ids;

    explicit Vertex(const VertexId& _id) : id(_id) {}

    bool operator==(const Vertex& other) const { return id == other.id; }
  };

  struct Edge {
    EdgeId id;
    VertexId from_vertex_id;
    VertexId to_vertex_id;

    Edge(const EdgeId& _id,
         const VertexId& _from_vertex_id,
         const VertexId& _to_vertex_id)
        : id(_id),
          from_vertex_id(_from_vertex_id),
          to_vertex_id(_to_vertex_id) {}

    bool operator==(const Edge& other) const { return id == other.id; }
  };

  Graph() = default;

  size_t size() const { return vertices_.size(); }
  bool empty() const { return vertices_.empty(); }
  size_t edges_size() const { return edges_.size(); }

  Vertex vertex_at(size_t pos) const;
  Vertex operator[](size_t pos) const;
  std::optional<Vertex> find_vertex(const VertexId& id) const;

  Vertex add_vertex();
  void remove_vertex(const VertexId& id);

  Edge add_edge(const VertexId& from_vertex_id, const VertexId& to_vertex_id);

  void remove_edge(const VertexId& from_vertex_id,
                   const VertexId& to_vertex_id);

  std::vector<Vertex> neighbours(const VertexId& id) const;
  std::vector<Edge> edges(const VertexId& id) const;

  bool has_vertex(const VertexId& id) const;

  bool is_connected(const VertexId& from_vertex_id,
                    const VertexId& to_vertex_id) const;

  bool operator==(const Graph& other) const {
    return vertices_ == other.vertices_ && edges_ == other.edges_;
  };

 private:
  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;
};

}  // namespace uni
