// https://en.wikipedia.org/wiki/Template_(C%2B%2B)
// https://isocpp.org/wiki/faq/templates
// https://en.cppreference.com/w/cpp/language/templates
// https://docs.microsoft.com/en-us/cpp/cpp/templates-cpp
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#t-templates-and-generic-programming

#include <array>
#include <iostream>

template <typename T>
T min(const T& lhs, const T& rhs) {
  return lhs < rhs ? lhs : rhs;
}

template <typename T, size_t Size>
class ArrayWrapper {
 public:
  T& at(size_t pos) { return internal_.at(pos); }
  size_t size() { return internal_.size(); }

 private:
  std::array<T, Size> internal_;
};

int main() {
  auto a = min(8, 12);
  std::cout << "min(8, 12) == " << a << std::endl;

  auto b = min(0.15, 0.28);
  std::cout << "min(0.15, 0.28) == " << b << std::endl;

  auto c = min('a', 'b');
  std::cout << "min('a', 'b') == " << c << std::endl;

  auto array = ArrayWrapper<int, 5>();
  array.at(3) = 116;
  std::cout << "size of array is " << array.size() << std::endl;
  std::cout << "3rd element of array is " << array.at(3) << std::endl;

  return 0;
}
