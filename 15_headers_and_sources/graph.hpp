// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-source

// https://en.wikipedia.org/wiki/Include_guard
#ifndef GRAPH_H
#define GRAPH_H

// The same purpose, but less supported
// #pragma once

// Prefer the quoted form of #include for files relative to the including file
// and the angle bracket form everywhere else
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#sf12-prefer-the-quoted-form-of-include-for-files-relative-to-the-including-file-and-the-angle-bracket-form-everywhere-else
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

namespace uni {

// Iterator convention
class Graph {
 public:
  struct VertexData {
    std::string label;
  };

  struct EdgeData {
    int weight;
  };

  struct Vertex {
    VertexData data;
    size_t pos;
  };

  struct Edge {
    EdgeData data;
    size_t from_vertex_pos;
    size_t to_vertex_pos;
  };

  enum class ConnectionStatus { Ok, AlreadyConnected };
  enum class DisconnectionStatus { Ok, EdgeDoesNotExist };

  size_t size() const { return vertices_.size(); }
  bool empty() const { return vertices_.empty(); }
  size_t edges_count() const { return edges_.size(); }

  Vertex vertex_at(size_t pos) const;
  Vertex operator[](size_t pos) const;

  Vertex add_vertex(const VertexData& data = {});
  void remove_vertex(size_t pos);

  std::tuple<ConnectionStatus, std::optional<Edge>> add_edge(size_t from_pos, size_t to_pos, const EdgeData& data = {});
  DisconnectionStatus remove_edge(size_t from_pos, size_t to_pos);

  std::vector<Vertex> neighbours(size_t pos) const;
  std::vector<Edge> edges_from(size_t pos) const;

  bool is_connected(size_t from_pos, size_t to_pos) const;

  // You can define different operators
  // https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
  // https://en.cppreference.com/w/cpp/language/operators
  bool operator==(const Graph& other) { return vertices_ == other.vertices_ && edges_ == other.edges_; };

 private:
  // Forward declaration
  // https://en.cppreference.com/w/cpp/language/class
  // https://en.wikipedia.org/wiki/Forward_declaration
  struct EdgeInternal;

  struct VertexInternal {
    VertexData data;
    std::vector<EdgeInternal*> edges;
  };

  struct EdgeInternal {
    EdgeData data;
    VertexInternal& vertex;
  };

  std::vector<std::unique_ptr<VertexInternal>> vertices_;
  std::vector<std::unique_ptr<EdgeInternal>> edges_;
};

}  // namespace uni

#endif  // GRAPH_H
