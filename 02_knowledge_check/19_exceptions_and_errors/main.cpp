// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#e-error-handling
//
// https://en.cppreference.com/w/cpp/error
//
// https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <tuple>

enum class Status { Ok, InvalidArgument };

// Shouldn't throw exceptions.
// https://en.cppreference.com/w/cpp/language/noexcept_spec
static int sum(int a, int b) noexcept { return a + b; }

// Compiles, but at runtime this calls std::terminate
static int sum_positive1(int a, int b) noexcept {
  if (a < 0 || b < 0) {
    throw std::invalid_argument("received negative value");
  }
  return a + b;
}

static int sum_positive2(int a, int b) {
  if (a < 0 || b < 0) {
    throw std::invalid_argument("received negative value");
  }
  return a + b;
}

// Exceptions are not always easy to handle and they have processing overhead.
// Without exceptions you can return obvious self-describing error code.
// Don't use global enum, put it inside your class or namespace.
static std::tuple<Status, int> sum_positive3(int a, int b) {
  if (a < 0 || b < 0) {
    return {Status::InvalidArgument, 0};
  }
  return {Status::Ok, a + b};
}

// If by design your function can't have invalid argument, which means,
// that if you have invalid argument, then it is a bug, which should be addressed.
// Use `assert` only for debug builds.
// https://en.cppreference.com/w/cpp/error/assert
// https://docs.microsoft.com/en-us/visualstudio/debugger/c-cpp-assertions
static int sum_positive4(int a, int b) {
  assert(a >= 0 && b >= 0 && "Invalid Argument");
  return a + b;
}

int main() {
  try {
    sum_positive2(-1, 5);
  } catch (const std::invalid_argument& exception) {
    std::cout << "Exception: " << exception.what() << std::endl;
    // handle exception...
  }

  auto [status, result] = sum_positive3(-1, 5);
  if (status == Status::InvalidArgument) {
    std::cout << "Error: Status::InvalidArgument" << std::endl;
    // handle error...
  }

  int res = sum_positive4(-1, 5);

  return 0;
}

// Return errors when you expect you function to fail.
// Throw exception when failing is unexpected behaviour.
