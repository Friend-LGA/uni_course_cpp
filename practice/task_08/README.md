# Задача 8

# Вынести интерфейсы классов

В мире `C++` интерфейсом называется абстрактный класс, содержащий только `public` секцию и только `pure virtual functions`.

- [Virtual Function](https://en.cppreference.com/w/cpp/language/virtual) -
функция, которая может быть перегружена (`overriden`) в наследуемом классе.
При вызове такой функции будет вызвана самая последняя перегруженная версия в цепочке наследования.
Для указания функции вуртуальной нужно использовать ключевое слово `virtual`.
  ```cpp
  class A {
    // Virtual Destructor
    virtual ~A {}

    // Virtual Function
    virtual void virtual_func() {
      std::cout << "A::virtual_func()" << std::endl;
    }
  };

  class B : public A {
    // notice `override` keyword
    void virtual_func() override {
      A::virtual_func(); // call to a parent class
      std::cout << "B::virtual_func()" << std::endl;
    }
  };
  ```
- [Pure Virtual Function](https://en.cppreference.com/w/cpp/language/abstract_class) -
виртуальная функция, которая не имеет реализации. Обязана быть перегруженной при наследовании.
Помечается специальной записью `= 0`.
  ```cpp
  class A {
    // Virtual Destructor
    virtual ~A {}

    // Pure Virtual Func
    virtual void virtual_func() = 0;
  };
  ```
- [Абстрактный класс](https://en.cppreference.com/w/cpp/language/abstract_class) -
класс, который имеет хотя бы одну `pure virtual function`.

Стоит обратить внимание на следующее:
- Если подразумевается наследование, то нужно обязательно добавлять виртуальный деструктор.
Это необходимо делать, чтобы при удалении были вызваны деструкторы всех классов в цепочке наследования.
- При перегрузке нужно указывать метод как `override`.
Технически это не обязательно, но практичеки рекомедуется указывать всегда для наглядности.
- Для того, чтобы вызвать метод из родительского класса используется такая запись: `ParentClass::method_name()`.
- Создать экземпляр абстрактного класса нельзя, можно только передать на него ссылку или указатель.

Интерфейсом является такой абстрактный класс, который включает в себя только публичный интерфейс реализуемого класса.

## Интерфейс или Наследование

Выделение интерфейса в отдельный абстрактный класс является по факту наследованием.
Но так как это абстрактный класс, который не включает в себя никаких лишних данных и логики,
это позволяет избежать возрастающей сложности наследования, а так же ускорить компиляцию,
так как в большинстве файлов можно инклудить легковесный интерфейс вместо полноценных тяжелых классов.

## Необходимые действия

1\) Вам нужно будет создать новую папку `interfaces` и поместить туда следующие интерфейсы:
- `interfaces/i_graph.hpp`
- `interfaces/i_vertex.hpp`
- `interfaces/i_edge.hpp`
- `interfaces/i_worker.hpp`

2\) Пример интерфейса:

`i_vertex.hpp`:
  ```cpp
  #pragma once

  namespace uni_course_cpp {

  using VertexId = int;

  struct IVertex {
  public:
    virtual ~IVertex() {};

    virtual VertexId id() const = 0;
  };

  }  // namespace uni_course_cpp
  ```

3\) Перенести псевдонимы и зависимые данные:
- `VertexId` -> `i_vertex.hpp`

  ```cpp
  namespace uni_course_cpp {
  using VertexId = int;
  class IVertex {...};
  } // namespace uni_course_cpp
  ```

- `EdgeId` -> `i_edge.hpp`<br>
  `Edge::Color` -> `EdgeColor` -> `i_edge.hpp`

  ```cpp
  namespace uni_course_cpp {
  using EdgeId = int;
  enum class EdgeColor { Grey, Green, Blue, Yellow, Red };
  class IEdge {...};
  } // namespace uni_course_cpp
  ```

