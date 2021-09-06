// https://en.cppreference.com/w/cpp/language/namespace
// https://docs.microsoft.com/en-us/cpp/cpp/namespaces-cpp

// Namespaces are needed to avoid name collisions

// Named nested namespaces
namespace foo {
namespace bar {
namespace baz {

void function() {}

}  // namespace baz
}  // namespace bar
}  // namespace foo

// Unnamed, private namespace
namespace {

void function() {}

}  // namespace

int main() {
  foo::bar::baz::function();
  function();
  return 0;
}
