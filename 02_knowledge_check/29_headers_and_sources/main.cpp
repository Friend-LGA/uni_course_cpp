// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-source
// https://docs.microsoft.com/en-us/cpp/cpp/header-files-cpp
// https://en.cppreference.com/w/cpp/preprocessor/include
// https://en.wikipedia.org/wiki/Pragma_once
// https://docs.microsoft.com/en-us/cpp/preprocessor/once
// https://en.wikipedia.org/wiki/Include_guard

#include "graph.hpp"
#include "graph_traverser.hpp"

int main() {
  auto graph = uni::Graph();
  auto graph_traverser = uni::GraphTraverser(graph);

  return 0;
}
