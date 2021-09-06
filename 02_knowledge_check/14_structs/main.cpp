// https://en.cppreference.com/w/c/language/struct
//
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c-classes-and-class-hierarchies

#include <iostream>

// Use `struct` for simple data containers.
// If it has some private members and not inlined functions
// better use `class` instead.

struct Position {
  // `public` by default.
  int x = 0;
  int y = 0;

  // It is not necessary to have constructor, but it is possible if you need one.
  // Don't put default values here, better use default member assignment as above.
  // Position(int _x, int _y) : x(_x), y(_y) {}
};

struct Size {
  int width = 0;
  int height = 0;
};

struct Rectangle {
  Position pos = {};
  Size size = {};

  Position center() const { return {.x = pos.x + size.width / 2, .y = pos.y + size.height / 2}; }
};

int main() {
  // It already has default member values.
  Rectangle rect1;
  std::cout << "Rect1 pos == {" << rect1.pos.x << ", " << rect1.pos.y << "}" << std::endl;
  std::cout << "Rect1 size == {" << rect1.size.width << ", " << rect1.size.height << "}" << std::endl;
  std::cout << "Rect1 center == {" << rect1.center().x << ", " << rect1.center().y << "}" << std::endl;

  // Always use constructor with named properties.
  // Bad: Rectangle rect2 = {{}, {10, 10}};
  Rectangle rect2 = {.pos = {.x = 8, .y = 16}, .size = {.width = 10, .height = 10}};  // Good
  std::cout << "Rect2 pos == {" << rect2.pos.x << ", " << rect2.pos.y << "}" << std::endl;
  std::cout << "Rect2 size == {" << rect2.size.width << ", " << rect2.size.height << "}" << std::endl;
  std::cout << "Rect2 center == {" << rect2.center().x << ", " << rect2.center().y << "}" << std::endl;
}
