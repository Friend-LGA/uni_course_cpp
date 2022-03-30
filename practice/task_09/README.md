# Задача 9

# Реализовать поиск кратчайшего пути

- Создать класс `GraphTraverser`, ответственностью которого будет обход графа.
- Внутри `GraphTraverser` реализовать интерфейс для поиска кратчайшего пути между 2умя вершинами по алгоритму Дейкстры.
  - [Wiki: Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
- Возвращать путь между вершинами в виде массивов из `VertexId` и `EdgeId`.
  - Для реализации данной логики создать интерфейс `IGraphPath` и структуру `GraphPath`.
- Для определения дистанции между вершинами добавить пользовательский тип:
  - `using PathDistance = int;`
- На данный момент дистанция между любыми 2умя вершинами - `1`.

## Пример интерфейса

`i_graph_path.hpp`:
```cpp
using PathDistance = int;
struct IGraphPath {
  PathDistance distance() const = 0;
  const std::vector<VertexId>& vertex_ids() const = 0;
  const std::vector<EdgeId> edge_ids() const = 0;
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
- Пример. Если корневая вершина - `0`, а на последней глубине 3 вершины - `[32, 15, 28]`, то `find_all_paths` должен найти и вернуть 3 пути:
  - Path 0: 0 -> ... -> ... -> 32
  - Path 1: 0 -> ... -> ... -> 15
  - Path 2: 0 -> ... -> ... -> 28

## Пример класса

```cpp
class GraphTraverser {
  // From root vertex to all vertices at the last depth
  std::vector<GraphPath> find_all_paths() const;
}
```

# Реализовать многопоточный поиск путей среди множества графов

- По аналогии с `task_07` создать `GraphTraversalController`, который будет принимать список графов и находить для каждого все кратчайшие пути.
- Вынести `GraphGenerationController::Worker` в отдельную сущность и переиспользовать его.
- Логировать начало и конец обхода каждого графа, аналогично логированию генерации графов:
  ```
  date_time Graph 0, Traversal Started
  date_time Graph 0, Traversal Finished, Paths: [
    {vertices: [root_vertex_id, .., last_vertex_id], edges: [first_edge_id, .., last_edge_id], distance: distance},
    {vertices: [root_vertex_id, .., last_vertex_id], edges: [first_edge_id, .., last_edge_id], distance: distance},
    ...
  ]
  ```
  Пример:
  ```
  2021.12.06 19:16:28 Graph 0, Traversal Started
  2021.12.06 19:16:28 Graph 0, Traversal Finished, Paths: [
    {vertices: [0, 2, 18, 19, 20], edges: [1, 15, 17, 25], distance: 4},
    {vertices: [0, 2, 6, 7, 5, 9], edges: [1, 7, 12, 9, 13], distance: 5},
    {vertices: [0, 2, 6, 12, 13, 14], edges: [1, 7, 17, 20, 29], distance: 5}
  ]
  ```
- Расширить логику `printing`:
  ```cpp
  namespace printing {

  std::string print_path(const IGraphPath& path);

  }  // namespace printing
  ```

## Пример интерфейса

```cpp
class GraphTraversalController {
  GraphTraversalController(const std::vector<unique_ptr<IGraph>>& graphs);

  void traverse(
      const TraversalStartedCallback& traversalStartedCallback,
      const TraversalFinishedCallback& traversalFinishedCallback);
};
```

# Функция `main` вашей программы

```cpp
// ... some other logic ...

void traverse_graphs(const std::vector<unique_ptr<IGraph>>& graphs) {
  auto traversal_controller = GraphTraversalController(graphs);
  auto& logger = Logger::get_logger();

  traversal_controller.traverse(
      [...](...) {
        logger.log(traversal_started_string(index));
      },
      [...](...) {
        logger.log(traversal_finished_string(index, paths));
      });
}

int main() {
  const int depth = handle_depth_input();
  const int new_vertices_count = handle_new_vertices_count_input();
  const int graphs_count = handle_graphs_count_input();
  const int threads_count = handle_threads_count_input();
  prepare_temp_directory();

  auto params = GraphGenerator::Params(depth, new_vertices_count);
  const auto graphs = generate_graphs(std::move(params), graphs_count, threads_count);

  traverse_graphs(graphs);

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и `*.hpp` исходные файлы.
- `makefile` по желанию.

# Время Выполнения

1 Неделя.

# Полезные ссылки

- [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
