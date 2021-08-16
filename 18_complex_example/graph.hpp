#ifndef GRAPH_H
#define GRAPH_H

#include <exception>
#include <iterator>
#include <map>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace uni {

// Iterator convention
template <typename VertexData, typename EdgeData>
class Graph {
 public:
  class EdgeIterator;

  class VertexIterator : public std::iterator<std::input_iterator_tag, VertexData> {
   public:
    explicit VertexIterator(const Graph& graph, size_t pos = 0) : graph_(graph), pos_(pos) {}

    VertexIterator operator+(int value) {}
    VertexIterator operator++(int) {}
    VertexIterator operator-(int value) {}
    VertexIterator operator--(int) {}
    bool operator==(const VertexIterator& other) const { return graph_ == other.graph_ && pos_ == other.pos_; }
    bool operator!=(const VertexIterator& other) const { return !(*this == other); }

    VertexData& operator*() const { return graph_[pos_].data; }

    std::vector<EdgeIterator> edges() const { return graph_.edges(*this); }

   private:
    const Graph& graph_;
    size_t pos_;

    void update_pos(size_t new_pos);
  };

  class EdgeIterator : public std::iterator<std::input_iterator_tag, EdgeData> {
    explicit EdgeIterator(const Graph& graph, size_t vertex_pos = 0, size_t edge_pos = 0)
        : graph_(graph), vertex_pos_(vertex_pos), edge_pos_(edge_pos) {}

    EdgeIterator operator+(int value) {}
    EdgeIterator operator++(int) {}
    EdgeIterator operator-(int value) {}
    EdgeIterator operator--(int) {}
    bool operator==(const EdgeIterator& other) const {
      return graph_ == other.graph_ && vertex_pos_ == other.vertex_pos_ && edge_pos_ == other.edge_pos_;
    }
    bool operator!=(const EdgeIterator& other) const { return !(*this == other); }

    EdgeData& operator*() const { return graph_[vertex_pos_].edges[edge_pos_].data; }

    std::vector<VertexIterator> vertices() { return graph_.vertices(*this); }

   private:
    const Graph& graph_;
    size_t vertex_pos_;
    size_t edge_pos_;
  };

  enum class ConnectionStatus { Ok, AlreadyConnected };
  enum class DisconnectionStatus { Ok, EdgeDoesNotExist };

  explicit Graph() {}

  size_t size() const { return adj_list_.size(); }
  bool empty() const { return adj_list_.empty(); }
  size_t edges_count() const { return edges_count_; };

  VertexIterator begin() const { return VertexIterator(*this, 0); }
  VertexIterator end() const { return VertexIterator(*this, adj_list_.size()); }

  EdgeIterator edges_begin() const { return EdgeIterator(*this, 0, 0); }
  EdgeIterator edges_end() const {
    return EdgeIterator(*this, adj_list_.size() - 1, at(adj_list_.size() - 1).edges.size());
  }

  VertexIterator add_vertex(const VertexData& data = {}) {}
  void remove_vertex(VertexIterator iter) {}

  std::tuple<ConnectionStatus, EdgeIterator> add_edge(VertexIterator from_iter, VertexIterator to_iter,
                                                      const EdgeData& data = {}) {}

  DisconnectionStatus remove_edge(VertexIterator from_iter, VertexIterator to_iter) {}

  std::vector<VertexIterator> neighbours(VertexIterator iter) const {}
  std::vector<EdgeIterator> edges(VertexIterator iter) const {}
  EdgeIterator edge_between(VertexIterator from_iter, VertexIterator to_iter) const {}
  std::vector<VertexIterator> vertices(EdgeIterator iter) const {}

  bool is_connected(VertexIterator from_iter, VertexIterator to_iter) const {}

  bool operator==(const Graph& other) { return adj_list_ == other.adj_list_; };

 private:
  struct Edge;

  struct Vertex {
    VertexData data;
    std::vector<Edge> edges;
  };

  struct Edge {
    EdgeData data;
    Vertex& vertex;
  };

  std::vector<std::unique_ptr<Vertex>> adj_list_;
  size_t edges_count_;
};

}  // namespace uni

#endif  // GRAPH_H
