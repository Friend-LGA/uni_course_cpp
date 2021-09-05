#include <iostream>

// The same as:
// int main(int argc, char** argv)
int main(int argc, char* argv[]) {
  std::cout << "argc == " << argc << std::endl;

  for (int i = 0; i <= argc; i++) {
    if (const auto val = argv[i]) {
      std::cout << "argv[" << i << "] == " << val << std::endl;
    }
    else {
      // End of arguments vector is always `nullptr`
      std::cout << "argv[" << i << "] == " << "nullptr" << std::endl;
    }
  }

  // Just as an example we check for 3 args
  return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE;
}
