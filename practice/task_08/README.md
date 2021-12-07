# Задача 8

# Реализовать поиск кратчайшего пути

- Создать класс `GraphTraverser`, ответственностью которого будет обход графа.
- Внутри `GraphTraverser` реализовать интерфейс для поиска кратчайшего пути между 2умя вершинами по алгоритму Дейкстры.
  - [Wiki: Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
- Возвращать путь между вершинами в виде массива из `VertexId`.
  - Для реализации данной логики создать структуру `GraphTraverser::Path`.
- Для определения дистанции между вершинами добавить пользовательский тип:
  - `using Distance = int;`

## Пример интерфейса

```cpp
class GraphTraverser {
  using Distance = int;

  struct Path {
    std::vector<VertexId> vertex_ids;
    Distance distance = 0;
  }

  GraphTraverser(const Graph& graph);

  std::optional<Path> find_shortest_path(
    VertexId source_vertex_id,
    VertexId destination_vertex_id) const;
};
```

# Реализовать многопоточный поиск кратчайших путей

- По аналогии с `task_07` создать `GraphTraversalController`, который будет искать все кратчайшие пути между корневой вершиной и вершинами на последней глубине.
- Максимальное количество воркеров:
  - `const int MAX_WORKERS_COUNT = std::thread::hardware_concurrency();`
- Пример. Если корневая вершина - `0`, а на последней глубине 3 вершины - `[32, 15, 28]`, то `GraphTraversalController` должен найти и вернуть 3 пути:
  - Path 0: 0 -> ... -> ... -> 32
  - Path 1: 0 -> ... -> ... -> 15
  - Path 2: 0 -> ... -> ... -> 28

## Пример интерфейса

```cpp
class GraphTraversalController {
  using TraversalStartedCallback = std::function<void(const Graph&)>;
  using TraversalFinishedCallback =
      std::function<void(const Graph&, std::vector<GraphTraverser::Path>)>;

  class Worker;

  GraphTraversalController(const Graph& graph);

  void traverse(
      const TraversalStartedCallback& traversalStartedCallback,
      const TraversalFinishedCallback& traversalFinishedCallback);
};
```

# Реализовать многопоточный поиск путей среди множества графов

- По аналогии с `task_06` написать логику, которая будет принимать список графов и, используя `GraphTraversalController` находить для каждого все кратчайшие пути.
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

## Пример интерфейса

```cpp
void traverse_graphs(const std::vector<Graph>& graphs) {
  // prepare jobs
  // prepare workers
  // start workers
  // wait for all jobs to be done
  // stop workers
}
```

# Функция `main` вашей программы

```cpp
// ... some other logic ...

int main() {
  const int depth = handle_depth_input();
  const int new_vertices_num = handle_new_vertices_num_input();
  const int graphs_count = handle_graphs_count_input();
  const int threads_count = handle_threads_count_input();

  const auto params = GraphGenerator::Params(depth, new_vertices_num);
  const auto graphs = generate_graphs(params, graphs_count, threads_count);

  traverse_graphs(graphs);

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и `*.hpp` исходные файлы.
- Скомпилированный бинарник.

# Время Выполнения

2 Недели.

# Количество Баллов

20 Баллов.