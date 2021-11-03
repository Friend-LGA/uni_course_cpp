#include "graph.hpp"

using Vertex = Graph::Vertex;
using Edge = Graph::Edge;

Vertex::Vertex(int _id) : id(_id) {}

Edge::Edge(int _id, int _from_vertex_id, int _to_vertex_id)
    : id(_id), from_vertex_id(_from_vertex_id), to_vertex_id(_to_vertex_id) {}

const Vertex& Graph::add_vertex() {
  const auto& new_vertex = vertices_.emplace_back(get_new_vertex_id());
  return new_vertex;
}

const Edge& Graph::add_edge(int from_vertex_id, int to_vertex_id) {
  const auto& new_edge =
      edges_.emplace_back(get_new_edge_id(), from_vertex_id, to_vertex_id);
  return new_edge;
}
