// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#e-error-handling
// https://en.cppreference.com/w/cpp/error
// https://en.cppreference.com/w/cpp/error/assert
// https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp
// https://docs.microsoft.com/en-us/visualstudio/debugger/c-cpp-assertions

#include <cassert>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <tuple>

enum class Status { Ok, InvalidArgument };

// Exception example
// Use exceptions to handle unexpected behaviour, which is not in your control,
// for example if you failed to open a file
void open_file(const std::string& filename) {
  std::filebuf fb;
  if (!fb.open(filename, std::ios::binary | std::ios::in)) {
    throw std::runtime_error("Open file for readind is failed");
  }
  // some logic ...
}

// ERROR, can't throw.
// `noexcept` means that function shouldn't throw exceptions.
// https://en.cppreference.com/w/cpp/language/noexcept_spec
// void open_file(const std::string& filename) noexcept {
//   std::filebuf fb;
//   if (!fb.open(filename, std::ios::binary|std::ios::in)) {
//     throw std::runtime_error("Open file for read failed");
//   }
//   // some logic ...
// }

// On the other hand, if failing is expected, then use well-defined error.
std::tuple<Status, int> sum_positive_exception(int a, int b) {
  if (a < 0 || b < 0) {
    return {Status::InvalidArgument, 0};
  }
  return {Status::Ok, a + b};
}

// If by design your function can't have invalid argument, which means,
// that if you have invalid argument, then it is a bug, which should be
// addressed. Use `assert` only for debug builds.
// https://en.cppreference.com/w/cpp/error/assert
// https://docs.microsoft.com/en-us/visualstudio/debugger/c-cpp-assertions
int sum_positive_assert(int a, int b) {
  assert(a >= 0 && b >= 0 && "Invalid Argument");
  return a + b;
}

int main() {
  try {
    open_file("happy_place.bmp");
  } catch (const std::runtime_error& exception) {
    std::cout << "Exception: " << exception.what() << std::endl;
    // handle exception...
  }

  auto [status, result] = sum_positive_exception(-1, 5);
  if (status == Status::InvalidArgument) {
    std::cout << "Error: Status::InvalidArgument" << std::endl;
    // handle error...
  }

  int res = sum_positive_assert(-1, 5);

  return 0;
}
