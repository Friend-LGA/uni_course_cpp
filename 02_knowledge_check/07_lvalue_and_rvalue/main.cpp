// https://en.cppreference.com/w/cpp/language/value_category

#include <iostream>

int main() {
  int a = 10;
  // int& lValRef = 15; // ERROR: must be lvalue
  int& lValRef = a;
  // int&& rValRef = a; // ERROR: must be rvalue
  int&& rValRef = 15;

  std::cout << "lValRef = " << lValRef << std::endl;
  std::cout << "rValRef = " << rValRef << std::endl;

  return 0;
}
