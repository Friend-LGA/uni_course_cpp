# Naming Convention

В каждой команде, которая ведет разработку совместно, всегда имеется свой стандарт написания кода.
Наши стандары наименования будут следующими:

- Файлы:
  - `snake_case`
  - Расширения файлов:
    - `.hpp` - header files
    - `.cpp` - source files
  - Пример:
    ```cpp
    - graph_generator.hpp
    - graph_generator.cpp
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
- Названия для перменных, функций и неймспейсов:
  - `snake_case`
  - Пример:
    ```cpp
    int some_var = 15;
    void some_function();
    namespace some_namespace {}
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
    };
    ```
- Названия глобальных констант:
  - `kCamelCase` (начинаются на `k`)
  - Пример:
    ```cpp
    static constexpr int kMonthsCount = 12;
    ```
- Названия интерфейсов:
  - `ICamelCase` (начинаются на `I`)
  - Пример:
    ```cpp
    class IClassName {};
    ```
- Не использовать зарезервированные форматы:
  - Все буквы капсом - `ALL_CAPS`
  - Начинающиеся с подчеркивания - `_name`
- Сначала `const` модификатор, потом тип данных, потом ссылка или указатель:
  - `const Graph& graph;`

# Links

- [ISO C++: Coding Standards](https://isocpp.org/wiki/faq/coding-standards)
- [ISO C++: Core Guidlines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [ISO C++: FAQ](https://isocpp.org/wiki/faq)
- [Microsoft: C++ Guide](https://docs.microsoft.com/en-us/cpp/cpp/cpp-language-reference)
- [Google: C++ Guide](https://google.github.io/styleguide/cppguide.html)
- [Perforce: C++ Coding Standard](https://www.perforce.com/resources/qac/high-integrity-cpp-coding-standard)
- [GeoSoft: C++ Style](https://geosoft.no/development/cppstyle.html)
