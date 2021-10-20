#include <string>

struct Vertex;

struct Edge {
  std::string id;
  Vertex* from_vertex;
  Vertex* to_vertex;
};
