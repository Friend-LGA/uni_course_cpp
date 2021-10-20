#include "graph.hpp"

using Vertex = Graph::Vertex;
using Edge = Graph::Edge;

Vertex::Vertex(const std::string& _data) : data(_data) {}

Edge::Edge(const std::string& _data) : data(_data) {}

Graph::Graph(int max_depth, int initial_num_vertices) : max_depth_(max_depth) {
  for (int i = 0; i < initial_num_vertices; i++) {
    add_vertex();
  }
}

Vertex Graph::add_vertex() {
  auto new_vertex = Vertex();
  vertices_.push_back(new_vertex);
  return new_vertex;
}
