// https://en.cppreference.com/w/cpp/language/class
//
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c-classes-and-class-hierarchies
//
// https://en.cppreference.com/w/cpp/language/default_constructor
// https://en.cppreference.com/w/cpp/language/copy_constructor
// https://en.cppreference.com/w/cpp/language/move_constructor
// https://en.cppreference.com/w/cpp/language/copy_assignment
// https://en.cppreference.com/w/cpp/language/move_assignment
// https://en.cppreference.com/w/cpp/language/destructor

#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main() { return 0; }

class SomeClass1 {
 public:
  // Empty constructor.
  // SomeClass1() {}

  // Default constructor, since C++11.
  // https://stackoverflow.com/questions/20828907/the-new-syntax-default-in-c11
  // SomeClass1() = default;

  // SomeClass1(int in1, int in2, std::string in3, std::string in4) {
  //   pub_var1 = in1;
  //   pub_var2 = in3;
  //   priv_var1_ = in2;
  //   priv_var2_ = in4;
  // }

  // Order of initialization should be the same as order of declaration.
  // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c47-define-and-initialize-member-variables-in-the-order-of-member-declaration
  // SomeClass1(int in1, int in2, std::string in3, std::string in4)
  //     : pub_var1(in1), pub_var2(in3), priv_var1_(in2), priv_var2_(in4) {}

  // Use `explicit` for constructors with single argument.
  // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c46-by-default-declare-single-argument-constructors-explicit
  // explicit SomeClass1(int in1) : pub_var1(in1), pub_var2(""), priv_var1_(0), priv_var2_("") {}

  // Construction Chain
  // SomeClass1() : SomeClass1(0) {}
  // explicit SomeClass1(int in1) : SomeClass1(in1, 0) {}
  // SomeClass1(int in1, int in2) : SomeClass1(in1, in2, "") {}
  // SomeClass1(int in1, int in2, std::string in3) : SomeClass1(in1, in2, in3, "") {}
  // SomeClass1(int in1, int in2, std::string in3, std::string in4)
  //     : pub_var1(in1), pub_var2(in3), priv_var1_(in2), priv_var2_(in4) {}

  // Better version, this will cover all variants above.
  // But don't duplicate default values with members list.
  // SomeClass1(int in1 = 0, int in2 = 0, std::string in3 = "", std::string in4 = "")
  //     : pub_var1(in1), pub_var2(in3), priv_var1_(in2), priv_var2_(in4) {}

  int pub_var1 = 0;
  std::string pub_var2 = "";

  void some_public_logic() { return; }

 private:
  int priv_var1_ = 0;
  std::string priv_var2_ = "";

  void some_private_logic() { return; }
};

class SomeClass2 {
 public:
  // Constructor
  SomeClass2() = default;

  // Destructor
  ~SomeClass2() = default;

  // Copy Constructor
  SomeClass2(const SomeClass2& other) = default;

  // Copy Assignment
  SomeClass2& operator=(const SomeClass2& other) = default;

  // Move Constructor
  SomeClass2(SomeClass2&& other) = default;

  // Move Assignment
  SomeClass2& operator=(SomeClass2&& other) = default;

  // If you don't want some of these operations.
  // For example `unique_ptr` can't be copied.
  // SomeClass2() = delete;
  // ~SomeClass2() = delete;
  // SomeClass2(const SomeClass2& other) = delete;
  // SomeClass2& operator=(const SomeClass2& other) = delete;
  // SomeClass2(SomeClass2&& other) = delete;
  // SomeClass2& operator=(SomeClass2&& other) = delete;

  // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#cdefop-default-operations
};

// Example of manually implementing constructor, destructor, copy and move.
class SomeClass3 {
 public:
  int value;
  int* pointer;
  std::unique_ptr<int> smart_pointer;

  SomeClass3() : value(5), pointer(new int(328)), smart_pointer(std::make_unique<int>(512)) {}

  ~SomeClass3() {
    // Raw pointer needs to be manually deleted.
    delete pointer;
  }

  // Do you need shallow or deep copy?
  SomeClass3(const SomeClass3& other)
      : value(other.value), pointer(other.pointer), smart_pointer(std::make_unique<int>(*other.smart_pointer.get())) {}

  SomeClass3& operator=(const SomeClass3& other) {
    value = other.value;
    pointer = other.pointer;
    smart_pointer = std::make_unique<int>(*other.smart_pointer.get());
    return *this;
  }

  SomeClass3(SomeClass3&& other)
      : value(std::move(other.value)),
        pointer(std::move(other.pointer)),
        smart_pointer(std::move(other.smart_pointer)) {}

  SomeClass3& operator=(SomeClass3&& other) {
    value = std::move(other.value);
    pointer = std::move(other.pointer);
    smart_pointer = std::move(other.smart_pointer);
    return *this;
  }
};

// Nested Classes and Structs
// https://en.cppreference.com/w/cpp/language/nested_types
class SomeClass4 {
 public:
  // SomeClass4::SomeClass5
  class SomeClass5 {};

  // SomeClass4::SomeStruct
  struct SomeStruct {};
};
