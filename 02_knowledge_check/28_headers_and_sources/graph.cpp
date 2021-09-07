#include "graph.hpp"

#include "cassert"

namespace {

void validate_vertex_pos(size_t pos, const uni::Graph& graph) {
  assert(pos < graph.size() && "Vertex position is out of range");
}

}  // namespace

namespace uni {

using Vertex = Graph::Vertex;
using Edge = Graph::Edge;
using ConnectionStatus = Graph::ConnectionStatus;
using DisconnectionStatus = Graph::DisconnectionStatus;

Vertex Graph::vertex_at(size_t pos) const {
  validate_vertex_pos(pos, *this);
  auto vertex = vertices_.at(pos).get();
  return {.data = vertex->data, .pos = pos};
}

Vertex Graph::operator[](size_t pos) const {
  validate_vertex_pos(pos, *this);
  auto vertex = vertices_[pos].get();
  return {.data = vertex->data, .pos = pos};
}

Vertex Graph::add_vertex(const VertexData& data) {
  auto vertex = Vertex();
  // ... some complex logic ...
  return vertex;
}

void Graph::remove_vertex(size_t pos) {
  validate_vertex_pos(pos, *this);
  auto edges = edges_from(pos);
  for (auto edge : edges) {
    remove_edge(edge.from_vertex_pos, edge.to_vertex_pos);
  }
  vertices_.erase(vertices_.begin() + pos);
}

std::tuple<ConnectionStatus, std::optional<Edge>> Graph::add_edge(size_t from_pos, size_t to_pos,
                                                                  const EdgeData& data) {
  validate_vertex_pos(from_pos, *this);
  validate_vertex_pos(to_pos, *this);
  if (is_connected(from_pos, to_pos)) {
    return std::make_tuple(ConnectionStatus::AlreadyConnected, std::nullopt);
  }
  auto edge = Edge();
  // ... some complex logic ...
  return std::make_tuple(ConnectionStatus::AlreadyConnected, edge);
}

DisconnectionStatus Graph::remove_edge(size_t from_pos, size_t to_pos) {
  if (!is_connected(from_pos, to_pos)) {
    return DisconnectionStatus::EdgeDoesNotExist;
  }
  // ... some complex logic ...
  return DisconnectionStatus::Ok;
}

std::vector<Vertex> Graph::neighbours(size_t pos) const {
  validate_vertex_pos(pos, *this);
  // ... some complex logic ...
  return {};
}

std::vector<Edge> Graph::edges_from(size_t pos) const {
  validate_vertex_pos(pos, *this);
  // ... some complex logic ...
  return {};
}

bool Graph::is_connected(size_t from_pos, size_t to_pos) const {
  validate_vertex_pos(from_pos, *this);
  validate_vertex_pos(to_pos, *this);
  // ... some complex logic ...
  return false;
}

}  // namespace uni
