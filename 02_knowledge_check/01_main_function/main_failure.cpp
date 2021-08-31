// https://en.cppreference.com/w/cpp/language/main_function
// https://docs.microsoft.com/en-us/cpp/cpp/main-function-command-line-args
// https://stackoverflow.com/questions/204476/what-should-main-return-in-c-and-c

#include <iostream>

int main() {
  std::cout << "Hello World!" << std::endl;
  std::cout << "Failure" << std::endl;
  return 1; // EXIT_FAILURE
}
