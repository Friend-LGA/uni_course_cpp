#include "graph.hpp"

#include "edge.hpp"
#include "vertex.hpp"

void Graph::add_vertex(const Vertex& vertex) {
  vertices_.emplace_back(vertex);
}

void Graph::add_edge(const Edge& edge) {
  edges_.emplace_back(edge);
}
