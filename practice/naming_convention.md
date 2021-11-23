# Naming Convention

В каждой команде, которая ведет разработку совместно, всегда имеется свой стандарт написания кода.

Поэтому давайте договоримся с вами о наших стандартах наименования:

- Файлы:
  - `snake_case` или `CamelCase`
  - Главное, чтобы было постоянство.
  - Расширения файлов:
    - `.hpp` - header files
    - `.cpp` - source files
  - Пример:
    ```cpp
    - graph_generator.hpp
    - graph_generator.cpp
    // или
    - GraphGenerator.hpp
    - GraphGenerator.cpp
    ```
- Названия для `Struct`, `Class`, `Enum`, `Type` и опций внутри `Enum`:
  - `CamelCase`
  - Пример:
    ```cpp
    struct SomeStruct {};
    class SomeClass {};
    enum class SomeEnum { OptionOne, OptionTwo, OptionThree };
    using SomeType = int;
    ```
- Названия для перменных и функций:
  - `snake_case` или `camelCase`
  - Главное, чтобы было постоянство.
  - Пример:
    ```cpp
    int some_var = 15;
    void some_function();
    // или
    int someVar = 15;
    void someFunction();
    ```
- Названия для приватных переменных:
  - Оканчиваются на `_`
  - Пример:
    ```cpp
    class SomeClass {
     public:
      int public_var;
     private:
      int private_var_;
    }
    ```
- Названия  констант:
  - `ALL_CUPS` или `kCamelCase` или `k_snake_case`
  - Пример:
    ```cpp
    constexpr int MONTHS_COUNT = 12;
    // или
    constexpr int kMonthsCount = 12;
    // или
    constexpr int k_months_count = 12;
    ```

# Links

- [ISO C++: Coding Standards](https://isocpp.org/wiki/faq/coding-standards)
- [ISO C++: Core Guidlines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [ISO C++: FAQ](https://isocpp.org/wiki/faq)
- [Microsoft: C++ Guide](https://docs.microsoft.com/en-us/cpp/cpp/cpp-language-reference)
- [Google: C++ Guide](https://google.github.io/styleguide/cppguide.html)
- [Perforce: C++ Coding Standard](https://www.perforce.com/resources/qac/high-integrity-cpp-coding-standard)
- [GeoSoft: C++ Style](https://geosoft.no/development/cppstyle.html)
