// https://en.cppreference.com/w/c/language/struct
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c-classes-and-class-hierarchies

#include <iostream>

// Use `struct` for simple data containers.
// If it has some private members and complex mutable functions
// better use `class` instead.

struct Position {
  // `public` by default.
  int x = 0;
  int y = 0;
};

struct Size {
  int width = 0;
  int height = 0;
};

struct Rectangle {
  Position pos = {};
  Size size = {};

  // Convenient constructors
  Rectangle(Position _pos, Size _size) : pos(_pos), size(_size) {}

  // Construction Chain
  // Always use chaining instead of duplicating member initialization
  Rectangle(int x, int y, int width, int height) : Rectangle({.x = x, .y = y}, {.width = width, .height = height}) {}

  Position center() const { return {.x = pos.x + size.width / 2, .y = pos.y + size.height / 2}; }
};

int main() {
  Position pos = {.x = 8, .y = 16};
  Size size = {.width = 10, .height = 10};

  Rectangle rect1 = Rectangle(pos, size);
  Rectangle rect2 = Rectangle(8, 16, 10, 10);
  // Rectangle rect3 = {.pos = pos, .size = size}; // ERROR: You need to use constructor if you have one

  std::cout << "Rect pos == {" << rect1.pos.x << ", " << rect1.pos.y << "}" << std::endl
            << "Rect size == {" << rect1.size.width << ", " << rect1.size.height << "}" << std::endl
            << "Rect center == {" << rect1.center().x << ", " << rect1.center().y << "}" << std::endl;
}
