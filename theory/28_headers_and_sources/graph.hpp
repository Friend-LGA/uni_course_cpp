// Prefer the quoted form of #include for files relative to the including file
// and the angle bracket form everywhere else.
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#sf12-prefer-the-quoted-form-of-include-for-files-relative-to-the-including-file-and-the-angle-bracket-form-everywhere-else
#include <string>
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
