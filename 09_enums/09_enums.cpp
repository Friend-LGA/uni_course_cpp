// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#enum-enumerations
//
// https://en.cppreference.com/w/cpp/language/enum
//
// https://docs.microsoft.com/en-us/cpp/cpp/enumerations-cpp?view=msvc-160

// Don't use plain enums, as they are easily converted to int
// and they are not forced by compiler. Also they are in global scope.
enum Direction { North, East, West, South };

enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

int main() {
  int direction = North; // not very helpful...

  Day day = Day::Monday; // this is nice!
  
  return 0;
}
