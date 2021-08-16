// https://en.cppreference.com/w/cpp/language/namespace
//
// https://docs.microsoft.com/en-us/cpp/cpp/namespaces-cpp

#include <string>
#include <vector>

////////////
// Global //
////////////

struct Data1 {}; // Can't be static

static void function1() {}

///////////////////////
// Private Namespace //
///////////////////////

namespace {

struct Data2 {}; // now it behaves like static

void function2() {}

}  // namespace

/////////////////////
// Named Namespace //
/////////////////////

namespace uni {

struct Data3 {};

void function3() {}

}  // namespace uni

/////////////
// Testing //
/////////////

using String = std::string;
using IntVector = std::vector<int>;

// Don't include whole namespaces, it's error-prone.
using namespace std; // BAD

int main() {
  auto a = Data1();
  function1();

  auto b = Data2();
  function2();

  auto c = uni::Data3();
  uni::function3();

  auto string = String();
  auto vector = IntVector();

  return 0;
}
