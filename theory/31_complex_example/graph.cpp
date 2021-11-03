#include "graph.hpp"

#include "cassert"

using Graph = uni::Graph;
using Vertex = uni::Graph::Vertex;
using VertexId = uni::Graph::VertexId;
using Edge = uni::Graph::Edge;
using EdgeId = uni::Graph::EdgeId;

namespace {

// Try to use private namespace functions instead of extending private interface
// of the object
void validate_vertex_pos(const std::vector<Vertex>& vertices, size_t pos) {
  assert(pos < vertices.size() && "Vertex position is out of range");
}

void validate_vertex_existance(const Graph& graph, const VertexId id) {
  assert(graph.find_vertex(id).has_value() &&
         "Vertex with provided id doesn't exist");
}

}  // namespace

namespace uni {

Vertex Graph::vertex_at(size_t pos) const {
  // Validate possible error
  validate_vertex_pos(vertices_, pos);
  return vertices_.at(pos);
}

Vertex Graph::operator[](size_t pos) const {
  validate_vertex_pos(vertices_, pos);
  return vertices_[pos];
}

std::optional<Vertex> Graph::find_vertex(const VertexId& id) const {
  // ... some complex logic ...
  return std::nullopt;
}

Vertex Graph::add_vertex() {
  // ... some complex logic ...
  return Vertex(0);
}

void Graph::remove_vertex(const VertexId& id) {
  // ... some complex logic ...
}

Edge Graph::add_edge(const VertexId& from_vertex_id,
                     const VertexId& to_vertex_id) {
  // Validate preconditions
  validate_vertex_existance(*this, from_vertex_id);
  validate_vertex_existance(*this, to_vertex_id);
  // ... some complex logic ...
  return Edge(0, 0, 0);
}

void Graph::remove_edge(const VertexId& from_vertex_id,
                        const VertexId& to_vertex_id) {
  validate_vertex_existance(*this, from_vertex_id);
  validate_vertex_existance(*this, to_vertex_id);
  // ... some complex logic ...
}

std::vector<Vertex> Graph::neighbours(const VertexId& id) const {
  validate_vertex_existance(*this, id);
  // ... some complex logic ...
  return {};
}

std::vector<Edge> Graph::edges(const VertexId& id) const {
  validate_vertex_existance(*this, id);
  // ... some complex logic ...
  return {};
}

bool Graph::has_vertex(const VertexId& id) const {
  // ... some complex logic ...
  return true;
}

bool Graph::is_connected(const VertexId& from_vertex_id,
                         const VertexId& to_vertex_id) const {
  validate_vertex_existance(*this, from_vertex_id);
  validate_vertex_existance(*this, to_vertex_id);
  // ... some complex logic ...
  return false;
}

}  // namespace uni
