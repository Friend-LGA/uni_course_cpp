// Preprocessor flat, which tells preprocessor to go over it only once.
// https://en.wikipedia.org/wiki/Pragma_once
#pragma once

// Include Guard. Preprocessor makes sure that the code included only once.
// Naming convention: FILE_NAME_EXTENSION
// https://en.wikipedia.org/wiki/Include_guard
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph {
 public:
  struct Vertex {
    int id;

    explicit Vertex(int id);
  };

  struct Edge {
    int id;
    int from_vertex_id;
    int to_vertex_id;

    explicit Edge(int id, int from_vertex_id, int to_vertex_id);
  };

  const Vertex& add_vertex();
  const Edge& add_edge(int from_vertex_id, int to_vertex_id);

 private:
  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;

  int vertex_id_counter_ = 0;
  int edge_id_counter_ = 0;

  int get_new_vertex_id() { return vertex_id_counter_++; }
  int get_new_edge_id() { return edge_id_counter_++; }
};

#endif  // GRAPH_HPP
