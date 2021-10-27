# Задача 2

## Написать граф

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

Инетрфейс для взаимодействия с графом должен быть следующий:
```cpp
class Graph {
  void add_vertex();
  void add_edge(const VertexId from_vertex_id, const VertexId to_vertex_id);
};
```

Остальной интерфейс и имплементация за вами, дерзайте!

### Визуализация графа, который вы должны сгенерировать
![Graph](graph.png)

- Порядок `id` вершин и граней могут отличаться от нарисованных здесь. Главное чтобы первая вершина имела `id = 0`, последняя вершина имела `id = 13` и форма графа совпадали.
- Визуализация дана только для лучшего понимания задачи, вам ничего рисовать не нужно.

### Функция `main` вашей программы

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

# Рабочая директория

`/02_knight_and_princess/name_surname/*`

# Время Выполнения

1 Недели

# Количество Баллов

10 Баллов

# Полезные ссылки:
- [Graph Theory](https://en.wikipedia.org/wiki/Graph_theory)
- [JSON](https://en.wikipedia.org/wiki/JSON)
