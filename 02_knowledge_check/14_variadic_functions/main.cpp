// The old way
// https://en.cppreference.com/w/cpp/utility/variadic

// The new way
// https://en.cppreference.com/w/cpp/language/parameter_pack
// https://en.cppreference.com/w/cpp/language/fold

#include <iostream>

template <class... Args>
void print(Args... args) {
  // ( init op ... op pack )
  (std::cout << ... << args) << std::endl;
}

int main() {
  print(1, ':', " Hello", ',', " ", "World!");
  return 0;
}
