#include <vector>
#include <tuple>
#include <iostream>

// If you don't want to write all nested namespaces
using std::vector;

// If you want to make more sense out of some complex type
using IntPair = std::tuple<int, int>;

// To have more context of what the type means
using seconds = float;

// Don't include whole namespaces, it's error-prone.
using namespace std; // BAD

void sleep(seconds interval) {
  // some logic
}

int main() {
  cout << "I don't need to write `std::` !!!" << endl;

  auto a = IntPair(10, 32);

  sleep(5.0);

  return 0;
}
