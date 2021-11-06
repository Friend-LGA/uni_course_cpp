# Практика

# Basic Idea

1. Задача практикума - написать игру, которая будет играть сама в себя. То, что мы должны получить:
    - Игровое поле, представляющее собой граф.
    - В начале этого поля находится рыцарь.
    - В конце этого поля находится принцесса.
    - Переход между клетками игрового поля (вершинами графа) занимает определенное время.
    - При переходе есть вероятность что рыцарь наткнется на противника (дракон, виверна, тролль, и т.д.) и завяжется схватка.
    - У рыцаря и у его противников есть характеристики (здоровье, выносливость, атака, и т.д.).
    - Нужно найти кратчайший и наиболее безопасный пути к принцессе, а так же подобрать оптимальные характеристики для рыцаря.
1. У нас есть общий репозиторий, к которому у вас у всех есть/будет доступ. Каждая задача представляет собой `Pull Request` в этот репозиторий.
   Когда `Pull Request` прошел все проверки, одобрен мной и залит вами в `master`, тогда задача считается выполненной.
1. Каждая задача рассчитана на определенное время выполнения и количество баллов. За каждую неделю задержки отнимается по 5 баллов. В зависимости от количества недостающих баллов в конце семестра, нужно будет выполнить допольнительные задания.

# Plan

- [Initial Setup](initial_setup)
- Неделя 1. [Hello World!](task_01)
- Неделя 2. [Graph Generation](task_02)
- Неделя 3. [JSON Representation](task_03)
- Неделя 4. [Graph Development](task_04)
  - Vertices and Edges Probabilities
- Неделя 5. [Multiple Graphs and Logger](task_05)
  - Multiple Graphs Generation (Sequentially)
  - Add Logger
- Неделя 6. [Shortest Path Algorith](./)
  - Add Edge Durations
  - Single Pair (Sequential Algorithm)
- Неделя 7. [Shortest Path Algorith](./)
  - Single Pair (Parallel Algorithm)
- Неделя 8. [Graph Development](./)
  - Add Params, Fights and Blessings
  - Multiple Graphs Generation (Parallel)
- Неделя 9. [Shortest Path Algorith](./)
  - Multiple Pair (Parallel Algorithm)
- Неделя 10. [Graph Development](./)
  - Adjustable Params (Parallel)
  - Add Enemies and Blessings
- Неделя 11. [Graph Development](./)
  - Multiple Players (Parallel)
  - Add Enemies and Blessings
- ...

План временный, для общего понимания. Задачи готовятся по мере возможности.

# Rules

