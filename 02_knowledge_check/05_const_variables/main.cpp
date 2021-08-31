// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#con-constants-and-immutability

// in modern c++ the same as `static const` below.
const int kSomeConstVar1 = 10;

// global `static` - storage duration, which means that it lasts for the lifetime of the program.
// https://en.cppreference.com/w/cpp/language/storage_duration
static const int kSomeConstVar2 = 15;

// `constexpr` tells compiler to evaluate variable at compile time.
// Use it whenever possible.
// https://en.cppreference.com/w/cpp/language/constexpr
// https://docs.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=msvc-160
static constexpr int kSomeConstVar3 = 20;

// Don't use global non const variables!
int kGlobalVariable = 5; // BAD

// Don't use MACROS as global constants!
#define PI 3.14 // BAD

int main() {
  ////////////
  // VALUES //
  ////////////

  int a1 = 5;
  a1 = 10;

  const int a2 = 5;
  // a2 = 10; // ERROR

  ////////////////
  // REFERENCES //
  ////////////////

  int& b1 = a1;
  b1 = 15;

  // reference to const value.
  const int& b2 = a1;
  // b2 = 15; // ERROR

  //////////////
  // POINTERS //
  //////////////

  int* c1 = &a1;
  c1 = &b1;
  *c1 = 20;

  // pointer to const value.
  // pointer can be changed, for example to point on different data
  // int can't be changed as it is const
  const int* c2 = &a1;
  c2 = &b1; // Ok, pointer is not const
  // *c2 = 20; // ERROR, value is const

  // const pointer to value.
  // pointer can't be changed, but int can be changed.
  // It is not really makes much sense to have const pointer, as it is anyway
  // just a copy of the other pointer. What important is if data const or not.
  int* const c3 = &a1;
  // c3 = &b1; // ERROR, pointer is const
  *c3 = 20; // Ok, value is not const

  // const pointer to const value.
  // Neither pointer nor string can be changed.
  // Almost never used.
  const int* const c4 = &a1;
  // c4 = &b1; // ERROR, pointer is const
  // *c4 = 20; // ERROR, value is const

  return 0;
}
