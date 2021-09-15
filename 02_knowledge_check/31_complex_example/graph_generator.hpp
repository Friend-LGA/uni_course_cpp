#pragma once

namespace uni {

class Graph;

class GraphGenerator {
 public:
  struct Options {
    int depth = 0;
  };

  GraphGenerator(const Options& options) : options_(options) {}

  Graph generate() const;

 private:
  Options options_;
};

}  // namespace uni
