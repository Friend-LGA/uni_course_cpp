// https://en.cppreference.com/book/intro/smart_pointers
// https://en.cppreference.com/w/cpp/memory/unique_ptr
// https://en.cppreference.com/w/cpp/memory/shared_ptr
// https://en.cppreference.com/w/cpp/memory/weak_ptr
//
// https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp
//
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#rsmart-smart-pointers

#include <iostream>
#include <memory>

int main() {
  // This is just a value on the stack.
  int simple_var1;
  int simple_var2 = 314;

  // This is a pointer to some data, usually to some big object allocated on the
  // heap. It can be null, in other words it can point to nothing, which is
  // expected. Usually it is used to decrease performance hit by copying/moving
  // of big objects in memory, instead we are copying and moving small pointer
  // to this object. If object has been created on heap by operator `new`, then
  // it also should be menually deleted by operator `delete`, otherwise it will
  // be a memory leak in the program.
  int* raw_pointer1;
  int* raw_pointer2 = nullptr;
  int* raw_pointer3 = new int(315);  // Allocated on the heap,
                                     // have to be deleted manually
  int* raw_pointer4 = &simple_var2;
  // int* raw_pointer5 = 316; // ERROR, you need to init with `new`

  // This is a reference to some data, usually used to pass object by value if
  // it needs to be changed and to have better performance by eliminating
  // copying or moving of the object itself. Reference can't point to nothing
  // and can't be null.
  int& reference1 = simple_var1;
  int& reference2 = *raw_pointer4;
  // int& reference3 = nullptr; // ERROR, can't be null
  // int& reference4; // ERROR, can't be undefined

  // Smart pointers are abstraction on top of raw pointers to avoid
  // memory leaks and improve ownership visibility.
  // When smart pointer is destroyed, it destroys internal raw pointer as well,
  // no need to do it manually any more.

  // Unique pointers can only exists in one copy and be owned by one entity.
  // They can't be copied, only moved.
  auto unique_pointer1 = std::make_unique<int>(317);          // Good
  auto unique_pointer2 = std::unique_ptr<int>(new int(318));  // BAD

  // ERROR, can only be moved, not references
  // auto unique_pointer3 = unique_pointer1;

  // it works, but unique_pointer1 can't be used any more
  // auto unique_pointer4 = std::move(unique_pointer1);

  // Shared pointers can be owned by many entities and can be copied.
  // Internally it has a counter of number of current owners,
  // and when it became zero, it destroys itself.
  auto shared_pointer1 = std::make_shared<int>(319);          // Good
  auto shared_pointer2 = std::shared_ptr<int>(new int(320));  // BAD
  auto shared_pointer3 = shared_pointer1;

  // Weak pointer can't be null, if it is pointing to null, then it is destroyed
  // immidiately. You always need to point weak pointer to some other shared
  // pointer. Weak pointers are necessary to avoid retain cycles, when 2
  // entities own each other. You need to use weak pointer when you want to use
  // data which should not be owned by you, so it will be destroyed, when
  // related shared pointer has been destroyed anywhere.
  std::weak_ptr weak_pointer1 = shared_pointer2;
  auto weak_pointer2 = std::weak_ptr<int>(shared_pointer2);

  // ERROR, will be destroyed immediately
  // auto weak_pointer3 = std::weak_ptr<int>(new int(321));

  // ERROR, can only be moved, not references
  // std::weak_ptr weak_pointer4 = unique_pointer2;

  // When you are planning to use weak pointer, you need to check if it not
  // expired yet, and then make strong pointer to it, wo it won't expire while
  // you are using it.
  if (false) {
    // This will create `shared_ptr` to the data `weak_ptr` is pointing to,
    // or, if it is expired, then it will be `nullptr`, which you should check.
    auto strong_pointer = weak_pointer1.lock();
    if (strong_pointer == nullptr)
      return 0;
    // Now use only strong_pointer to the end of the scope.
  }

  // clang-format off
  std::cout << "variable\t│ value\t\t\t| address (&)\t\t| dereference (*)\n"
            << "simple_var1\t│ "
            << simple_var1 << "\t\t│ "
            << &simple_var1 << "\t│ "
            << "n/a" << "\n"
            << "simple_var2\t│ "
            << simple_var2 << "\t\t\t│ "
            << &simple_var2 << "\t│ "
            << "n/a" << "\n"
            << "raw_pointer1\t│ "
            << raw_pointer1 << "\t\t\t│ "
            << &raw_pointer1 << "\t│ "
            << "null" << "\n"
            << "raw_pointer2\t│ "
            << raw_pointer2 << "\t\t\t│ "
            << &raw_pointer2 << "\t│ "
            << "null" << "\n"
            << "raw_pointer3\t│ "
            << raw_pointer3 << "\t│ "
            << &raw_pointer3 << "\t│ "
            << *raw_pointer3 << "\n"
            << "raw_pointer4\t│ "
            << raw_pointer4 << "\t│ "
            << &raw_pointer4 << "\t│ "
            << *raw_pointer4 << "\n"
            << "reference1\t│ "
            << reference1 << "\t\t│ "
            << &reference1 << "\t│ "
            << "n/a" << "\n"
            << "reference2\t│ "
            << reference2 << "\t\t\t│ "
            << &reference2 << "\t│ "
            << "n/a" << "\n"
            << "unique_pointer1\t│ "
            << unique_pointer1 << "\t│ "
            << &unique_pointer1 << "\t│ "
            << *unique_pointer1 << "\n"
            << "unique_pointer2\t│ "
            << unique_pointer2 << "\t│ "
            << &unique_pointer2 << "\t│ "
            << *unique_pointer2 << "\n"
            << "shared_pointer1\t│ "
            << shared_pointer1 << "\t│ "
            << &shared_pointer1 << "\t│ "
            << *shared_pointer1 << "\n"
            << "shared_pointer2\t│ "
            << shared_pointer2 << "\t│ "
            << &shared_pointer2 << "\t│ "
            << *shared_pointer2 << "\n"
            << "shared_pointer3\t│ "
            << shared_pointer3 << "\t│ "
            << &shared_pointer3 << "\t│ "
            << *shared_pointer3 << "\n"
            << "weak_pointer1\t│ "
            << "n/a\t\t" << "\t│ "
            << &weak_pointer1 << "\t│ "
            << "n/a" << "\n"
            << "weak_pointer2\t│ "
            << "n/a\t\t" << "\t│ "
            << &weak_pointer2 << "\t│ "
            << "n/a" << "\n";
  // clang-format on

  delete raw_pointer3;  // !!! Don't forget

  return 0;
}
