# Задача 2

Данная, и последующие задачи выполняются поверх файлов предыдущей задачи.
В вашей папке не должны находиться файлы с решением отдельных задач.
Все изменения накладываются друг на друга.
Каждый новый ПР изменяет состояние вашего проекта (вашей папки).
У вас должна быть только одна программа с одной функцией `int main()`.

Тот код, который вы увидите здесь ниже и дальше по заданиям - это псевдокод, близкий к C++.
Я не гарантирую, что он компилируется. Вы должны его придерживаться, но, можете вносить небольние изменения, если считаете это необходимым.

# Написать граф

Используя парадигму объектно-ориентированного программирования, написать программу, которая будет генерировать конкретный граф (см. рисунок ниже).

Параметры графа:
- Неориентированный, можно двигаться в любом направлении.
- Между любыми двумя вершинами может быть только одна грань.
- Вершина может иметь одну грань к самой себе.

Соответственно нужно объявить сущности, из которых состоит граф:
```cpp
class Graph {
  struct Vertex { ... };
  struct Edge { ... };
}
```

Вершина и грань должны быть объявлены внутри графа и иметь **уникальное** поле `id`, для которого нужно объявить псевдонимы:
```cpp
class Graph {
  using VertexId = int;
  using EdgeId = int;
}
```

Интерфейс для взаимодействия с графом должен быть следующий:
```cpp
class Graph {
 public:
  void add_vertex();
  void add_edge(VertexId from_vertex_id, VertexId to_vertex_id);
};
```

Вершина должна иметь поле `id` и ничего более:
```cpp
struct Vertex {
  explicit Vertex(VertexId init_id) : id(init_id) {}

  const VertexId id = 0;
}
```

Грань должна иметь поле `id` и `id` вершин, которые она связывает, и ничего более:
```cpp
struct Edge {
  Edge(EdgeId init_id,
       VertexId init_from_vertex_id,
       VertexId init_to_vertex_id) :
    id(init_id),
    from_vertex_id(init_from_vertex_id),
    to_vertex_id(init_to_vertex_id) {}

  const EdgeId id = 0;
  const VertexId from_vertex_id = 0;
  const VertexId to_vertex_id = 0;
}
```

Остальной интерфейс и имплементация за вами, дерзайте!

## Визуализация графа, который вы должны сгенерировать
![Graph](graph.png)

Визуализация дана только для лучшего понимания задачи, вам ничего рисовать не нужно.

## Функция `main` вашей программы

```cpp
// ... some other logic ...

static constexpr int kVerticesCount = 14;

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
- `makefile` по желанию.

# Время Выполнения

1 Неделя.

# Полезные ссылки:
- [Graph Theory](https://en.wikipedia.org/wiki/Graph_theory)
- [JSON](https://en.wikipedia.org/wiki/JSON)
