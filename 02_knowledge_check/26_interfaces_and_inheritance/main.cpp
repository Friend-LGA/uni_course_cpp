// https://en.cppreference.com/w/cpp/language/derived_class
// https://en.cppreference.com/w/cpp/language/abstract_class
// https://docs.microsoft.com/en-us/cpp/cpp/abstract-classes-cpp
// https://en.cppreference.com/w/cpp/language/override
// https://en.cppreference.com/w/cpp/language/virtual
// https://docs.microsoft.com/en-us/cpp/cpp/virtual-functions
// https://en.wikipedia.org/wiki/Virtual_function
// https://en.cppreference.com/w/cpp/language/final
// https://docs.microsoft.com/en-us/cpp/cpp/multiple-base-classes
// https://en.wikipedia.org/wiki/Virtual_inheritance

#include <array>
#include <iostream>

struct Position {
  int x = 0;
  int y = 0;
};

struct Size {
  int width = 0;
  int height = 0;
};

// Abstract class, contains only virtual functions
class Shape {
 public:
  virtual void fill() = 0;
  virtual void stroke() = 0;

  virtual ~Shape() = default;
};

class Rectangle : public Shape {
 public:
  Position pos = {};
  Size size = {};

  void fill() override { std::cout << "Rectangle::fill()" << std::endl; }

  void stroke() override { std::cout << "Rectangle::stroke()" << std::endl; }
};

class Circle : public Shape {
 public:
  Position center = {};
  int radius = 0;

  void fill() override { std::cout << "Circle::fill()" << std::endl; }

  void stroke() override { std::cout << "Circle::stroke()" << std::endl; }
};

class Smile : public Circle {
 public:
  Position left_eye_pos = {};
  Size left_eye_size = {};
  Position right_eye_pos = {};
  Size right_eye_size = {};

  void fill() override {
    Circle::fill();
    std::cout << "Smile::fill()" << std::endl;
  }

  void stroke() override {
    Circle::stroke();
    std::cout << "Smile::stroke()" << std::endl;
  }
};

//////////////////////////
// Multiple Inheritance //
//////////////////////////

// https://docs.microsoft.com/en-us/cpp/cpp/multiple-base-classes
// https://en.wikipedia.org/wiki/Virtual_inheritance

namespace multiple_inheritance_example {

class A {
 public:
  virtual void a_function() = 0;
  virtual ~A() = default;
};

class B {
 public:
  virtual void b_function() = 0;
  virtual ~B() = default;
};

class C : public A, public B {
 public:
  void a_function() {}
  void b_function() {}
  void c_function() {}
};

}  // namespace multiple_inheritance_example

////////////////
// VISIBILITY //
////////////////

namespace visibility_example {

class A {
 public:  // Visible for everyone
  void a_public_function() {}
  virtual ~A() = default;

 protected:  // Visible for A and derivatives
  void a_protected_function() {}

 private:  // Visible only for A
  void a_private_function() {}
};

// The same methods visibility in A and B
class B : public A {
  void d_function() {
    a_public_function();
    a_protected_function();
    // a_private_function();  // ERROR: not accessible
  }
};

// All `public` methods from A are now `protected` in C
class C : protected A {
  void d_function() {
    a_public_function();
    a_protected_function();
    // a_private_function();  // ERROR: not accessible
  }
};

// All `public` and `protected` methods from A are now `private` in D
class D : private A {
  void d_function() {
    a_public_function();
    a_protected_function();
    // a_private_function();  // ERROR: not accessible
  }
};

}  // namespace visibility_example

//////////////
// OVERRIDE //
//////////////

// https://en.cppreference.com/w/cpp/language/override

