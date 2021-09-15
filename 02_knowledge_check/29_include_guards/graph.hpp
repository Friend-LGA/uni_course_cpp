// Preprocessor flat, which tells preprocessor to go over it only once.
// https://en.wikipedia.org/wiki/Pragma_once
#pragma once

// Include Guard. Preprocessor makes sure that the code included only once.
// Naming convention: FILE_NAME_EXTENSION
// https://en.wikipedia.org/wiki/Include_guard
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>

struct Vertex {
  std::string id;
};

struct Edge {
  std::string id;
};

class Graph {
 public:
  Graph() = default;

  void add_vertex(const Vertex& vertex);

 private:
  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;
};

#endif  // GRAPH_HPP
