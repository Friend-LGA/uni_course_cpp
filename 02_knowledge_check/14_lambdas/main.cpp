// https://en.cppreference.com/w/cpp/language/lambda
// https://en.cppreference.com/w/cpp/utility/functional/function
//
// https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp
//
// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#SS-lambdas

#include <functional>
#include <string>

using SomeLambda = int (*)(int, int);
using SomeFunction = std::function<int(int, int)>;

void func1(int (*f)(int, int)) {
  int sum = f(5, 10);
}

void func2(std::function<int(int, int)> f) {
  int sum = f(5, 10);
}

void func3(SomeLambda f) {
  int sum = f(5, 10);
}

void func4(SomeFunction f) {
  int sum = f(5, 10);
}

int main() {
  int a_out = 0;
  int c_out = 0;

  // Lambda generally the same as function, but also aware of the scope it
  // exists in.
  auto lambda = []() {
    // do something...
  };

  // Don't capture any outside variables.
  // Has 2 attributes as input: b and c.
  // Return int.
  auto lambda1 = [](int b, int c = 5) -> int { return b + c; };

  // Captures everything by value.
  // Internal `a_out` is just a copy of declared outside `a_out`.
  // Then if you change internal `a_out`, outer `a_out` will stay the same.
  auto lambda2 = [=](int b) -> int { return a_out + b; };

  // Captures everything by reference.
  // Internal `a_out` is a reference to outer `a_out`.
  // If you change `a_out` inside lambda, then `a_out` outside will be changed
  // as well.
  auto lambda3 = [&](int b) -> int { return a_out + b; };

  // Captures only specified variables.
  // Better this way, as we explicitly tells which variables we need and how to
  // capture them.
  auto lambda4 = [a_out, &c_out](int b) -> int { return a_out + b + c_out; };

  // Captures into differently-named variables.
  // Good as well, but a little bit too verbose.
  auto lambda6 = [a_in = a_out, &c_in = c_out](int b) -> int {
    return a_in + b + c_in;
  };

  // Lambda can be passed as an argument to a function.
  func1(lambda1);
  func2(lambda1);
  func3(lambda1);
  func4(lambda1);

  return 0;
}
