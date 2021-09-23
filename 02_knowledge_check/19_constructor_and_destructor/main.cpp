// https://en.cppreference.com/w/cpp/language/default_constructor
// https://en.cppreference.com/w/cpp/language/destructor
// https://docs.microsoft.com/en-us/cpp/cpp/constructors-cpp
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c47-define-and-initialize-member-variables-in-the-order-of-member-declaration
// https://docs.microsoft.com/en-us/cpp/cpp/delegating-constructors
// https://docs.microsoft.com/en-us/cpp/cpp/destructors-cpp

#include <iostream>
#include <string>

class Amazing {
 public:
  int* pointer;

  // Constructor, initialises all resources.
  Amazing() : pointer(new int(15)) {
    std::cout << "Amazing constructor is executed" << std::endl;
    // For example can also:
    // - allocate heap memory
    // - open socket
    // - open file
    // - lock mutex
    // - connect database
    // - etc...
  }

  // Destructor, deletes all resources.
  ~Amazing() {
    std::cout << "Amazing destructor is executed" << std::endl;
    // Should mirror constructor, for example:
    // - delete heap memory
    // - close socket
    // - close file
    // - unlock mutex
    // - disconnect database
    // - etc...
    delete pointer;
  }
};

// Default constructor and/or destructor, since C++11.
// https://stackoverflow.com/questions/20828907/the-new-syntax-default-in-c11
class DefaultExample {
 public:
  DefaultExample() = default;
  ~DefaultExample() = default;
};

// Empty constructor and/or destructor.
// Makes the class not an aggregate and also not trivial. Just use `default`.
// https://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special
class EmptyExample {
 public:
  EmptyExample() {}
  ~EmptyExample() {}
};

// Deleted constructor and/or destructor
class DeleteExample {
 public:
  // If you don't want default constructor.
  DeleteExample() = delete;

  DeleteExample(std::string message) {
    // validate message
  }

  // It is possible, but you won't be able to delete the instance.
  ~DeleteExample() = delete;
};

// Order of initialization should be the same as order of declaration.
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c47-define-and-initialize-member-variables-in-the-order-of-member-declaration
class OrderExample {
 public:
  int a;
  int b;
  std::string c;
  std::string d;

  // GOOD
  OrderExample(int _a, int _b, std::string _c, std::string _d)
      : a(_a), b(_b), c(_c), d(_d) {}

  // BAD
  // OrderClass(int _a, int _b, std::string _c, std::string _d)
  //     : d(_d), a(_a), c(_c), b(_b) {}
};

// Use `explicit` for constructors with single argument.
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c46-by-default-declare-single-argument-constructors-explicit
class ExplicitExample {
 public:
  int a;
  int b;

  // GOOD
  explicit ExplicitExample(int _a) : a(_a), b(0) {}

  // BAD, implicit conversion `ExplicitExample var = 1;`
  // ExplicitExample(int _a) : a(_a) {}

  // GOOD
  ExplicitExample(int _a, int _b) : a(_a), b(_b) {}

  // BAD, redundant
  // explicit ExplicitExample(int _a, int _b) : a(_a), b(_b) {}
};

// Construction Chain
// Always use chaining instead of duplicating member initialization
// https://docs.microsoft.com/en-us/cpp/cpp/delegating-constructors
class ChainExample {
  struct Position {
    int x, y;
  } pos;

  struct Size {
    int width, height;
  } size;

  ChainExample(Position _pos, Size _size) : pos(_pos), size(_size) {}

  ChainExample(int x, int y, int width, int height)
      : ChainExample({.x = x, .y = y}, {.width = width, .height = height}) {}
};

int main() {
  auto a = Amazing();
  return 0;
}
