#include "graph.hpp"

#include "edge.hpp"
#include "vertex.hpp"

Graph::Graph() : vertices_(), edges_() {}

void Graph::add_vertex(const Vertex& vertex) { vertices_.push_back(std::make_unique<Vertex>(vertex)); }
