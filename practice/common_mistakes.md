# Common Mistakes

## Incorrect Branch Naming
### Неверное название бранчей (`branch`)

Повторяю:
- Формат названий бранчей следующий:
  - `surname_name/task_number`
- Пример:
  - `lutkov_grigorii/task_01`

## Incorrect File Hierarchy
### Неверная иерархия файлов

Повторяю:
- Формат следующий:
  - `/surname_name/*`
- Пример:
  - `/lutkov_grigorii/*`

## Unrelated Changes Inside `Pull Request`
### Добавление в `Pull Request` неотносящихся изменений

К примеру, при добавлении файлов первой задачи, вы, зачем-то, удаляете файлы других студентов из репозитория :))

`Pull Request` представляет собой ваш `branch`, который, в свою очередь, представляет собой логически завершенный блок работы, включающий в себя только те изменения, которые необходимы для реализации поставленной задачи.

Вернемся к примеру выше: для реализации первой задачи, необходимости удалять чужие файлы из репозитория нет.

## No Newline at End of File
### Отсутвие символа новой строки в конце файла

У текстовых фалов есть определенный формат, и, следуя этому формату, заканчиваться они должны символом новой строки. Это необходимо чтобы правильно определять количество строк в файле.

Кому сильно интересно:
- [Дискуссия 1](https://stackoverflow.com/questions/5813311/whats-the-significance-of-the-no-newline-at-end-of-file-log)
- [Дискуссия 2](https://unix.stackexchange.com/questions/18743/whats-the-point-in-adding-a-new-line-to-the-end-of-a-file)

## Using of `using namespace`
### Использование `using namespace`

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

## Unnecessary `main()` Arguments
### Ненужные аргументы в `main()`

Если вы не передаете в `main` никаких аргументов, то и не стоит усложнять свой код.

Плохо:
```cpp
int main(int argc, char* argv[]) { return 0; }
```

Хорошо:
```cpp
int main() { return 0; }
```

## Short Names
### Короткие названия

Мы с вами пытаемся писать не шифр, который необходимо декодировать, и не машинный код.
Стремиться называть переменные одной, двумя, тремя бувами - плохая идея.
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

## Naming of Different Entities
### Наименование различных сущностей

1. Если это объект, например класс или структура, то он должен быть назван как какая-то сущность, например `генератор графа`:
    - `class GraphGenerator;`
    - Если этот объект находится внутри файла, то файл, соответственно, будет назван:
      - `graph_generator.hpp`
1. Если это функция, то она должна быть названа как действие, например `генерировать граф`:
    - `Graph generate_graph();`
1. Если это метод класса, то он может быть как действием, так и названием объекта, который он возвращает:
    - `graph.add_vertex(); // добавить вершину`
    - `graph.vertices(); // вершины графа`
1. Если это набор определенной логики, то задайте себе вопрос: "Что это?" - `генерация`:
    - `namespace graph_generation {}`
    - `graph_generation.hpp`

## Naming of Variables
### Наименование переменных

1. Если это единственный объект, то он, соотвественно, должен называться в единственном числе:
    - ```cpp
      const auto vertex = Vertex();
      const auto edge = Edge();
      ```
2. Если это коллекция объектов - значит множественое число:
    - ```cpp
      const auto vertices = std::vector<Vertex>();
      const auto edges = std::vector<Edge>();
      ```

## Misleading Naming
### Подмена понятий

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

  bool has_edge(EdgeId edge) const {
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

  bool has_edge(EdgeId edge) const {
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

Будьте проще, не усложняйте. Видите `Graph` - назовите его `graph`. Видите `VertexId` - назовите его `vertex_id`. Не нужно никакой криптографии, лишних сокращений, подмены понятий.

```cpp
struct Vertex {
  std::vector<EdgeId> edge_ids;

  bool has_edge(EdgeId id) const {
    for (const auto edge_id : edge_ids) {
      if (id == edge_id) {
        return true;
      }
    }
    return false;
  }
};

class Graph {
  std::vector<Edge> edges;

  bool has_edge(EdgeId id) const {
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

## `Struct` vs `Class`
### `Struct` или `Class`

`Struct` и `Class` взаимозаменяемые. Единственное их отличие в том,
что по-умолчанию все аттрибуты класса `private`, а все аттрибуты структуры `public`.

Для простых объектов, которые только хранят данные и не имеют сложной логики, принято использовать `Struct`.
Для более сложных объектов, которые не только хранят данные, но и реализуют логику, лучше использовать `Class`.

## `explicit` Keyword
### `explicit` ключевое слово

`explicit` ключевое слово, использумое для запрета автоматического (`implicit`) приведения типов при создании нового экземпляра объекта.
`implicit` конвертация опасна, так как скрывает от пользователя то что происходит на самом деле,
создает неочевидное поведение программы, что, потенциально, может привести к ошибкам.

Плохо:
```cpp
struct Vertex {
 public:
  Vertex(int id) : id_(id) {}
 private:
  int id_ = 0;
}

// `int` автоматически (`implicit`) конвертируется в `Vertex`
const Vertex vertex = 5;
```

Хорошо:
```cpp
struct Vertex {
 public:
  explicit Vertex(int id) : id_(id) {}
 private:
  int id_ = 0;
}

// Однозначное (`explicit`) создание объекта класса `Vertex`
const Vertex vertex = Vertex(5);
```

`explicit` нужно указывать только для конструкторов с 1 аргументом.
В остальных случаях `implicit` конвертация невозможна, а значит и дополнительно указывать `explicit` необходимости нет.

Плохо:
```cpp
struct Edge {
 public:
  // Излишнее указание `explicit`.
  // Аргументов 3, больше 1, а значит `explicit` не нужен.
  explicit Edge(int id, int from_vertex_id, int to_vertex_id) {}
}
```

Хорошо:
```cpp
struct Edge {
 public:
  Edge(int id, int from_vertex_id, int to_vertex_id) {}
}
```

## `const` vs `constexpr`
### `const` или `constexpr`

`const` сигнализирует компилятору, что данная переменная не должна изменяться в ходе выполнения программы, и, соотвественно, он выдаст ошибку, если вы попытаетесь её изменить.

`constexp` в свою очередь, говорит компилятору, что данную переменную (или функцию) можно рассчитать на этапе компиляции, и вместо самой переменной, подставить в код непосредственно её значение.

Используйте `const` для локальных переменных и аргументов в функциях.
Используйте `constexpr` для глобальных констант.

## Member Initializer List
### Список инициализации

Когда вы инициализируете члены класса таким образом:

```cpp
class SomeClass {
 public:
  SomeClass(int init_a, const std::string& init_s) {
    a = init_a;
    s = init_s; // ERROR
    // ... some other logic ...
  }

  int a = 0;
  const std::string s;
}
```

Происходит следующее:
1. Начинается инициализация объекта `SomeClass`.
2. Происходит инициализация всех переменных этого класса:
    - `a = 0`, default value.
    - `s = ""`, default value.
3. Вызывается тело конструктора:
    - `a = init_a`, изменяем значение `a`.
    - `s = init_s`, пытаемся изменить константу `s`.
4. Заканчивается инициализация объекта `SomeClass`.

Какие проблемы мы здесь наблюдаем?
1. Переменной `a` присваивается значение 2 раза:
    1. Инициализируем в значение по-умолчанию `0`.
    2. Присваиваем новое значение `init_a`.
2. Ошибка при изменении значения переменной `s`
    1. Инициализируем в значение по-умолчанию `""`.
    2. Пытаемся присвоить новое значение, но так как переменная `const`, получаем ошибку.

Чтобы избежать данных проблем, нужно использовать `Member Initializer List`:

```cpp
class SomeClass {
 public:
  int a = 0;
  const std::string s;

  SomeClass(int init_a, const std::string& init_s) : a(init_a), s(init_s) {
    // ... some other logic ...
  }
}
```

## Order of Ownership Sectors
### Последовательность Секторов Видимости

Стоит придерживаться такой последовательности: `public -> protected -> private`.
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

## Mutability of Variables
### Мутабельность переменных

Часто у вас в коде встречаются переменные, которые не изменяются, но при этом не помечены как `const`.
Всегда, когда создаете локальную переменную, помечайте её `const`, и, если возникнет необходимость изменить её, `const` можно будет убрать.

Плохо:
```cpp
int var = 32;
// ... var is not changing ...

for (auto vertex_id : vertex_ids) {
  // ... vertex_id is not changing ...
}
```

Хорошо:
```cpp
const int var = 32;
// ... var is not changing ...

for (const auto vertex_id : vertex_ids) {
  // ... vertex_id is not changing ...
}
```

## Mutability of Function Arguments
### Мутабельность аргументов функции

Когда вы передаете аргументы в функцию, следуйте следующим правилам:
- Если это фундаментальный тип - передавать по значению:
  - `void function(int arg);`
- Если это НЕ фундаментальный тип - передавайте по `const` ссылке:
  - `void function(const std::vector& arg);`
  - `void function(const MyClass& arg);`
- Если вы планируете изменять переданный аргумент, то, возможно, это должен быть не аргумент, а возвращаемое значение:
  - Плохо:
    - `int functrion(bool& is_success);`
  - Хорошо:
    - `std::pair<int, bool> function();`

## Mutability of Function Return Value
### Мутабельность возвращаемого значения из функции

Когда вы возвращаете значение из функции, следуйте следующим правилам:
- Если возвращаете по значению, то без `const`, так как это копия данных и вам не важно, меняется ли данная копия дальше по коду или нет.
Это вне вашей зоны ответственности решать, должны ли эти данные быть изменяемыми или нет.
  - `int sum(int a, int b);`
- Если возвращаете по ссылке, то по возможности всегда возвращайте `const` ссылку.
Это предотвратит возможность изменения ваших внутренних данных извне.
  - `const std::vector<int>& vertices();`
- Возвращайте по изменяемой ссылке только в том случае, когда уверены, что данные должны быть изменяемыми, и это заложено в вашем дизайне интерфейса.
  - `Vertex& get_vertex(int id);`

## Mutability of Member Methods
### Мутабельность методов класса

Методы класса можно разделить на 2 вида:
1) Изменяющие объект, которому они принадлежат
2) Неизменяющие объект, которому они принадлежат

Те методы, которые не изменяют объект, которому они принадлежат, должны быть обязательно помечены как `const`.

```cpp
class Graph {
  // `non-const` метод, так как он добавляет новую вершину и изменяет `Graph`
  void add_vertex();

  // `const` метод, так как оне не изменяет `Graph`, а просто возвращает список вершин
  const std::vector<int>& vertices() const;

  // На первый взгляд выглядит что данный метод тоже `const`, так как он не
  // изменяет `Graph`, а просто возвращает вершину. Но на самом деле это не так,
  // обратите внимание, что он возвращает `non-const` ссылку на вершину,
  // а это значит, что потенциально данные могут быть изменены
  Vertex& get_vertex(int id);
};
```

Если метод не помечен как `const`, то он не может быть вызван на `const` объекте.

```cpp
auto graph = Graph();
const auto const_graph = Graph();

{
  // Оба метода можно вызвать, так как `graph` не `const`
  const auto& vertices1 = graph.vertices();
  graph.add_vertex();
}

{
  // Можно вызвать, так как и `graph` и `vertices()` оба `const`
  const auto& vertices2 = const_graph.vertices();

  // ERROR, нельзя вызвать `non-const` метод на `const` объекте
  const_graph.add_vertex();
}
```

## Complex and/or Many Constructors
### Сложные и/или много конструкторов

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

## `push` vs `emplace`
### `push` или `emplace`

Для большинства коллекций реализован метод `emplace`, который существует для того, чтобы создавать новый элемент при добавлении.
Повторяю, не добавлять уже существующий элемент в коллекцию, а конструировать внутри себя новый.
Этот метод обычно принимает списк аргументов, аналогичный конструктору объекта, который необходимо добавить.

В данном примере вы сначала создаете новый объект самостоятельно, и после этого копируете его в вектор:

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
1. Избегаем лишнего копирования.

## `const` Class Members
### `const` члены класса

Если данные в объекте при жизни не меняются - имеет смысл делать их `const`, например:

```cpp
class Vertex {
  explicit Vertex(int init_id) : id(init_id) {}
  const int id = 0;
}
```

Но, в будущем, вы можете столкнуться с проблемой, что такие объекты нельзя копировать, например:

```cpp
const auto vertex1 = Vertex(0);
const auto vertex2 = vertex1; // ERROR, can't assign `id`
```

Проблема в том, что при копировании, сначала создается пустой объект, а потом его внутреним переменным присваиваются новые значения. Тут и возникает проблема, что нельзя изменить константное поле:

```cpp
const auto vertex2 = vertex1;
// 1. vertex2 = Vertex();
// 2. vertex2.id = vertex1.id
```

Чтобы избежать этой проблемы, приходится убирать `const` и ограничивать доступ к данным:

```cpp
class Vertex {
 public:
  int id() const { return id_; }

 private:
  int id_ = 0;
}
```

Теперь копирование будет работать.

## Single-Responsibility Principle
### Принцип единственной ответственности

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

## Collections Traversal
### Обход коллекций

Использовать индекс считается наихудшим вариантом, так как это очень детальная запись,
и из-за этого высока вероятность ошибки:

```cpp
for (size_t i = 0; i < items.size(); i++) {
  // ...
}
```

Лучше использовать итератор:

```cpp
for (auto it = items.begin(); it != items.end(); it++) {
  // ...
}
```

Ещё лучше использовать `const` итератор:

```cpp
for (auto it = items.cbegin(); it != items.cend(); it++) {
  // ...
}
```

Верх совершенства - использовать напрямую объекты коллекции:

```cpp
for (const auto& item : items) {
  // ...
}
```

## Collections Traversal Naming
### Наименование при обходе коллекций

1\) Для обхода по индексу, индекс обычно наызвают `i`, `k`, `j`

2\) Для обхода с итератором, итератор обычно называют `it`

3\) Рассмотрим обход по элементам коллекции.

Коллекция, например `vector` - это набор однотипных сущностей, например `Vertex`.
Когда их много - это `vertices`, когда она одна - это `vertex`.

```cpp
const auto vertices = std::vector<Vertex>();
for (const auto& vertex : vertices) {
  // ... some logic ...
}

const auto edge = std::vector<Edge>();
for (const auto& edge : edges) {
  // ... some logic ...
}

const auto vertex_ids = std::vector<VertexId>();
for (const auto vertex_id : vertex_ids) {
  // ... some logic ...
}

const auto edge_ids = std::vector<EdgeId>();
for (const auto edge_id : edge_ids) {
  // ... some logic ...
}
```

## Huge Functions
### Большие функции

В продолжение разговора о `Single-Responcibility`. Этот принцип так же относится и к функциям.
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

## `unsigned` Data Types
### `unsigned` типы данных

В целом, старайтесь избегать `unsigned`, так как при конвертации между `signed` и `unsigned` вас могут подстерегать неприятности.
Математические операции с `unsigned` могут вернуть непредсказуемый результат, если быть невнимательным.

- [CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-mix)

## `int` vs `size_t`
### `int` или `size_t`

Контейнеры используют `size_t` для хранения своего размера и для обращения к элементам по индексу.
Поэтому, если работаете с коллекциями, используйте `size_t` вместо `int`, там где это осмысленно.

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

## Unnecessary Big Data Types
### Использование больших типов данных без необходимости

По-умолчанию, всегда используйте `int` и `float`. Это стандартные фундаментальные типы для целых и дробных чисел соответственно.
Используйте `long`, если размера `int` вам не хватает.
Используйте `double`, если размера `float` вам не хватает.
Не нужно впустую тратить ресурсы.

Кому сильно интересно:
- [Дискуссия](https://stackoverflow.com/questions/1074474/should-i-use-double-or-float)

## Free Functions
### Cвободные функции

Если функция использует только переданные в неё аргументы, то она является свободной функцией и не должна быть частью интерфейса класса.
Такие функции чаще всего должны находиться в приватном неймспейсе в `cpp` файле.

Плохо:
- `GraphGenerator.hpp`
  ```cpp
  class GraphGenerator {
  public:
    Graph generate() const;
  private:
    int generate_random_int(int limit) const;
  };
  ```
- `GraphGenerator.cpp`
  ```cpp
  Graph GraphGenerator::generate() const {
    // ... some logic ...
    int random_int = generate_random_int();
    // ... some logic ...
  }

  int GraphGenerator::generate_random_int(int limit) {
    // ... some logic ...
  }
  ```

Хорошо:
- `GraphGenerator.hpp`
  ```cpp
  class GraphGenerator {
  public:
    Graph generate() const;
  };
  ```
- `GraphGenerator.cpp`
  ```cpp
  namespace {
    int generate_random_int(int limit) {
      // ... some logic ...
    }
  } // namespace

  Graph GraphGenerator::generate() const {
    // ... some logic ...
    int random_int = generate_random_int();
    // ... some logic ...
  }
  ```

## Uninitialised Variables
### Не инициализированные переменные

Старайтесь никогда не оставлять неинициализхированные перменные, особенно если они теряют `const` из-за этого.

Плохо:
```cpp
int var;
// `var` is not initialized and is not `const`
if (bla) {
  var = 0;
}
else if (bla_bla) {
  var = 1;
}
else {
  var = 3;
}

int index; // value is unpredictable
get_object(index); // what is value of `index`?

struct Point {
  int x; // value is unpredictable
  int y; // value is unpredictable
};

Point point; // value is unpredictable
set_point(point); // what are values of `point.x` and `point.y`?
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
// `var` is initialized and `const`

const int var2 = calculate_var();
// `var2` is initialized and `const`

const int index = 0; // default value
get_object(index); // `index` has value

struct Point {
  int x = 0; // default value
  int y = 0; // default value
};

const auto point = Point(); // default value
set_point(point); // `point.x` and `point.y` have values
```

## Variable Visibility Scope
### Зона Видимости Переменных

Если есть возможность, переменную всегда стоит объявлять в локальной зоне видимости.

Плохо:
```cpp
const int can_be_nil = get_value();
if (can_be_nil) {
  // `can_be_nil` is used here ...
}
// `can_be_nil` is still accessible here ...
```

Хорошо:
```cpp
if (const int can_be_nil = get_value()) {
  // `can_be_nil` is used here ...
}
// `can_be_nil` is not accessible here ...
```

## `const` Methods Overriding
### Перегрузка `const` методов

Бывает такое, что вам нужно иметь 2 версии одного метода, `const` и `non-const`.

Пример `const`:

```cpp
class Graph {
  const Vertex& get_vertex(int id) const;
}

void success() {
  const auto graph = generate_graph();
  const auto& vertex = graph.get_vertex(0);
  vertex.get_data();
}

void fail() {
  auto graph = generate_graph();
  const auto& vertex = graph.get_vertex(0);
  vertex.update(); // ERROR, can't modify const vertex
}
```

Пример `non-const`:

```cpp
class Graph {
  Vertex& get_vertex(int id);
}

void success() {
  auto graph = generate_graph();
  auto& vertex = graph.get_vertex(0);
  vertex.update();
}

void fail() {
  const auto graph = generate_graph();
  const auto& vertex = graph.get_vertex(0); // ERROR, can't call non-const method
  vertex.get_data();
}
```

Как решить ситуацию, когда нам нужны обе версии одного метода?
Соответственно нам нужно использовать `override` этого метода:

```cpp
class Graph {
  const Vertex& get_vertex(int id) const;
  Vertex& get_vertex(int id);
}
```

Теперь мы можем использовать этот метод и на `const`, и на `non-const` объектах `Graph`.

Последний момент: чтобы избежать дублирования кода внутри этих методов, мы можем вызвать один метод внутри другого:

```cpp
class Graph {
  const Vertex& get_vertex(int id) const {
    // ... some complix logic to get the vertex ...
  }

  Vertex& get_vertex(int id) {
    // Делаем `const` ссылку на себя, чтобы была возможность вызывать `const` методы.
    const auto& const_this = *this;
    // Убираем `const` модификтор
    return const_cast<Vertex&>(const_this.get_vertex(id));
  }
}
```

Не самая красивая запись, но, в целом, это общепринятый подход в данном случае.

Реальные примеры:
- [std::vector::at](https://en.cppreference.com/w/cpp/container/vector/at)
- [std::map::find](https://en.cppreference.com/w/cpp/container/map/find)
