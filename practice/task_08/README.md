# Задача 8

# Реализовать поиск кратчайшего пути

- Создать класс `GraphTraverser`, ответственностью которого будет обход графа.
- Внутри `GraphTraverser` реализовать интерфейс для поиска кратчайшего пути между 2умя вершинами по алгоритму Дейкстры.
  - [Wiki: Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
- Возвращать путь между вершинами в виде массива из `VertexId`.
  - Для реализации данной логики создать структуру `GraphPath`.
- Для определения дистанции между вершинами добавить пользовательский тип:
  - `using Distance = int;`
- На данный момент дистанция между любыми 2умя вершинами - `1`.

## Пример интерфейса

`graph_path.hpp`:
```cpp
struct GraphPath {
  using Distance = int;

  std::vector<VertexId> vertex_ids;
  Distance distance = 0;
};
```

`graph_traverser.hpp`:
```cpp
class GraphTraverser {
  GraphTraverser(const Graph& graph);

  GraphPath find_shortest_path(VertexId source_vertex_id,
                               VertexId destination_vertex_id) const;
};
```

# Реализовать многопоточный поиск кратчайших путей

- По аналогии с `task_06` добавить `find_all_paths` метод, который будет искать все кратчайшие пути между корневой вершиной и вершинами на последней глубине.
- Максимальное количество воркеров:
  - `const int MAX_WORKERS_COUNT = std::thread::hardware_concurrency();`
- Пример. Если корневая вершина - `0`, а на последней глубине 3 вершины - `[32, 15, 28]`, то `find_all_paths` должен найти и вернуть 3 пути:
  - Path 0: 0 -> ... -> ... -> 32
  - Path 1: 0 -> ... -> ... -> 15
  - Path 2: 0 -> ... -> ... -> 28

## Пример интерфейса

```cpp
class GraphTraverser {
  // From root vertex to all vertices at the last depth
  std::vector<GraphPath> find_all_paths() const;
}
```

# Реализовать многопоточный поиск путей среди множества графов

- По аналогии с `task_07` создать `GraphTraversalController`, который будет принимать список графов и находить для каждого все кратчайшие пути.
- Максимальное количество воркеров:
  - `const int MAX_WORKERS_COUNT = std::thread::hardware_concurrency();`
- Логировать начало и конец обхода каждого графа, аналогично логированию генерации графов:
  ```
  date_time: Graph 0, Traversal Started
  date_time: Graph 0, Traversal Finished, Paths: [
    {vertices: [root_vertex_id, .., .., .., last_depth_vertex_id], distance: distance},
    {vertices: [root_vertex_id, .., .., .., last_depth_vertex_id], distance: distance},
    ...
  ]
  ```
  Пример:
  ```
  2021.12.06 19:16:28: Graph 0, Traversal Started
  2021.12.06 19:16:28: Graph 0, Traversal Finished, Paths: [
    {vertices: [0, 2, 18, 19, 20], distance: 4},
    {vertices: [0, 2, 6, 7, 5, 9], distance: 5},
    {vertices: [0, 2, 6, 12, 13, 14], distance: 5}
  ]
  ```
- Расширить логику `graph_printing`:
  ```cpp
  namespace graph_printing {
    std::string print_path(const GraphTraverser::Path& path);
  }  // namespace graph_printing
  ```

## Пример интерфейса

```cpp
class GraphTraversalController {
  using TraversalStartedCallback =
      std::function<void(int /* index */,
                         const Graph& /* graph */)>;
  using TraversalFinishedCallback =
      std::function<void(int /* index */,
                         const Graph& /* graph */,
                         std::vector<GraphTraverser::Path> /* paths */)>;

  class Worker;

  GraphTraversalController(const std::vector<Graph>& graphs);

  void traverse(
      const TraversalStartedCallback& traversalStartedCallback,
      const TraversalFinishedCallback& traversalFinishedCallback);
};
```

# Функция `main` вашей программы

```cpp
// ... some other logic ...

void traverse_graphs(const std::vector<Graph>& graphs) {
  auto traversal_controller = GraphTraversalController(graphs);

  traversal_controller.traverse(
      [](int index, const Graph& traversed_graph) {
        auto& logger = Logger::get_logger();
        logger.log(traversal_started_string(index));
      },
      [](int index, const Graph& traversed_graph,
         std::vector<GraphTraverser::Path> paths) {
        auto& logger = Logger::get_logger();
        logger.log(traversal_finished_string(index, paths));
      });
}

int main() {
  const int depth = handle_depth_input();
  const int new_vertices_count = handle_new_vertices_count_input();
  const int graphs_count = handle_graphs_count_input();
  const int threads_count = handle_threads_count_input();
  prepare_temp_directory();

  const auto params = GraphGenerator::Params(depth, new_vertices_count);
  const auto graphs = generate_graphs(params, graphs_count, threads_count);

  traverse_graphs(graphs);

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и `*.hpp` исходные файлы.
- Скомпилированный бинарник.
- `makefile` (по желанию).

# Время Выполнения

2 Недели.

# Количество Баллов

20 Баллов.
