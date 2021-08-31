// https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library
//
// https://en.cppreference.com/w/cpp/header
// https://en.cppreference.com/w/cpp/io/cout
// https://en.cppreference.com/w/cpp/string/basic_string
// https://en.cppreference.com/w/cpp/container/array
// https://en.cppreference.com/w/cpp/container/vector
// https://en.cppreference.com/w/cpp/chrono
// https://en.cppreference.com/w/cpp/utility/optional
// https://en.cppreference.com/w/cpp/utility/tuple
//
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#sl-the-standard-library

#include <array>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

int main() {
  // String
  std::string string = "Hello";
  string.append(" Test");
  string.replace(6, 4, "World");
  std::cout << "String: " << string << std::endl;

  // Array
  // Size is fixed.
  std::array<int, 4> array;
  array.at(1) = 2;
  array.at(2) = 3;
  array.at(3) = 1;
  std::sort(array.begin(), array.end());
  const auto array_size = array.size();

  std::cout << "Array: [";

  for (size_t i = 0; i < array_size; i++) {
    std::cout << array.at(i);
    if (i < array_size - 1) {
      std::cout << ", ";
    }
  }

  std::cout << "], size is " << array.size() << std::endl;

  std::array<int, 4> array2 = {0, 1, 2, 3};
  if (array == array2) {
    std::cout << "Array: the same" << std::endl;
  } else {
    std::cout << "Array: different" << std::endl;
  }

  // Vector
  // Size is flexible.
  std::vector<std::string> vector = {"C ", "Plus", " Nirvana"};
  vector.pop_back();
  vector.push_back(" Plus");

  std::string result_string;
  for (const auto& item : vector) {
    result_string.append(item);
  }

  std::cout << "Vector: all elements combined == " << result_string << std::endl;

  // Optional
  // It helps to add nullable state to the values, which can't be null.
  // For example if function couldn't calculate the number it can return null.
  int number = 15;
  auto optional_number = std::optional<int>(number);

  if (optional_number.has_value()) {
    std::cout << "Optional: value is " << optional_number.value() << std::endl;
  }

  // Tuple
  // It lets you easily create pairs of values.
  // For example if the function need to return Value and Error.
  auto tuple = std::make_tuple("Alisa", 18);
  auto [name, age] = tuple;
  std::cout << "Tuple: " << name << " is " << age << " years old" << std::endl;

  return 0;
}