1. Версия `C++`, которую мы будем использовать - `C++ 17`. Компилироваться ваши программы будут с помощью компилятора `clang` с флагом `-Werror`, это значит что все предупреждения компилятора будут считаться ошибками.
1. У нас с вами практикум по `C++`, поэтому использовать голый синтаксис `C` без крайней необходимости запрещено. Подробнее рассмотрено в секции [`C Style vs C++ Style`](#c-style-vs-c-style) ниже.
1. Использовать сторонние библиотеки также запрещено. Пользуйтесь теми инструментами, которые дает вам язык.
1. Чтобы упростить вам жизнь и избежать кучу головной боли, использовать `template` без крайней нужды тоже запрещено.
1. По правилам хорошего тона, когда много людей работают над одним репозиторием, используется `linter` для контроля форматирования текста,
   чтобы весь код выглядел единообразно и всем его было удобно читать. В нашем случае, мы будем использовать `clang-format`. Подробнее описано в секции [`Workflow`](#workflow) ниже.

# Workflow

1. Сделать `fork` репозитория, куда вы будете загружать выполненные задачи (ссылку спросить у меня).
    - [Docs: About Forks](https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/about-forks)
    - [Docs: Fork a Repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo)
1. Если у вас уже есть форк, то нужно поддерживать его в актуальном состоянии, и периодически подтягивать изменения из родителького репозитория:
    - [Docs: Syncing a Fork](https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/syncing-a-fork)
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
1. Когда задача готова, вы должны прогнать ваши файлы через `linter`:
    - Мы будем используем `clang-format`, инструкция по установки описана в [`Initial Setup`](initial_setup).
    - Файл конфигурации уже лежит в корне общего репозитория и выглядит так: [`.clang-format`](.clang-format).
      - Единственная и самая главная настройка, которую мы будем использовать:
        - `BasedOnStyle: Chromium` - означает, что за основу взято форматирование, принятое в команде, которая пишет `Chromium`.
    - Все, что вам нужно сделать, это:
      - Перейти в директорию с вашей задачей.
      - Выполнить форматирование `.hpp` и `.cpp` файлов:
        - `clang-format -i -style=Chromium *.cpp`
        - `clang-format -i -style=Chromium *.hpp`
          - `-i` - означает `Inplace`, то есть `linter` будет обновлять файлы при форматировании.
          - `-style=Chromium` - базовый стиль форматирования.
          - `*.cpp` - путь и маска, по которому искать файлы.
1. После этого создаете `Pull Request` со следующими параметрами:
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
1. На `Pull Request` автоматически выполняются проверки (`GitHub Actions`):
    - `clang` компилирует ваши файлы и выполняет программу.
    - `linter` проверяет соответствие ваших файлов ожидаемому формату.
    - Вы можете следить за выполнением этих `jobs` на странице `Pull Request`.
    - Если все `ок`, `Pull Request` помечается зеленой галочкой.
    - Если где-то произошла ошибка, `Pull Request` помечается красным крестиком.
1. Если проверки прошли удачно, я провожу код ревью и дальнешее развитие может быть:
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

# Updating Your Fork

Если у вас заблокирован `merge` для вашего `Pull Request`, или есть другая необходимость получить свежие изменения из общего мастера, то нужно следовать следующей логике:

1. Обновить ваш форк
    - [Docs: Syncing a Fork](https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/syncing-a-fork)
1. Перейти в локальный master
    - `git checkout master`
1. Обновить локальный master
    - `git pull origin master`
1. Перейти в свою ветку
    - `git checkout name_of_my_branch`
1. Добавить в неё новые изменения из мастера
    - `git merge master`
    - Docs: [Git](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging), [Atlassian](https://www.atlassian.com/git/tutorials/using-branches/git-merge)
1. Обновить свой PR
    - `git push origin name_of_my_branch`

# Rollback Changes from Pull Request

Если у вас в `Pull Request` есть изменения файлов относительно `master`, которые вы хотите откатить, то можно выполнить следующие команды:
- `git checkout master -- file_path`
- `git checkout master -- directory_path`

Полностью логика выглядит так:
- Обновляетесь на свежий `master`
  - Читать выше, [Updating Your Fork](#updating-your-fork)
- Переходите в свой `branch`
  - `git switch your_branch`
  - или
  - `git checkout your_branch`
- Откатываете изменение для файлов:
  - `git checkout master -- file_path`
- Создаете `commit` с изменениями
  - `git add .`
  - `git commit -m "Commit Message"`
- Обновляете ваш `Pull Request`
  - `git push origin your_branch`

# Naming Convention

Я понимаю, что никто не удосужился почитать приведенные ссылки по [Guidlines, Coding Standards](/#guidlines-coding-standards). Поэтому давайте договоримся с вами о наших стандартах:

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
    ```
  - `C++`:
    ```cpp
    char c = 'a';
    int* p = static_cast<int*>(&c); // compilation error
    ```
- Asserts:
  - Не имеет аналога в `C++`, можно использовать `C`.
    ```cpp
    assert(some_condition() && "Description message");
    ```
- И т.д. и т.п.
- Ну вы поняли идею, правильно?

# Common Mistakes

## Неверное название бранчей (`branch`)

Повторяю:
- Формат названий бранчей следующий:
  - `name_surname/task_number`
- Пример:
  - `grigorii_lutkov/task_01`

## Неверная иерархия директорий

Повторяю:
- Формат иерархии директорий следующий:
  - `/task_dir_name/name_surname/*`
- Пример:
  - `/01_hello_world/grigorii_lutkov/*`

## Добавление в `Pull Request` неотносящихся изменений

К примеру, при добавлении файлов первой задачи, вы, зачем-то, удаляете файлы других студентов из репозитория :))

`Pull Request` представляет собой ваш `branch`, который, в свою очередь, представляет собой логически завершенный блок работы, включающий в себя только те изменения, которые необходимы для реализации поставленной задачи.

Вернемся к примеру выше: для реализации первой задачи, необходимости удалять чужие файлы из репозитория нет.

## No Newline at End of File

У текстовых фалов есть определенный формат, и, следуя этому формату, заканчиваться они должны символом новой строки. Это необходимо чтобы правильно определять количество строк в файле.

Кому сильно интересно:
- [Дискуссия 1](https://stackoverflow.com/questions/5813311/whats-the-significance-of-the-no-newline-at-end-of-file-log)
- [Дискуссия 2](https://unix.stackexchange.com/questions/18743/whats-the-point-in-adding-a-new-line-to-the-end-of-a-file)

## Short Names

Мы с вами пытаемся писать не шифр, который необходимо декодировать, и не машинный код.
Стремиться называть перменные одной, двумя, тремя бувами - плохая идея.
Такой код сложно читать, сложно понимать, сложно поддерживать, и легче допустить ошибку.
Пусть лучше переменная будет названа целым словом, но зато из названия сразу будет понятно для чего она предназначена.

Плохо:
```cpp
const auto v = Vertex();
const auto e = Edge();
const auto vec = std::vector<Vertex>(v);
const auto vec_e = std::vector<Edge>(e);
const auto g = Graph(vec, vec_e);
```

Хорошо:
```cpp
const auto vertex = Vertex();
const auto edge = Edge();
const auto vertices = std::vector<Vertex>(v);
const auto edges = std::vector<Edge>(e);
const auto graph = Graph(vertices, edges);
```

# Naming Logic

## Наименование различных сущностей

1. Если это объект, например класс или структура, то он должен быть назван как какая-то сущность, например `генератор графа`:
    - `class GraphGenerator;`
    - Если этот объект находится внутри файла, то файл, соответственно, будет назван:
      - `graph_generator.hpp`
1. Если это функция, то она должна быть названа как действие, например `генерировать граф`:
    - `Graph generate_graph();`
1. Если это набор определенной логики, то задайте себе вопрос: "Что это?" - `генерация`:
    - `namespace graph_generation {}`
    - `graph_generation.hpp`

## Названия переменных

1. Если это единственный объект, то он соотвественно должен называться в единственном числе:
    - ```cpp
      const auto vertex = Vertex();
      const auto edge = Edge();
      ```
2. Если это коллекция объектов, то это должно быть, соответственно, множественое число:
    - ```cpp
      const auto vertices = std::vector<Vertex>();
      const auto edges = std::vector<Edge>();
      ```

## Обход коллекций

Коллекция, например `vector` - это набор однотипных сущностей, например `Vertex`.
Когда их много - это `vertices`, когда она одна - это `vertex`.

В вашем понимании зачастую это не так:

```cpp
auto vertices = std::vector<Vertex>();
for (const auto& k : vertices) {
  // some logic ...
  k.add_edge();
  // some more interesting reading ...
}
```

К моменту, когда я дочитал до `k.add_edge();`, я уже 100 раз забыл кем является этот некий `k`, для меня такая переменная в первую очередь ассоциируется с Tommy Lee Jones.

Намного логичней будет назвать элемент коллекции, тем, чем он на самом деле и является:

```cpp
auto vertices = std::vector<Vertex>();
for (const auto& vertex : vertices) {
  // some logic ...
  vertex.add_edge();
  // some more interesting reading ...
}
```

`vertex.add_edge();` - все прозрачно и понятно, никакого лишнего расхода мозговой активности.

## Подмена понятий

Ещё один интересный пример. Предположим у вас есть следующие типы данных:
- `struct Vertex;`
- `struct Edge;`
- `using VertexId = int;`
- `using EdgeId = int;`

Когда вы читаете код, то ожидаете что:
- Переменная с названием `vertex` указывает на объект `Vertex`.
- Переменная с названием `edge` указывает на объект `Edge`.
- Переменная с названием `vertex_id` указывает на объект `VertexId`.
- Переменная с названием `edge_id` указывает на объект `EdgeId`.

Вы же перемешиваете все в одну кучу:

```cpp
struct Vertex {
  std::vector<EdgeId> edges;

  void has_edge(const EdgeId& edge) const {
    for (const auto& edg : edges) {
      if (edg == edge) {
        return true;
      }
    }
    return false;
  }
};

class Graph {
  std::vector<Edge> edges;

  void has_edge(const EdgeId& edge) const {
    for (const auto& edg : edges) {
      if (edg.id == edge) {
        return true;
      }
    }
    return false;
  }
};
```

Как вам кажется, такой код удобно читать и легко понимать? Кого вы пытаетесь запутать, самих себя?
Почему разные сущности называются одинаково, чтобы сократить 2 лишние буквы?
Функции, которые, на первый взгляд выглядят совершенно одинаково, на самом деле оперируют разными данными и имеют разную логику.
Но чтобы это понять, нужно внимательно вчитаться в код, и не полениться, сходить посмотреть как они все определены, какие типы данных имеют.
Зачем вы усложняете жизнь и себе, и тем, кто будет читать ваш код и работать с вами?

Самое основное правило: будьте проще, не усложняйте. Видите `Graph` - назовите его `graph`. Видите `VertexId` - назовите его `vertex_id`. Не нужно никакой криптографии, лишних сокращений, подмены понятий.

```cpp
struct Vertex {
  std::vector<EdgeId> edge_ids;

  void has_edge(const EdgeId& id) const {
    for (const auto& edge_id : edge_id) {
      if (id == edge_id) {
        return true;
      }
    }
    return false;
  }
};

class Graph {
  std::vector<Edge> edges;

  void has_edge(const EdgeId& id) const {
    for (const auto& edge : edges) {
      if (id == edge.id) {
        return true;
      }
    }
    return false;
  }
};
```

Как вам такой вариант? Проще? Понятней? Не нужно никуда ходить и ничего проверять, все очевидно из названий перменных.
Это то, к чему вы должны стремиться, ясный, легко читаемый код, а не закодированный шифр.

## `using namespace`

Использовать `using namespace` считается плохой практикой.
Вместе этого лучше использовать ограниченный `using`:

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

## Unnecessary Main Arguments

Если вы не передаете в `main` никаких аргументов, то и не стоит усложнять свой код.

Плохо:
```cpp
int main(int argc, char* argv[]) { return 0; }
```

Хорошо:
```cpp
int main() { return 0; }
```

## Member Initializer List

Когда вы инициализируете члены класса таким образом:

```cpp
class SomeClass {
 public:
  int a = 0;
  const std::string s;

  SomeClass(int _a, const std::string& _s) {
    a = _a;
    s = _s; // ERROR
    // ... some other logic ...
  }
}
```

Происходит следующее:
1. Начинается инициализация объекта `SomeClass`.
2. Происходит инициализация всех переменных этого класса:
    - `a = 0`, default value.
    - `s = ""`, default value.
3. Вызывается тело конструктора:
    - `a = _a`, изменяем значение `a`.
    - `s = _s`, пытаемся изменить константу `s`.
4. Заканчивается инициализация объекта `SomeClass`.

Какие проблемы мы здесь наблюдаем?
1. Переменной `a` присваивается значение 2 раза:
    1. Инициализируем в значение по-умолчанию `0`.
    2. Присваиваем новое значение `_a`.
2. Ошибка при изменении значения переменной `s`
    1. Инициализируем в значение по-умолчанию `""`.
    2. Пытаемся присвоить новое значение, но так как переменная `const`, получаем ошибку.

Чтобы избежать данных проблем, нужно использовать `Member Initializer List`:

```cpp
class SomeClass {
 public:
  int a = 0;
  const std::string s;

  SomeClass(int _a, const std::string& _s) : a(_a), s(_s) {
    // ... some other logic ...
  }
}
```

## `for` Loop

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

## `push` vs `emplace`

Для большинства коллекций реализован метод `emplace`, который существует для того, чтобы создавать новый элемент при добавлении.
Повторяю, не добавлять уже существующий элемент в коллекцию, а контруировать внутри себя новый.
Этот метод обычно принимает списк аргументов, аналогичный конструктору объекта, который необходимо добавить.

В данном примере вы сначала создаете новый объект самостоятельно, и после этого добавляете его в вектор:

```cpp
auto vector = std::vector<MyClass>();
const auto var = MyClass(arg1, arg2);
vector.push_back(var);
```

В данном примере вектор сам создает новый объект:

```cpp
auto vector = std::vector<MyClass>();
vector.emplace_back(arg1, arg2);
```

1. Меньше кода.
1. Нет лишней переменной.

## Последовательность Секций Видимости в Классах

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

## Not `const` Variables

Часто у вас в коде встречаются переменные, которые не изменяются, но при этом не помечены как `const`. Лучше просто всегда, когда создаете локальную переменную, помечайте её `const`, а если возникнет необходжимость изменить её, то `const` можно будет убрать.

Плохо:
```cpp
int var = 32;
// var is not changing ...
```

Хорошо:
```cpp
const int var = 32;
// var is not changing ...
```

## Immutability of function arguments

Когда вы передаете аргументы в функцию, следуйте следующим правилам:
- Если это фундаментальный тип - передавать по значению:
  - `void function(int arg);`
- Если это НЕ фундаментальный тип - передавайте по `const` ссылке:
  - `void function(const std::vector& arg);`
  - `void function(const MyClass& arg);`
- Если это кастомный пользовательский тип - передавайте по `const` ссылке, так как мы не можем знать наверняка что за ним скрывается:
  - ```cpp
    using VertexId = int;
    void function(const VertexId& id);
    ```
- Если вы планируете изменять переданный аргумент, то, возможно, это должен быть не аргумент, а возвращаемое значение:
  - Плохо:
    - `int functrion(bool& is_success);`
  - Хорошо:
    - `std::pair<int, bool> function();`

## Uninitialised Variables

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

## Зона Видимости Переменных

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

## `unsigned` Types

В целом, старайтесь избегать `unsigned`, так как при конвертации между `signed` и `unsigned` вас могут подстерегать неприятности.

- [CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-mix)

## `int` vs `size_t`

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

## `const` vs `constexpr`

`const` сигнализитирует компилятору, что данная переменная не должна изменяться в ходе выполнения программы, и, соотвественно, он выдаст ошибку, если вы попытаетесь её изменить.

`constexp` в свою очередь, говорит компилятору, что данную переменную можно рассчитать на этапе компиляции, и вместо самой переменной, подставить в код непосредственно её значение.

Используйте `const` для локальных переменных и аргументов в функциях.
Используйте `constexpt` для глобальных констант.

## Unnecessary Big Types

По-умолчанию, всегда используйте `int` и `float`? Это стандартные фундаментальные типы для целых и дробных чисел соответственно.
Используйте `long`, если размера `int` вам не хватает.
Используйте `double`, если размера `float` вам не хватает.
Не нужно впустую тратить ресурсы.

## Нарушение Зоны Ответственности (Single-Responcibility)

Часто встречается плохое понимание зоны отвественности объявляемой сущности, например класса `Graph`.

Давайте попробуем подумать о том, что из себя абстрактно представляет граф, и за что он отвечает:
- Он хранит вершины.
- Он хранит грани.
- Он знает отношение вершин и граней друг к другу.
- Он реализует логику работы с вершинами и гранями.

Теперь давайте попробуем подумать, за что граф не должен отвечать:
- За вывод данных в командную строку.
- За работу с файлами.
- За сложную генерацию самого себя.
- И т.д. и т.п.

Та логика, за которую он не в отвественности, должна быть реализована вне данного класса.

## Huge Functions

В продолжение разговора о `Single Responcibility`. Этот принцип так же относится и к функциям.
Одна функция, должна выполнять одно элементарное действие. Под словом `элементарное` я подразумеваю логику, которую невозможно, или сложно разбить на более мелкие кусочки.
Это сделает код легче для чтения и понимания, поможет прослеживать более четкую последовательность действий, изолировать куски кода друг от друга, упростит написание тестов.

Плохо:
```cpp
void process_graph() {
  // Creating Graph ...
  // Filling Graph with Data ...
  // Printing Graph ...
  // Writing Graph to File ...
  // Total 100500+ lines of code
}

int main() {
  process_graph();
  return 0;
}
```

Хорошо:
```cpp
void prepare_graph();
void print_graph();
void pring_vertex();
void print_edge();
void write_to_file();

int main() {
  prepare_graph();
  print_graph();
  write_to_file();
  return 0;
}
```

## Complex and/or Many Constructors

В продолжении темы про зону ответственности.

Сам объект `Graph` является валидным даже не имея вершин и граней, они не необходимы для его инициализации. Старайтесь упрощать, а не усложнять.

Писать 100500 вариаций конструктора тоже дорога к безумию. Как много вариантов конструктора можно придумать? Да практически бесконечное, давайте прикинем:
- Пустой
- С одной вершиной
- С одной гранью
- С одной гранью и 2умя вершинами
- С массивом вершин
- С массивом граней
- С массивом вершин и граней
- И т.д и т.п.

Поэтому, не надо захламлять ваш класс миллионом конструкторов, подумайте, какой из них является минимально необходимым. Если в ходе написания большого приложения, вы поймете, что у вас есть специфические требования по частой генерации объекта с похожими входными параметрами, даже в этом случае, вам скорее нужно будет написать фабрику, или, другими словами, генератор, чья ответственность как раз и будет тем, чтобы генерировать эти самые объекты.
