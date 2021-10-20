// #pragma once // Should not be used in main file

#define PI 3.14
#define MIN(x, y) ((x) < (y) ? x : y)
#define OUTPUT(a) std::cout << "Output: " << a << std::endl

#define IS_DEBUG_BUILD 1

#ifdef IS_DEBUG_BUILD
#define DEBUG_ASSERT(x) assert(x)
#else
#define DEBUG_ASSERT(x) (void)0
#endif

#ifndef TEST
#define TEST
#endif

#undef TEST

#if defined(WIN32)
#define PUTS_PLATFORM() OUTPUT("Platform is WIN32")
#elif defined(WIN64)
#define PUTS_PLATFORM() OUTPUT("Platform is WIN64")
#else
#define PUTS_PLATFORM() OUTPUT("Platform is Undefined")
#endif

#if IS_DEBUG_BUILD == 1
#define PUTS_DEBUG() OUTPUT("Debug is Enabled")
#elif IS_DEBUG_BUILD == 0
#define PUTS_DEBUG() OUTPUT("Debug is Disabled")
#else
#define PUTS_DEBUG() OUTPUT("Debug is Undefined")
#endif

#define MY_ASSERT(BOOL_EXPRESSION)                                     \
  do {                                                                 \
    if (!(BOOL_EXPRESSION)) {                                          \
      printf("MY_ASSERT FAILED: \"" #BOOL_EXPRESSION "\" on %s(%d)\n", \
             __FILE__, __LINE__);                                      \
      exit(-1);                                                        \
    }                                                                  \
  } while (0)

#include <cassert>
#include <iostream>

int main() {
  OUTPUT("PI = " << PI);
  OUTPUT("MIN(16, 8) = " << MIN(16, 8));
  DEBUG_ASSERT(MIN(16, 8) == 8 && MIN(8, 16) == 8);
  PUTS_PLATFORM();
  PUTS_DEBUG();

#ifdef IS_DEBUG_BUILD
  MY_ASSERT(1 + 1 == 1);
#else
  // use production logger
#endif

  return EXIT_SUCCESS;
}
