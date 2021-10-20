// https://en.wikipedia.org/wiki/Include_guard
// https://en.wikipedia.org/wiki/Pragma_once
// https://docs.microsoft.com/en-us/cpp/preprocessor/once

// Will be included only once.
#include "graph.hpp"

int main() {
  const auto graph = Graph();
  return 0;
}
