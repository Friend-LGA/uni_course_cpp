# Задача 3

# Реализовать вывод графа в файл в формате `JSON`

Доработать программу, чтобы она выводила созданный граф в файл в формате `JSON`.
Для этого вам нужно будет добавить новую логику по распечатке графа и выделить её в отдельный `namespace`:
```cpp
namespace graph_printing {}
```
Логика по работе с файлами здесь присутствовать не должна, только генерация строк.

Набор функций должен быть следующий:
```cpp
namespace graph_printing {

std::string print_graph(const Graph& graph);
std::string print_vertex(const Graph::Vertex& vertex, const Graph& graph);
std::string print_edge(const Graph::Edge& edge, const Graph& graph);

}  // namespace graph_printing
```

Пример `JSON` структуры (ключей и значений) выводимого файла:
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

Можно в одну строку и даже без пробелов, как душе угодно, главное чтобы структура совпадала и `JSON` был валидный, например:
```json
{
  "vertices": [
    {"id":0,"edge_ids":[0,1,2]},
    {"id":1,"edge_ids":[0,3,4,5]},
    "..."
  ],
  "edges":[
    {"id":0,"vertex_ids":[0,1]},
    {"id":1,"vertex_ids":[0,2]},
    "..."
  ]
}
```

или даже так:
```json
{"vertices":[{"id":0,"edge_ids":[0,1,2]},"..."],"edges":[{"id":0,"vertex_ids":[0,1]},"..."]}
```

Пример файла можете посмотреть здесь: [graph.json](graph.json).

## Функция `main` вашей программы

```cpp
// ... some other logic ...

int main() {
  const auto graph = generate_graph();
  const auto graph_json = graph_printing::print_graph(graph);
  std::cout << graph_json << std::endl;
  write_to_file(graph_json, "graph.json");

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и/или `*.hpp` исходные файлы.
- Скомпилированный бинарник.
- `graph.json` (результат выполнения программы).
- `makefile` (по желанию).

# Время Выполнения

1 Неделя.

# Количество Баллов

10 Баллов.

# Полезные ссылки:
- [Graph Theory](https://en.wikipedia.org/wiki/Graph_theory)
- [JSON](https://en.wikipedia.org/wiki/JSON)
