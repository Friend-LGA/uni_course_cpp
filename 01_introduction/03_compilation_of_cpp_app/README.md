# Compilation of a C++ app
1. Write simple `hello_world.cpp`
    ```cpp
    #include <iostream>

    int main() {
      std::cout << "Hello World!" << std::endl;
      return 0;
    }
    ```
2. Use `clang++` to compile `hello_world.cpp`
    - ```clang++ hello_world.cpp -o hello_world -std=c++17```
    - Useful Clang Flags:
        - `-std=c++17` to specify version of C++ 17
        - `-Weverything` to enable all warnings
        - `-Wno-...` to disable specific warning
        - [All Flags](https://clang.llvm.org/docs/DiagnosticsReference.html)
3. Run compiled `hello_world` app
    - `./hello_world`
