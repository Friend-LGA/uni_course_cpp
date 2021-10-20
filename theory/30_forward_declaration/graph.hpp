#include <memory>
#include <vector>

struct Vertex;
struct Edge;

class Graph {
 public:
  Graph();

  void add_vertex(const Vertex& vertex);

 private:
  std::vector<std::unique_ptr<Vertex>> vertices_;
  std::vector<std::unique_ptr<Edge>> edges_;
};