namespace override_example {

class A {
 public:
  virtual void a_function(int var) = 0;
  virtual ~A() = default;
};

class B : public A {};  // Still abstract class as `a_function` is virtual

class C : public A {
 public:
  void a_function(int var) {}  // BAD: intention is unclear, error-prone
};

class D : public A {
 public:
  void a_function(int var) override {}  // GOOD
};

class E : public A {
 public:
  // void a_function(float var) override {}  // ERROR: hides virtual member function
  // int a_function(int var) override {}  // ERROR: has a different return type
};

}  // namespace override_example

/////////////
// VIRTUAL //
/////////////

// https://en.cppreference.com/w/cpp/language/virtual
// https://docs.microsoft.com/en-us/cpp/cpp/virtual-functions
// https://en.wikipedia.org/wiki/Virtual_function

namespace virtual_example {

class A {
 public:
  // Pure Virtual Function
  // Have to be overriden in the derived class
  // Will call the most derived implementation
  virtual void pure_virtual_func() = 0;

  // Virtual Function
  // Don't have to be overriden
  // Will call the most derived implementation
  virtual void virtual_func() { std::cout << "A::virtual_func()" << std::endl; }

  // Normal Function
  // Can't be overriden
  // Will call A implementation of `func()`
  void func() { std::cout << "A::func()" << std::endl; }

  virtual ~A() = default;
};

class B : public A {
 public:
  void pure_virtual_func() override {
    // A::pure_virtual_func(); // ERROR: is not defined
    std::cout << "B::pure_virtual_func()" << std::endl;
  }

  void virtual_func() override {
    A::virtual_func();
    std::cout << "B::virtual_func()" << std::endl;
  }

  void func() {
    A::func();
    std::cout << "B::func()" << std::endl;
  }
};

class C : public B {
 public:
  void pure_virtual_func() override {
    B::pure_virtual_func();
    std::cout << "C::pure_virtual_func()" << std::endl;
  }

  void virtual_func() override {
    B::virtual_func();
    std::cout << "C::virtual_func()" << std::endl;
  }

  void func() {
    B::func();
    std::cout << "C::func()" << std::endl;
  }
};

}  // namespace virtual_example

///////////
// FINAL //
///////////

// https://en.cppreference.com/w/cpp/language/final

namespace final_example {

class A {
 public:
  virtual void func() {}
};

class B : public A {
 public:
  void func() final override {}
};

class C final : public B {
 public:
  // void func() override {}  // ERROR: final func cannot be overriden
  void c_func() {}
};

// class D : public C {};  // final class cannot be inherited

}  // namespace final_example

//////////
// MAIN //
//////////

int main() {
  auto smile = Smile();
  smile.fill();

  {  // visibility_example
    using namespace visibility_example;

    auto b = B();
    b.a_public_function();
    // b.a_protected_function();  // ERROR: not accessible
    // b.a_private_function();    // ERROR: not accessible

    auto c = C();
    // c.a_public_function();     // ERROR: not accessible
    // c.a_protected_function();  // ERROR: not accessible
    // c.a_private_function();    // ERROR: not accessible

    auto d = D();
    // d.a_public_function();     // ERROR: not accessible
    // d.a_protected_function();  // ERROR: not accessible
    // d.a_private_function();    // ERROR: not accessible
  }

  {  // virtual_example
    using namespace virtual_example;

    // A* a = new A(); // ERROR: abstract class
    A* b = new B();
    A* c = new C();

    std::cout << std::endl;
    std::cout << "b->pure_virtual_func()" << std::endl;
    b->pure_virtual_func();

    std::cout << std::endl;
    std::cout << "b->virtual_func()" << std::endl;
    b->virtual_func();

    std::cout << std::endl;
    std::cout << "b->func()" << std::endl;
    b->func();

    std::cout << std::endl;
    std::cout << "c->pure_virtual_func()" << std::endl;
    c->pure_virtual_func();

    std::cout << std::endl;
    std::cout << "c->virtual_func()" << std::endl;
    c->virtual_func();

    std::cout << std::endl;
    std::cout << "c->func()" << std::endl;
    c->func();

    delete b;
    delete c;
  }

  return 0;
}
