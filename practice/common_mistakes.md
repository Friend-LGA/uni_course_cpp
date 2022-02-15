# Common Mistakes

# Неверное название бранчей (`branch`)

Повторяю:
- Формат названий бранчей следующий:
  - `surname_name/task_number`
- Пример:
  - `lutkov_grigorii/task_01`

# Неверная иерархия/название директорий

Повторяю:
- Формат следующий:
  - `/surname_name/*`
- Пример:
  - `/lutkov_grigorii/*`

# Добавление в `Pull Request` неотносящихся изменений

К примеру, при добавлении файлов первой задачи, вы, зачем-то, удаляете файлы других студентов из репозитория :))

`Pull Request` представляет собой ваш `branch`, который, в свою очередь, представляет собой логически завершенный блок работы, включающий в себя только те изменения, которые необходимы для реализации поставленной задачи.

Вернемся к примеру выше: для реализации первой задачи, необходимости удалять чужие файлы из репозитория нет.

# No Newline at End of File

У текстовых фалов есть определенный формат, и, следуя этому формату, заканчиваться они должны символом новой строки. Это необходимо чтобы правильно определять количество строк в файле.

Кому сильно интересно:
- [Дискуссия 1](https://stackoverflow.com/questions/5813311/whats-the-significance-of-the-no-newline-at-end-of-file-log)
- [Дискуссия 2](https://unix.stackexchange.com/questions/18743/whats-the-point-in-adding-a-new-line-to-the-end-of-a-file)

# Short Names

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

# Наименование различных сущностей

1. Если это объект, например класс или структура, то он должен быть назван как какая-то сущность, например `генератор графа`:
    - `class GraphGenerator;`
    - Если этот объект находится внутри файла, то файл, соответственно, будет назван:
      - `graph_generator.hpp`
1. Если это функция, то она должна быть названа как действие, например `генерировать граф`:
    - `Graph generate_graph();`
1. Если это метод класса, то он может быть как действием, так и названием объекта, который он возвращает:
    - `graph.add_vertex(); // добавить вершину`
    - `graph.vertices(); // вернуть все вершины`
1. Если это набор определенной логики, то задайте себе вопрос: "Что это?" - `генерация`:
    - `namespace graph_generation {}`
    - `graph_generation.hpp`

# Названия переменных

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

# Обход коллекций

Коллекция, например `vector` - это набор однотипных сущностей, например `Vertex`.
Когда их много - это `vertices`, когда она одна - это `vertex`.

В вашем понимании зачастую это не так:

```cpp
auto vertices = std::vector<Vertex>();
// fill vertices
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
// fill vertices
for (const auto& vertex : vertices) {
  // some logic ...
  vertex.add_edge();
  // some more interesting reading ...
}
```

`vertex.add_edge();` - все прозрачно и понятно, никакого лишнего расхода мозговой активности.

# Подмена понятий

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

  void has_edge(EdgeId id) const {
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

  void has_edge(EdgeId id) const {
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

# `using namespace`

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

# Unnecessary Main Arguments

Если вы не передаете в `main` никаких аргументов, то и не стоит усложнять свой код.

Плохо:
```cpp
int main(int argc, char* argv[]) { return 0; }
```

Хорошо:
```cpp
int main() { return 0; }
```

# Member Initializer List

Когда вы инициализируете члены класса таким образом:

```cpp
class SomeClass {
 public:
  int a = 0;
  const std::string s;

  SomeClass(int init_a, const std::string& init_s) {
    a = init_a;
    s = init_s; // ERROR
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

# `for` Loop

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

Ещё лучше:

```cpp
for (auto it = items.cbegin(); it != items.cend(); it++) {
  // ...
}
```

Верх совершенства:

```cpp
for (const auto& item : items) {
  // ...
}
```

# `push` vs `emplace`

Для большинства коллекций реализован метод `emplace`, который существует для того, чтобы создавать новый элемент при добавлении.
Повторяю, не добавлять уже существующий элемент в коллекцию, а конструировать внутри себя новый.
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

# Последовательность Секций Видимости в Классах

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

# Not `const` Variables

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

# Immutability of function arguments

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

# Uninitialised Variables

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

# Зона Видимости Переменных

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

# `unsigned` Types

В целом, старайтесь избегать `unsigned`, так как при конвертации между `signed` и `unsigned` вас могут подстерегать неприятности.

- [CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-mix)

# `int` vs `size_t`

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

# `const` vs `constexpr`

`const` сигнализирует компилятору, что данная переменная не должна изменяться в ходе выполнения программы, и, соотвественно, он выдаст ошибку, если вы попытаетесь её изменить.

`constexp` в свою очередь, говорит компилятору, что данную переменную можно рассчитать на этапе компиляции, и вместо самой переменной, подставить в код непосредственно её значение.

Используйте `const` для локальных переменных и аргументов в функциях.
Используйте `constexpr` для глобальных констант.

# Unnecessary Big Types

По-умолчанию, всегда используйте `int` и `float`. Это стандартные фундаментальные типы для целых и дробных чисел соответственно.
Используйте `long`, если размера `int` вам не хватает.
Используйте `double`, если размера `float` вам не хватает.
Не нужно впустую тратить ресурсы.

Кому сильно интересно:
- [Дискуссия](https://stackoverflow.com/questions/1074474/should-i-use-double-or-float)

# Нарушение Зоны Ответственности (Single-Responcibility)

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

# Huge Functions

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

# Complex and/or Many Constructors

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

# `const` Methods Overriding

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

# `const` Class Members

Если данные в объекте при жизни не меняются - имеет смысл делать их `const`, например:

```cpp
class Vertex {
  const int id = 0;
  explicit Vertex(int init_id) : id(init_id) {}
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
