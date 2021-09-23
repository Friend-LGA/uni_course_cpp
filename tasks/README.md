# Общая Идея

1. Задача практикума - написать игру, которая будет играть сама в себя. То, что мы должны получить:
    - Игровое поле, представляющее собой граф.
    - В начале этого поля находится рыцарь.
    - В конце этого поля находится принцесса.
    - Переход между клетками игрового поля (вершинами графа) занимает определенное время.
    - При переходе есть вероятность что рыцарь наткнется на противника (дракон, виверна, тролль, и т.д.) и завяжется схватка.
    - У рыцаря и у его противников есть характеристики (здоровье, выносливость, атака, и т.д.).
    - Нужно найти кратчайший и наиболее безопасный пути к принцессе, а так же подобрать оптимальные характеристики для рыцаря.
1. У нас есть общий репозиторий, к которому у вас у всех есть/будет доступ. Каждая задача представляет собой `Pull Request` в этот репозиторий.
   Когда `Pull Request` проверен мной и залит вами в `master`, тогда задача считается выполненной.
1. У нас с вами практикум по `C++`, поэтому использовать голый синтаксис `C` без крайней необходимости запрещено.
1. Использовать сторонние библиотеки также запрещено. Пользуйтесь теми инструментами, которые дает вам язык.

# Workflow

1. Сделать `fork` репозитория, куда вы будете загружать выполненные задачи (ссылку спросить у меня).
    - [Docs: About Forks](https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/about-forks)
    - [Docs: Fork a Repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo)
1. Для каждой новой задачи создаете новый `branch`:
    - Формат названий бранчей следующий:
      - `name_surname/task_number`
    - Пример:
      - `grigorii_lutkov/task_01`
1. Для каждой новой задачи, при необходимости, создаете подпапку:
    - Формат иерархии директорий следующий:
      - `/task_dir_name/name_surname/*`
      - `task_dir_name` дано в описании каждой задачи (`Рабочая директория`)
    - Пример:
      - `/01_hello_world/grigorii_lutkov/*`
1. Все изменения должны находиться только внутри данной папки. Так как мы все работаем в одном общем репозитории, то каждый работает только внутри своей папки и не трогает файлы других студентов. Каждый отдельный `branch` должен включать в себя только те изменения, которые имеют отношения к конкретной задаче.
1. Когда задача готова, создаете `Pull Request` со следующими параметрами:
    - Base Repository: Общий репозиторий
    - Base Branch: `master`
    - Head Repository: Ваш `fork` общего репозитория
    - Compare Branch: `branch`, в котором вы выполняли работу по конкретной задаче
    - Name: `name_surname/task_number`
      - Пример:
        - `grigorii_lutkov/task_01`
    - Status: `Ready for Review`
      - [Docs: Changing the State of a Pull Request](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/changing-the-stage-of-a-pull-request)
    - Reviewers: `Grigorii Lutkov`
    - Labels: `task_number`
      - Пример:
        - `task_01`
    - Description: Оставьте пустым
    - [Docs: About Pull Requests](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests)
    - [Docs: Creating a Pull Request from a Fork](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork)
1. Я провожу ревью и дальнешее развитие может быть:
    - Я подтверждаю изменения.
      - Вы можете мерджить `Pull Request`
        - [Docs: Merging a Pull Request](https://docs.github.com/en/github/collaborating-with-pull-requests/incorporating-changes-from-a-pull-request/merging-a-pull-request)
    - Я оставляю комментарии и запрашиваю изменения.
      - Исправляете ошибки
      - Коммитите исправления в свой `branch`
      - `Pull Request` обновится автоматически
      - Запрашиваете ревью:
        - [Docs: Requesting a Pull Request Review](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/requesting-a-pull-request-review)
1. Повторяем предыдущий шаг, пока не добьемся успеха.

# Common Mistakes

## 1. Неверное название бранчей (`branch`)

Повторяю:
- Формат названий бранчей следующий:
  - `name_surname/task_number`
- Пример:
  - `grigorii_lutkov/task_01`

## 2. Неверная иерархия директорий

Повторяю:
- Формат иерархии директорий следующий:
  - `/task_dir_name/name_surname/*`
- Пример:
  - `/01_hello_world/grigorii_lutkov/*`

## 3. Добавление в `Pull Request` неотносящихся изменений

К примеру, при добавлении файлов первой задачи, вы, зачем-то, удаляете файлы других студентов из репозитория :))

`Pull Request` представляет собой ваш `branch`, который, в свою очередь, представляет собой логически завершенный блок работы, включающий в себя только те изменения, которые необходимы для реализации поставленной задачи.

Вернемся к примеру выше: для реализации первой задачи, необходимости удалять чужие файлы из репозитория нет.

## 4. No Newline at End of File

У текстовых фалов есть определенный формат, и, следуя этому формату, заканчиваться они должны символом новой строки. Это необходимо чтобы правильно определять количество строк в файле.