- `Depth` -> `GraphDepth` -> `i_graph.hpp`

  ```cpp
  namespace uni_course_cpp {
  using GraphDepth = int;
  class IGraph {...};
  } // namespace uni_course_cpp
  ```

- `Vertex` -> `Graph(private)`<br>
  `Edge` -> `Graph(private)`

  ```cpp
  class Graph {
   private:
    struct Vertex {...};
    struct Edge {...};
  };
  ```

4\) Отнаследовать реализуемые классы от их интерфейсов.

Пример `graph.hpp`:
```cpp
class Graph : public IGraph {
 private:
  struct Vertex : public IVertex {
   public:
    explicit Vertex(VertexId id) : id_(id) {}
    VertexId id() const override { return id_; }
   private:
    VertexId id_;
  };
  struct Edge : public IEdge {...};
};
```

5\) Отрефакторить ваш код на использование интерфейсов заместо их реализаций.
Это должно быть сделано повсеместно.

Пример `graph_json_printer.hpp`:
```cpp
#pragma once

#include <string>
#include "interface/i_graph.hpp"

namespace uni_course_cpp {
namespace printing {
namespace json {

std::string print_graph(const IGraph& graph);
std::string print_vertex(const IVertex& vertex, const IGraph& graph);
std::string print_edge(const IEdge& edge, const IGraph& graph);

}  // namespace json
}  // namespace printing
}  // namespace uni_course_cpp
```

6\) Единственное место, где вы должны напрямую обращаться к классу `Graph` - это `graph_generator.cpp`.
Во всех остальных файлах вы опрерируете только с интерфейсом.

Тут возникает небольшая проблема, так как мы не можем создать экземпляр абстрактного класса,
то как нам вернуть сгенерированный `IGraph` из `GraphGenerator`? В этом, и только в этом
случае мы обернем его в `std::unique_ptr`. Смарт поинтер может указывать даже не абстрактный класс.
Для создания нового объекта `std::unique_ptr` нужно использовать специальную конструкцию `std::make_unique`.

Ещё один момент: для `std::unique_ptr` запрещено копирование, поэтому его можно только перемещать.

Пример:
- `graph_generator.hpp`

  ```cpp
  class GraphGenerator {
    std::unique_ptr<IGraph> generate() const;
  };
  ```

- `graph_generator.cpp`

  ```cpp
  std::unique_ptr<IGraph> GraphGenerator::generate() const {
    auto graph = Graph();
    // генерируем все вершины и ветви
    return std::make_unique<Graph>(std::move(graph));
  }
  ```


# Функция `main` вашей программы

```cpp
// ... some other logic ...

std::vector<std::unique_ptr<IGraph>> generate_graphs(
    GraphGenerator::Params&& params,
    int graphs_count,
    int threads_count) {
  auto generation_controller =
      GraphGenerationController(threads_count, graphs_count, std::move(params));

  auto& logger = Logger::get_logger();

  auto graphs = std::vector<std::unique_ptr<IGraph>>();
  graphs.reserve(graphs_count);

  generation_controller.generate(
      [&logger](int index) { logger.log(generation_started_string(index)); },
      [&logger, &graphs](int index, std::unique_ptr<IGraph> graph) {
        graphs.push_back(graph);
        const auto graph_description = printing::print_graph(*graph);
        logger.log(generation_finished_string(index, graph_description));
        const auto graph_json = printing::json::print_graph(*graph);
        write_to_file(graph_json, "graph_" + std::to_string(index) + ".json");
      });

  return graphs;
}

int main() {
  const int depth = handle_depth_input();
  const int new_vertices_count = handle_new_vertices_count_input();
  const int graphs_count = handle_graphs_count_input();
  const int threads_count = handle_threads_count_input();
  prepare_temp_directory();

  auto params = GraphGenerator::Params(depth, new_vertices_count);
  const auto graphs =
      generate_graphs(std::move(params), graphs_count, threads_count);

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и `*.hpp` исходные файлы.
- `makefile` по желанию.

# Время Выполнения

1 Неделя.
