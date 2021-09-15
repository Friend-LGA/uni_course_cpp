// Prefer the quoted form of #include for files relative to the including file
// and the angle bracket form everywhere else.
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#sf12-prefer-the-quoted-form-of-include-for-files-relative-to-the-including-file-and-the-angle-bracket-form-everywhere-else
#include <string>
#include <vector>

class Graph {
 public:
  struct Vertex {
    std::string id;
    std::string data;

    explicit Vertex(const std::string& data = "");
  };

  struct Edge {
    std::string id;
    std::string data;

    explicit Edge(const std::string& data = "");
  };

  Graph(int max_depth, int initial_num_vertices = 0);

  Vertex add_vertex();

 private:
  int max_depth_ = 0;
  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;
};
