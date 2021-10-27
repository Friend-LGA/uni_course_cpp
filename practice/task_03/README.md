# Задача 3

## Добавить валидацию данных

В тех функциях, где есть входные параметры, которые имеет смысл валидировать, нужно добавить валидацию.
Например:
- Если вы передаете в функцию `VertexId`, нужно проверить, что `Vertex` с таким `id` существует в графе.
- Если вы создаете новую грань между вершинами, нужно проверить, что эти вершины еще не связаны друг с другом.
- И т.д. и т.п.

## Реализовать текстовый вывод графа в файл в формате `JSON`

Доработать программу, чтобы она выводила созданный граф в файл в формате `JSON`.
Для этого вам нужно будет создать новую сущность:
```cpp
class GraphPrinter;
```
Который будет включать в себя всю логику по распечатке графа,
но не должен включать логику по работе с файлами, так как это не относится к его зоне ответственности.

Интерфейс для взаимодействия с принтером должен быть следующий:
```cpp
class GraphPrinter {
  std::string print() const;
};
```

Пример структуры (ключей и значений) выводимого файла:
```json
{
  "vertices": [
    {
      "id": 0,
      "edge_ids": [0, 1, 2]
    }, {
      "id": 1,
      "edge_ids": [0, 3, 4, 5]
    },
    "..."
  ],
  "edges": [
    {
      "id": 0,
      "vertex_ids": [0, 1]
    }, {
      "id": 1,
      "vertex_ids": [0, 2]
    },
    "..."
  ]
}
```

Можно в одну строку и даже без пробелов, как душе угодно, главное чтобы структура совпадала и `JSON` был валидный:
```json
{"vertices":[{"id":0,"edge_ids":[0,1,2]},"..."],"edges":[{"id":0,"vertex_ids":[0,1]},"..."]}
```

Пример файла можете посмотреть здесь: [graph.json](graph.json).

### Функция `main` вашей программы

```cpp
// ... some other logic ...

constexpr int kVerticesCount = 14;

Graph generate_graph() {
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

  return graph;
}

void write_to_file(const GraphPrinter& graph_printer,
                   const std::string& filename) {
  std::ofstream outfile(filename);
  outfile << graph_printer.print() << std::endl;
  outfile.close();
}

int main() {
  const auto graph = generate_graph();
  const auto graph_printer = GraphPrinter(graph);
  std::cout << graph_printer.print() << std::endl;
  write_to_file(graph_printer, "graph.json");

  return 0;
}

```

# Содержание `Pull Request`

- `*.cpp` и/или `*.hpp` исходные файлы.
- Скомпилированный бинарник.
- `graph.json` - результат выполнения программы.

# Рабочая директория:

`/02_knight_and_princess/name_surname/*`

# Время Выполнения

1 Недели

# Количество Баллов

10 Баллов

# Полезные ссылки:
- [Graph Theory](https://en.wikipedia.org/wiki/Graph_theory)
- [JSON](https://en.wikipedia.org/wiki/JSON)
