// https://en.cppreference.com/w/cpp/language/types
// https://en.cppreference.com/w/cpp/types/integer
// https://en.cppreference.com/w/cpp/types/numeric_limits
// https://en.cppreference.com/w/c/types/size_t
//
// https://docs.microsoft.com/en-us/cpp/cpp/integer-limits
// https://docs.microsoft.com/en-us/cpp/cpp/floating-limits

// How are they stored in memory?
// For example 4 bit == 2^4 == 16 values:
// 0 0 0 0 == 00 == 0
// 0 0 0 1 == 01 == +1
// 0 0 1 0 == 02 == +2
// 0 0 1 1 == 03 == +3
// 0 1 0 0 == 04 == +4
// 0 1 0 1 == 05 == +5
// 0 1 1 0 == 06 == +6
// 0 1 1 1 == 07 == +7
// 1 0 0 0 == 08 == -1
// 1 0 0 1 == 09 == -2
// 1 0 1 0 == 10 == -3
// 1 0 1 1 == 11 == -4
// 1 1 0 0 == 12 == -5
// 1 1 0 1 == 13 == -6
// 1 1 1 0 == 14 == -7
// 1 1 1 1 == 15 == -8

#include <iostream>
#include <limits>

int main() {
  // Boolean Type
  // bool size is 1 bit, it can has value 0 or 1, which is usually represented
  // as true or false.
  bool positive = true;
  bool negative = false;

  // Character Types
  // char size is 8 bit, usually represents string characters.
  char character1 = 127;           // range is [-2^7, (2^7)-1] == [-128, 127]
  unsigned char character2 = 255;  // range is [0, (2^8)-1] == [0, 255]

  // Integer Types
  // int size is 16 bit on 32bit systems and 32 bit on 64bit systems.
  // Size of int may differ for different systems.
  // For 16bit system range is [-2^15, (2^15)-1] == [-32768, 32767]
  // For 32bit system range is [-2^31, (2^31)-1] == [-2147483648, 2147483647]
  int integer1 = 32767;
  // For 16bit system range is [0, (2^16)-1] == [0, 65535]
  // For 32bit system range is [0, (2^32)-1] == [0, 4294967295]
  unsigned int integer2 = 0;

  // Can store the maximum size of a theoretically possible object of any type.
  // Should be used whenever you are implementing any collection, for the size of
  // this collection.
  size_t size = 100;

  // Floating-Point Types
  float number = 0.0000034;  // range is [-3.40282e+38, 3.40282e+38], smallest
                             // is 1.17549e-38

  // clang-format off
  std::cout << "type\t\t\t│ sizeof, bit\t| min\t\t\t│ max\n"
            << "bool\t\t\t│ " << sizeof(bool) * 8 << "\t\t│ "
            << std::numeric_limits<bool>::min() << "\t\t\t│ "
            << std::numeric_limits<bool>::max() << '\n'
            << "char\t\t\t│ " << sizeof(char) * 8 << "\t\t│ "
            << std::numeric_limits<char>::min() << "\t\t\t│ "
            << std::numeric_limits<char>::max() << '\n'
            << "unsigned char\t\t│ " << sizeof(unsigned char) * 8 << "\t\t│ "
            << std::numeric_limits<unsigned char>::min() << "\t\t\t│ "
            << std::numeric_limits<unsigned char>::max() << '\n'
            << "int\t\t\t│ " << sizeof(int) * 8 << "\t\t│ "
            << std::numeric_limits<int>::min() << "\t\t│ "
            << std::numeric_limits<int>::max() << '\n'
            << "unsigned int\t\t│ " << sizeof(unsigned int) * 8 << "\t\t│ "
            << std::numeric_limits<unsigned int>::min() << "\t\t\t│ "
            << std::numeric_limits<unsigned int>::max() << '\n'
            << "long\t\t\t│ " << sizeof(long) * 8 << "\t\t│ "
            << std::numeric_limits<long>::min() << "\t│ "
            << std::numeric_limits<long>::max() << '\n'
            << "unsigned long\t\t│ " << sizeof(unsigned long) * 8 << "\t\t│ "
            << std::numeric_limits<unsigned long>::min() << "\t\t\t│ "
            << std::numeric_limits<unsigned long>::max() << '\n'
            << "long long\t\t│ " << sizeof(long long) * 8 << "\t\t│ "
            << std::numeric_limits<long long>::min() << "\t│ "
            << std::numeric_limits<long long>::max() << '\n'
            << "unsigned long long\t│ " << sizeof(unsigned long long) * 8 << "\t\t│ " 
            << std::numeric_limits<unsigned long long>::min() << "\t\t\t│ " 
            << std::numeric_limits<unsigned long long>::max() << '\n'
            << "float\t\t\t│ " << sizeof(float) * 8 << "\t\t│ "
            << std::numeric_limits<float>::min() << "\t\t│ "
            << std::numeric_limits<float>::max() << '\n'
            << "double\t\t\t│ " << sizeof(double) * 8 << "\t\t│ "
            << std::numeric_limits<double>::min() << "\t\t│ "
            << std::numeric_limits<double>::max() << '\n'
            << "long double\t\t│ " << sizeof(long double) * 8 << "\t\t│ "
            << std::numeric_limits<long double>::min() << "\t\t│ "
            << std::numeric_limits<long double>::max() << '\n';
  // clang-format on

  return 0;
}

// Void Type
// Type with an empty set of values.
// This type is used when you don't need specific value,
// for example when function doesn't return a value.
void func() {
  // ... some logic
  return;
}
