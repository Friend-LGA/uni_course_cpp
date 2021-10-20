// https://en.cppreference.com/w/cpp/language/function
// https://en.cppreference.com/w/cpp/utility/functional/function
//
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f-functions

#include <cassert>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

int main() {
  return 0;
}

// Arguments passed by value (copy).
void func(int a) {}

// Overloading.
void func(float a) {}

// Default arguments.
void func(int a, int b = 0) {}

// in-out argument by reference, data can't be null.
void func(std::string& a) {
  a.append("something amazing!");
}

// For heavy data passing use const reference, which can't be changed.
void func(const std::string& a) {}

// int is not heavy to copy, so pass it just by value, don't use const
// reference.
void func(const int& a) {}  // Bad

// in-out argument by pointer, data can be null.
void func(std::string* a) {}

// `unique_ptr` usually used to transfer ownership of an object.
// To pass `unique_ptr` you will actually need to use `std::move()` semantics,
// because `unique_ptr` can only have 1 owner.
void func(std::unique_ptr<int> a) {}

// Pass `shared_ptr` only if your intent is to own the object,
// in other words if you will store it somewhere.
// Otherwise if you just going to have some local calculations with it
// use simple raw pointer.
// `shared_ptr` will be copied here, internal counter will be increased by 1.
void func(std::shared_ptr<int> a) {}

// Don't usually do such a thing. If you don't want to use `shared_ptr` logic,
// then use simple value, reference or raw pointer.
void func(const std::shared_ptr<int>& a) {}

// Pass rvalue reference if you want to implement move semantics.
void func(std::string&& a) {}

// Return result by value.
std::string func1(char a) {
  return "";
}

// Don't return const value, as function usually shouldn't decide how result is
// used outside
const std::string func2(char a) {
  return "";
}

// Return by reference to local object, can't be null.
// For example std::vector.at() returns reference.
// Consider the situation: `b` will be destroyed after execution of the
// function, then where will reference point to?
std::string& func3(char a) {
  static std::string b = "some string";
  return b;
}

// The same idea. But result can be null.
std::string* func4(char a) {
  static std::string b = "some string";
  return &b;
}

// If you need to return more then one object and they are unrelated to each
// other, then use `std::tuple`.
std::tuple<std::string, int> multipleReturn1() {
  std::string data = "some very useful data";
  int status = 1;  // ok!
  return {data, status};
}

// In case they are related, for example parameters of some entity like
// `name` and `age`, then use struct which represents this entity.
struct Person {
  std::string name;
  int age;
};

Person multipleReturn2() {
  std::string name = "Alisa";
  int age = 18;
  return {.name = name, .age = age};
}
