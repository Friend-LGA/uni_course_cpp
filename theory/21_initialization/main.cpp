// https://en.cppreference.com/w/cpp/language/initialization
// https://en.cppreference.com/w/cpp/language/value_initialization
// https://en.cppreference.com/w/cpp/language/direct_initialization
// https://en.cppreference.com/w/cpp/language/copy_initialization
// https://en.cppreference.com/w/cpp/language/list_initialization
// https://en.cppreference.com/w/cpp/language/aggregate_initialization
// https://en.cppreference.com/w/cpp/language/reference_initialization
// https://en.cppreference.com/w/cpp/language/default_initialization
// https://en.cppreference.com/w/cpp/language/zero_initialization
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-lambda-init

#include <iostream>
#include <string>
#include <vector>

struct CustomStruct {
  int x;
  int y;
};

struct CustomStructWithDefaults {
  int x = 0;
  int y = 0;
};

struct CustomStructWithConstructor {
  int x = 0;
  int y = 0;

  CustomStructWithConstructor() = default;
  CustomStructWithConstructor(int _x, int _y) : x(_x), y(_y) {}
};

class CustomClass {
 public:
  int x;
  int y;
};

class CustomClassWithDefaults {
 public:
  int x = 0;
  int y = 0;

  CustomClassWithDefaults() = default;
  CustomClassWithDefaults(int _x, int _y) : x(_x), y(_y) {}
};

int main() {
  ///////////////////////
  // FUNDAMENTAL TYPES //
  ///////////////////////

  // BAD: uninitialized, some trash
  int i0;

  // Default initialization to 0
  int i1 = {};
  int i2{};
  auto i3 = int();
  auto i4 = int{};

  // Initialization to a value
  int i5 = 5;
  int i6(5);
  int i7{5};
  auto i8 = int(5);
  auto i9 = int{5};

  std::cout << "i0 = " << i0 << std::endl
            << "i1 = " << i1 << std::endl
            << "i2 = " << i2 << std::endl
            << "i3 = " << i3 << std::endl
            << "i4 = " << i4 << std::endl
            << "i5 = " << i5 << std::endl
            << "i6 = " << i6 << std::endl
            << "i7 = " << i7 << std::endl
            << "i8 = " << i8 << std::endl
            << "i9 = " << i9 << std::endl
            << std::endl;

  //////////////////////
  // STANDARD LIBRARY //
  //////////////////////

  // Default initialization to empty array
  std::vector<int> vec0;
  std::vector<int> vec1 = {};
  std::vector<int> vec2{};
  auto vec3 = std::vector<int>();
  auto vec4 = std::vector<int>{};

  // Initialization to a value
  std::vector vec5 = {0, 1, 2};
  std::vector vec6({0, 1, 2});
  std::vector vec7{0, 1, 2};
  auto vec8 = std::vector({0, 1, 2});
  auto vec9 = std::vector{0, 1, 2};

  // Default initialization to empty string
  std::string str0;
  std::string str1 = {};
  std::string str2{};
  auto str3 = std::string();
  auto str4 = std::string{};

  // Initialization to a value
  std::string str5 = "abc";
  std::string str6("abc");
  std::string str7{"abc"};
  auto str8 = std::string("abc");
  auto str9 = std::string{"abc"};

  std::cout << "str0 = " << str0 << std::endl
            << "str1 = " << str1 << std::endl
            << "str2 = " << str2 << std::endl
            << "str3 = " << str3 << std::endl
            << "str4 = " << str4 << std::endl
            << "str5 = " << str5 << std::endl
            << "str6 = " << str6 << std::endl
            << "str7 = " << str7 << std::endl
            << "str8 = " << str8 << std::endl
            << "str9 = " << str9 << std::endl
            << std::endl;

  ///////////////////
  // CUSTOM STRUCT //
  ///////////////////

  // BAD: uninitialized, some trash
  CustomStruct svar0;

  // Still BAD: default initialization, but invisible
  CustomStructWithDefaults svar1;

  // GOOD: default initialization, visible
  CustomStructWithDefaults svar2 = {};

  // BAD: unnamed initialization
  CustomStructWithDefaults svar3 = {8, 16};

  // GOOD
  CustomStructWithDefaults svar4 = {.x = 8, .y = 16};

  // GOOD: default constructor
  auto svar5 = CustomStructWithConstructor();

  // GOOD: custom constructor
  auto svar6 = CustomStructWithConstructor(8, 16);

  // ERROR: you have to use provided constructor
  // CustomStructWithConstructor svar6 = {.x = 8, .y = 16};

  std::cout
      << "svar0 = { x: " << svar0.x << ", y: " << svar0.y << " }" << std::endl
      << "svar1 = { x: " << svar1.x << ", y: " << svar1.y << " }" << std::endl
      << "svar2 = { x: " << svar2.x << ", y: " << svar2.y << " }" << std::endl
      << "svar3 = { x: " << svar3.x << ", y: " << svar3.y << " }" << std::endl
      << "svar4 = { x: " << svar4.x << ", y: " << svar4.y << " }" << std::endl
      << "svar5 = { x: " << svar5.x << ", y: " << svar5.y << " }" << std::endl
      << "svar6 = { x: " << svar6.x << ", y: " << svar6.y << " }" << std::endl
      << std::endl;

  ///////////////////
  // CUSTOM CLASS //
  ///////////////////

  // BAD: uninitialized, some trash
  CustomClass cvar0;

  // Still BAD: default initialization, but invisible
  CustomClassWithDefaults cvar1;

  // GOOD: default initialization, visible
  auto cvar2 = CustomClassWithDefaults();

  // GOOD: custom constructor
  auto cvar3 = CustomClassWithDefaults(8, 16);

  // BAD: don't use struct style initialization for class
  CustomClass cvar4 = {8, 16};

  // clang-format off
  std::cout
      << "cvar0 = { x: " << cvar0.x << ", y: " << cvar0.y << " }" << std::endl
      << "cvar1 = { x: " << cvar1.x << ", y: " << cvar1.y << " }" << std::endl
      << "cvar2 = { x: " << cvar2.x << ", y: " << cvar2.y << " }" << std::endl
      << "cvar3 = { x: " << cvar3.x << ", y: " << cvar3.y << " }" << std::endl
      << "cvar4 = { x: " << cvar4.x << ", y: " << cvar4.y << " }" << std::endl
      << std::endl;
  // clang-format on

  /////////////////////////////
  // Uninitialized Variables //
  /////////////////////////////

  // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-lambda-init

  // BAD: can't be const, complex initialization logic, error-prone.
  int bad_result;
  int some_condition = 2;
  if (some_condition == 0) {
    bad_result = 1;
  } else if (some_condition == 1) {
    bad_result = 2;
  } else {
    bad_result = 3;
  }
  // some more logic ...

  // GOOD: can be const, complex initialization logic is happening inside it's
  // own scope.
  const int good_result = []() -> int {
    int some_condition = 2;
    if (some_condition == 0) {
      return 1;
    } else if (some_condition == 1) {
      return 2;
    } else {
      return 3;
    }
    // some more logic ...
  }();

  return 0;
}
