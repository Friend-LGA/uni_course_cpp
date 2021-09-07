// https://en.cppreference.com/w/cpp/language/copy_constructor
// https://en.cppreference.com/w/cpp/language/move_constructor
// https://en.cppreference.com/w/cpp/language/copy_assignment
// https://en.cppreference.com/w/cpp/language/move_assignment
// https://en.cppreference.com/w/cpp/utility/move
// https://docs.microsoft.com/en-us/cpp/cpp/constructors-cpp
// https://docs.microsoft.com/en-us/cpp/cpp/copy-constructors-and-copy-assignment-operators-cpp
// https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#cdefop-default-operations

#include <memory>

class SomeClass {
 public:
  SomeClass() = default;
  ~SomeClass() = default;

  // Copy Constructor
  SomeClass(const SomeClass& other) = default;

  // Copy Assignment
  SomeClass& operator=(const SomeClass& other) = default;

  // Move Constructor
  SomeClass(SomeClass&& other) = default;

  // Move Assignment
  SomeClass& operator=(SomeClass&& other) = default;
};

// Example of manually implementing constructor, destructor, copy and move.
class ExampleClass {
 public:
  int value;
  int* pointer;
  std::unique_ptr<int> smart_pointer;

  ExampleClass(int master_int)
      : value(master_int), pointer(new int(master_int)), smart_pointer(std::make_unique<int>(master_int)) {}

  ~ExampleClass() {
    // Raw pointer needs to be manually deleted.
    delete pointer;
  }

  //////////////////////
  // Copy Constructor //
  //////////////////////

  // Shallow Copy
  ExampleClass(const ExampleClass& other)
      : value(other.value), pointer(other.pointer), smart_pointer(std::make_unique<int>(*other.smart_pointer.get())) {}

  // Deep Copy
  // ExampleClass(const ExampleClass& other)
  //     : value(other.value),
  //       pointer(new int(*other.pointer)),
  //       smart_pointer(std::make_unique<int>(*other.smart_pointer.get())) {}

  /////////////////////
  // Copy Assignment //
  /////////////////////

  // Shallow Copy
  ExampleClass& operator=(const ExampleClass& other) {
    value = other.value;
    pointer = other.pointer;
    smart_pointer = std::make_unique<int>(*other.smart_pointer.get());
    return *this;
  }

  // Deep Copy
  // ExampleClass& operator=(const ExampleClass& other) {
  //   value = other.value;
  //   pointer = new int(*other.pointer);
  //   smart_pointer = std::make_unique<int>(*other.smart_pointer.get());
  //   return *this;
  // }

  //////////////////////
  // Move Constructor //
  //////////////////////

  // Other object should stay in valid but unspecified state
  ExampleClass(ExampleClass&& other)
      : value(std::move(other.value)),
        pointer(std::move(other.pointer)),
        smart_pointer(std::move(other.smart_pointer)) {}

  /////////////////////
  // Move Assignment //
  /////////////////////

  ExampleClass& operator=(ExampleClass&& other) {
    value = std::move(other.value);
    pointer = std::move(other.pointer);
    smart_pointer = std::move(other.smart_pointer);
    return *this;
  }
};

int main() { return 0; }
