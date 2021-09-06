// https://en.cppreference.com/w/cpp/language/storage_duration

#include <iostream>

// global `static` - storage duration, which means that it lasts for the lifetime of the program.
static constexpr int kGlobalConst = 323;

// Use `static` keyword for global functions, this will limit it's visibility.
// They are invisible to the linker, 
// allowing other compilation units to define functions with the same signature.
static int sum(int a, int b) {
  return a + b;
}

void printInt() {
  int i = 0;
  i++;
  std::cout << "i = " << i << std::endl;
}

void printStaticInt() {
  static int i = 0;
  i++;
  std::cout << "static i = " << i << std::endl;
}

int main() {
  for (int i = 0; i < 5; i++) {
    printInt();
  }

  for (int i = 0; i < 5; i++) {
    printStaticInt();
  }

  return 0;
}
