# `C Style` vs `C++ Style`

Напоминаю что у нас практикум по `C++` и использовать голый синтаксис `C` без крайней необходимости запрещено.
Почти каждая из возможностей языка `C` имеет свою обертку в `C++`.
На практикуме мы хотим научиться писать качественный, высокоуровневый, поддерживаемый, масштабируемый код.

Примеры:
- Raw Pointers vs Smart Pointers:
  - `C`:
    ```cpp
    int* raw_pointer = new int(5);
    delete raw_pointer; // life time is manually controlled
    ```
  - `C++`:
    ```cpp
    std::unique_ptr<int> smart_unique_pointer = std::make_unique<int>(5);
    std::shared_ptr<int> smart_shared_pointer = std::make_shared<int>(5);
    // no need for delete
    ```
- Collections:
  - `C`:
    ```cpp
    int array1[5] = {0, 1, 2, 3, 4};
    int (*array2)[5] = {0, 1, 2, 3, 4};

    int vector1[] = {0, 1, 2};
    int* vector2 = {0, 1, 2};
    ```
  - `C++`:
    ```cpp
    std::array<int, 5> array = {0, 1, 2, 3, 4};
    std::vector<int> vector = {0, 1, 2};
    ```
- Strings:
  - `C`:
    ```cpp
    char string1[] = "string 1";
    char* string2 = "string 2";
    ```
  - `C++`:
    ```cpp
    std::string string = "string";
    ```
- Enumerations:
  - `C`:
    ```cpp
    enum SomeEnum { Option0 = 0, Option1 = 1 };
    SomeEnum c_enum = 0; // works
    ```
  - `C++`:
    ```cpp
    enum class SomeEnum { Option0 = 0, Option1 = 1 };
    SomeEnum cpp_enum1 = 0; // compilation error
    SomeEnum cpp_enum2 = SomeEnum::Option0;
    ```
- Output:
  - `C`:
    ```cpp
    printf("Output");
    ```
  - `C++`:
    ```cpp
    std::cout << "Output" << std::endl;
    ```
- Type Casting:
  - `C`:
    ```cpp
    char c = 'a';
    int* p = (int*)&c; // works

    int a = 5;
    float b = (float)a;
    ```
  - `C++`:
    ```cpp
    char c = 'a';
    int* p = static_cast<int*>(&c); // compilation error

    int a = 5;
    float b = static_cast<float>(a);
    ```
- Asserts:
  - Не имеет аналога в `C++`, можно использовать `C`.
    ```cpp
    assert(some_condition() && "Description message");
    ```
- И т.д. и т.п.
- Ну вы поняли идею, правильно?
