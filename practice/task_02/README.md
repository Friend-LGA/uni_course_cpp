# Задача 2

# Написать граф

Написать программу, которая будет генерировать конкретный граф (см. рисунок ниже).

Параметры графа:
- Неориентированный, можно двигаться в любом направлении.
- Между любыми двумя вершинами может быть только одна грань.
- Вершина может иметь одну грань к самой себе.

Использовать парадигму объектно-ориентированного программирования.
Соответственно объявить сущности, из которых состоит граф:
```cpp
struct Vertex;
struct Edge;
class Graph;
```

Вершины и грани графа должны иметь **уникальное** поле `id`, для которого нужно нужно объявить специализированные типы:
```cpp
using VertexId = int;
using EdgeId = int;
```

Интерфейс для взаимодействия с графом должен быть следующий:
```cpp
class Graph {
 public:
  Vertex& add_vertex();
  Edge& add_edge(VertexId from_vertex_id, VertexId to_vertex_id);
};
```

Вершина должна иметь поле `id` и ничего более:
```cpp
struct Vertex {
 public:
  explicit Vertex(VertexId id) : id_(id) {}

  VertexId id() const { return id_; }

 private:
  VertexId id_ = 0;
}
```

Грань должна иметь поле `id` и `id` вершин, которые она связывает, и ничего более:
```cpp
struct Edge {
 public:
  Edge(EdgeId id,
       VertexId from_vertex_id,
       VertexId to_vertex_id) :
    id_(id),
    from_vertex_id_(from_vertex_id),
    to_vertex_id_(to_vertex_id) {}

  EdgeId id() const { return id_; }
  VertexId from_vertex_id() const { return from_vertex_id_; }
  VertexId to_vertex_id() const { return to_vertex_id_; }

 private:
  EdgeId id_ = 0;
  VertexId from_vertex_id_ = 0;
  VertexId to_vertex_id_ = 0;
}
```

Остальной интерфейс и имплементация за вами, дерзайте!

## Визуализация графа, который вы должны сгенерировать
![Graph](graph.png)

Визуализация дана только для лучшего понимания задачи, вам ничего рисовать не нужно.

## Функция `main` вашей программы

```cpp
// ... some other logic ...

constexpr int kVerticesCount = 14;

int main() {
  auto graph = Graph();

  for (int i = 0; i < kVerticesCount; i++) {
    graph.add_vertex();
  }

  graph.add_edge(0, 1);
  graph.add_edge(0, 2);
  graph.add_edge(0, 3);
  graph.add_edge(1, 4);
  graph.add_edge(1, 5);
  graph.add_edge(1, 6);
  graph.add_edge(2, 7);
  graph.add_edge(2, 8);
  graph.add_edge(3, 9);
  graph.add_edge(4, 10);
  graph.add_edge(5, 10);
  graph.add_edge(6, 10);
  graph.add_edge(7, 11);
  graph.add_edge(8, 11);
  graph.add_edge(9, 12);
  graph.add_edge(10, 13);
  graph.add_edge(11, 13);
  graph.add_edge(12, 13);

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и/или `*.hpp` исходные файлы.
- Скомпилированный бинарник.

# Время Выполнения

1 Неделя.

# Количество Баллов

10 Баллов.

# Полезные ссылки:
- [Graph Theory](https://en.wikipedia.org/wiki/Graph_theory)
- [JSON](https://en.wikipedia.org/wiki/JSON)
