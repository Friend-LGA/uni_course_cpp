// https://en.cppreference.com/w/cpp/language/main_function
// https://docs.microsoft.com/en-us/cpp/cpp/main-function-command-line-args
// https://stackoverflow.com/questions/204476/what-should-main-return-in-c-and-c

#include <iostream>

int main() {
  std::cout << "Hello World!" << std::endl;
  std::cout << "Success" << std::endl;
  // Unnecessary, `main()` implicitly will `return 0` if no return specified
  return 0; // EXIT_SUCCESS
}
