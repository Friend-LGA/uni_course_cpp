# Задача 3

## Добавить валидацию данных

В тех функциях, где есть входные параметры, которые имеет смысл валидировать, нужно добавить валидацию.
Например:
- Если вы передаете в функцию `VertexId`, нужно проверить, что `Vertex` с таким `id` существует в графе.
- Если вы создаете новую грань между вершинами, нужно проверить, что эти вершины еще не связаны друг с другом.
- И т.д. и т.п.

Цель данной валидации - отловить баги в коде, а значит программа должна падать в случае неудачи.
Поэтому для валидации использовать `assert`.

Примеры:
```cpp
assert(should_be_true() && "This condition should be true");
assert(has_vertex(id) && "Vertex doesn't exist");
assert(!has_edge(from_vertex_id, to_vertex_id) && "Vertices are already connected");
```

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
 public:
  GraphPrinter(const Graph& graph) : graph_(graph) {}

  std::string print() const;
  std::string print_vertex(const Vertex& vertex) const;
  std::string print_edge(const Edge& edge) const;

 private:
  Graph& graph_;
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

int main() {
  const auto graph = generate_graph();
  const auto graph_printer = GraphPrinter(graph);
  const auto graph_json = graph_printer.print();
  std::cout << graph_json << std::endl;
  write_to_file(graph_json, "graph.json");

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и/или `*.hpp` исходные файлы.
- Скомпилированный бинарник.
- `graph.json` - результат выполнения программы.

# Время Выполнения

1 Недели

# Количество Баллов

10 Баллов

# Полезные ссылки:
- [Graph Theory](https://en.wikipedia.org/wiki/Graph_theory)
- [JSON](https://en.wikipedia.org/wiki/JSON)
