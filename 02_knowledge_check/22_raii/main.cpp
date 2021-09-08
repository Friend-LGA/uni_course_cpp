// https://en.cppreference.com/w/cpp/language/raii
// https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization

#include <iostream>
#include <memory>
#include <stdexcept>

void unsafe_function() {
  auto pointer = new int(15);
  if (false /* some condition */) {
    return;  // BAD: memory leak
  }
  if (false /* some condition */) {
    throw std::runtime_error("message");  // BAD: memory leak
  }
  delete pointer;
}

void safe_function() {
  auto pointer = std::make_unique<int>(15);
  if (false /* some condition */) {
    return;  // GOOD: destructor is executed
  }
  if (false /* some condition */) {
    throw std::runtime_error("message");  // GOOD: destructor is executed
  }
  // No need for manual `delete`
}

int main() {
  return 0;
}
