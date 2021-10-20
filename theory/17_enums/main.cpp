// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#enum-enumerations
// https://en.cppreference.com/w/cpp/language/enum
// https://docs.microsoft.com/en-us/cpp/cpp/enumerations-cpp

// Don't use plain enums, as they are easily converted to int
// and they are not forced by compiler. Also they are in global scope.
enum Direction { North, East, West, South };

enum class Day {
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday
};

// Is not very expressive and we need to manually validate the boundaries
void process1(int day) {
  // validate (day > 0 && day < 7)
  // some logic
}

// Already better, but we still need to manually validate the boundaries
using DayNumber = int;
void process2(DayNumber day) {
  // validate (day > 0 && day < 7)
  // some logic
}

// GOOD!!! Easily understandable and compiler will do validation for us
void process3(Day day) {
  // some logic
}

int main() {
  int direction = North;  // just an int, not very helpful...

  Day day = Day::Monday;  // this is nice!

  return 0;
}