Кому сильно интересно:
- [Дискуссия 1](https://stackoverflow.com/questions/5813311/whats-the-significance-of-the-no-newline-at-end-of-file-log)
- [Дискуссия 2](https://unix.stackexchange.com/questions/18743/whats-the-point-in-adding-a-new-line-to-the-end-of-a-file)

## 5. `using namespace`

Использовать `using namespace` считается плохой практикой.
Вместе этого лучше использовать ограниченный `using` (см. [aliases](/02_knowledge_check/13_aliases)):

```cpp
using std::cout;
using std::endl;
using short_name = foo::bar::baz::long_name;
```

Или просто писать полностью:

```cpp
std::cout << "..." << std::endl;
```

Кому сильно интересно:
- [Дискуссия](https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice)

## 6. `C` синтаксис

Напоминаю что у нас практикум по `C++` и использовать голый синтаксис `C` без крайней необходимости запрещено.

## 7. Цикл `for`

Вот такая форма записи, считается наименее приемлемой, так как она очень детальная, и из-за этого высока вероятность ошибки:

```cpp
for (size_t i = 0; i < items.size(); i++) {
  // ...
}
```

Такая форма лучше:

```cpp
for (auto it = items.begin(); it != items.end(); it++) {
  // ...
}
```

Такая форма - верх совершенства:

```cpp
for (const auto& item : items) {
  // ...
}
```

## 8. Naming Convention

Я понимаю, что никто не удосужился почитать приведеные ссылки по [Guidlines, Coding Standards](/#guidlines-coding-standards). Поэтому давайте договоримся с вами о наших стандартах:

- Названия для `Struct`, `Class`, `Type`:
  - `CamelCase`
    - Пример:
      ```cpp
      struct SomeStruct {};
      class SomeClass {};
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
  - Начинаются на `k`
    - Пример:
      ```cpp
      constexpr int kMonthsCount = 12;
      ```

## 9. Аргументы Окружения

Если вы не используете аргументы окружения, зачем передаете их в `main`? Старайтесь всегда избегать ненужного кода. Чем больше кода - тем выше вероятность ошибки.

Плохо:
```cpp
int main(int argc, char* argv[]) { return 0; }
```

Хорошо:
```cpp
int main() { return 0; }
```

## 10. Последовательность Секций Видимости в Классах

Больше всего распространена такая последовательность: `public -> protected -> private`.
Каждая секция должна встречаться только 1 раз.

Плохо:
```cpp
class SomeClass {
 private:
  //
 public:
  // ...
 protected:
  // ...
 public:
  // ...
 private:
  // ...
}
```

Хорошо:
```cpp
class SomeClass {
 public:
  // ...
 protected:
  // ...
 private:
  // ...
}
```

## 11. Not `const` variables

Часто у вас в коде встречаются переменные, которые не изменяются, но при этом не помечены как `const`. Лучше просто всегда, когда создаете локальную переменную, помечайте её `const`, а если возникнет необходжимость изменить её, то `const` можно будет убрать.

Плохо:
```cpp
{
  int var = 32;
  // var is not changing ...
}
```

Хорошо:
```cpp
{
  const int var = 32;
  // var is not changing ...
}
```

## 12. Uninitialised Variables

Старайтесь никогда не оставлять неинициализхированные перменные, особенно если они теряют `const` из-за этого.

Плохо:
```cpp
int var;
if (bla) {
  var = 0;
}
else if (bla_bla) {
  var = 1;
}
else {
  var = 3;
}
```

Хорошо:
```cpp
const int var = ([]() {
  if (bla) {
    return 0;
  }
  else if (bla_bla) {
    return 1;
  }
  else {
    return 3;
  }
})();
```

## 13. Зона Видимости Переменных

Если есть возможность, переменную всегда стоит объявлять в локальной зоне видимости.

Плохо:
```cpp
int can_be_nil = get_value();
if (can_be_nil) {
  // `can_be_nil` is used here ...
}
// `can_be_nil` is still accessible here ...
```

Хорошо:
```cpp
if (int can_be_nil = get_value()) {
  // `can_be_nil` is used here ...
}
// `can_be_nil` is not accessible here ...
```

## 14. `unsigned` Types

В целом, старайтесь избегать `unsigned`, так как при конвертации между `signed` и `unsigned` вас могут подстерегать неприятности.

- [CppGuidline](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-mix)

## 15. `int` Instead of `size_t`

Контейнеры используют `size_t` для хранения своего размера и для обращения к элементам по индексу. Поэтому, если работаете с коллекциями, по возможности используйте `size_t` вместо `int`.

Плохо:
```cpp
const int size = vector.size();
for (int i = 0; i < size; i++) {
  vector[i] = get_val(i);
}
```

Хорошо:
```cpp
const size_t size = vector.size();
for (size_t i = 0; i < size; i++) {
  vector[i] = get_val(i);
}
```
