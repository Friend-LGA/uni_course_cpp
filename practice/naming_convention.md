# Naming Convention

Я понимаю, что никто не удосужился почитать приведенные ссылки по [Guidlines, Coding Standards](/#guidlines-coding-standards).
Поэтому давайте договоримся с вами о наших стандартах наименования:

- Файлы:
  - `snake_case` или `CamelCase`
  - Главное, чтобы было постоянство.
  - Расширения файлов:
    - `.hpp` и `.cpp`
  - Пример:
    - `graph_generator.hpp`
    - `graph_generator.hpp`
    - Или:
    - `GraphGenerator.hpp`
    - `GraphGenerator.hpp`
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
      ```
      Или:
      ```cpp
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
  - `ALL_CUPS` или начинаются на `k`
    - Пример:
      ```cpp
      constexpr int MONTHS_COUNT = 12;
      ```
      Или:
      ```cpp
      constexpr int kMonthsCount = 12;
      ```
