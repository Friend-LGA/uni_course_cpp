#include <string>

struct Edge;

struct Vertex {
  std::string id;
  std::vector<Edge*> edges;
};
