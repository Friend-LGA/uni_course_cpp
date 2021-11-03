#include <memory>
#include <vector>

struct Vertex;
struct Edge;

class Graph {
 public:
  Graph();

  void add_vertex(const Vertex& vertex);
  void add_edge(const Edge& edge);

 private:
  std::vector<std::unique_ptr<Vertex>> vertices_;
  std::vector<std::unique_ptr<Edge>> edges_;
};
