// https://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap

#include <memory>
#include <string>
#include <vector>

struct MyAmazingStruct {
  int id = 0;
  std::string label = "";
};

int main() {
  int stack_int = 15;
  int* heap_int = new int(15);

  std::string stack_string = "I am on stack!";
  auto* heap_string = new std::string("I am on heap!");

  std::vector stack_vector = {1, 2, 3};
  auto* heap_vector = new std::vector({1, 2, 3});

  auto stack_struct = MyAmazingStruct();
  auto heap_struct = new MyAmazingStruct();

  // Calls `new` under the hood
  auto heap_unique = std::make_unique<int>(15);
  auto heap_shared = std::make_shared<int>(15);

  // Don't forget to delete raw pointers...
  delete heap_int;
  delete heap_string;
  delete heap_vector;
  delete heap_struct;

  return 0;
}
