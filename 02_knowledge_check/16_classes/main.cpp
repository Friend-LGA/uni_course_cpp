// https://en.cppreference.com/w/cpp/language/class
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c-classes-and-class-hierarchies

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Use `class` for objects with complex logic with private members and mutable functions,
// otherwise use `struct` for simple data containers.

class ClassExample {
 public:
  int pub_var1 = 0;
  std::string pub_var2 = "";

  void public_func() const { return; }
  void mutable_logic() { priv_var1_++; }

 private:
  int priv_var1_ = 0;
  std::string priv_var2_ = "";

  void private_func() { return; }
};

// Nested Classes and Structs
// https://en.cppreference.com/w/cpp/language/nested_types
class NestingExample {
 public:
  // NestingExample::SomeClass5
  class SomeClass5 {};

  // NestingExample::Position
  // Only declaration
  struct Position {
    int x = 0;
    int y = 0;
  };

  Position pos = {};

  // NestingExample::Position
  // Member of a class, inline declaration
  struct Size {
    int width = 0;
    int height = 0;
  } size;
};

int main() { return 0; }
