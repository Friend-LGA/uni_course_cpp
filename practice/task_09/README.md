# Задача 9

# Добавить основу игровой логики

- Создать класс `GameMap`, который будет хранить в себе граф и продолжительность (`Duration`) перехода по каждой грани:
  ```cpp
  class GameMap {
  public:
    using Duration = int;
  private:
    Graph graph_;
    std::unordered_map<EdgeId, Duration> edge_durations_;
  };
  ```
  - `Duration` может принимать рандомное `int` значение из соответствующего диапазона:
    - Grey = [1, 2]
    - Green = [1, 2]
    - Blue = [1, 3]
    - Yellow = [1, 3]
    - Red = [2, 4]
- Добавить структуру `GameMapPath`, унаследованную от `GraphPath`, которая должна знать продолжительность пути:
  ```cpp
  struct GameMapPath : public GraphPath {
    GameMap::Duration duration() const { return duration_; }
  };
  ```
- Создать класс `Game`, который будет инкапсулировать игровую логику:
  - Игровую карту
  - Расположение рыцаря
  - Расположение принцессы
  - Поиск кратчайшего пути между рыцарем и принцессой
    - Параметр поиска - `GraphPath::Distance`, количество шагов пути
  - Поиск скорейшего пути между рыцарем и принцессой
    - Параметр поиска - `GameMap::Duration`, продолжительность пути
  ```cpp
  class Game {
   public:
    // Traverse by `Distance`
    GameMapPath find_shortest_path() const;
    // Traverse by `Duration`
    GameMapPath find_fastest_path() const;
   private:
    GameMap map_;
    Graph::VertexId knight_position_;
    Graph::VertexId princess_position_;
  };
  ```
- Соответственно, для поиска путей добавить класс `GameMapTraverser`, аналогичный классу `GraphTraverser`.
- Создать класс `GameGenerator`, который принимает параметры графа `GraphGenerator::Params` и генерирует игру `Game`.
- Добавить логику `game_printing`, аналогичную `graph_printing`:
  ```cpp
  namespace game_printing {
    std::string print_game(const Game& game);
    std::string print_character_position(VertexId vertex_id, const Graph& graph);
    std::string print_path(const GameMapPath& path);
    std::string print_map(const GameMap& map);
  }  // namespace game_printing
  ```
  - Метод `print_map` должен печатать карту в `JSON` формате. Пример:
  ```json
  {
    "graph": { "..." },
    "edge_durations": [
      {"edge_id": 0, "duration": 1},
      {"edge_id": 1, "duration": 1},
      "..."
    ]
  }
  ```
  - Пример файла можете посмотреть здесь: [map.json](map.json).
- Ваша программа должна создать игру и залогировать её данные. Пример:
  ```
  2021.12.20 10:44:42 Game is Preparing...
  2021.12.20 10:44:42 Game is Ready {
    map: {
      depth: 7,
      vertices: {amount: 44, distribution: [1, 2, 4, 7, 10, 9, 8, 3]},
      edges: {amount: 89, distribution: {grey: 43, green: 5, blue: 7, yellow: 26, red: 8}}
    },
    knight position: {vertex_id: 0, depth: 0},
    princess position: {vertex_id: 17, depth: 7}
  }
  2021.12.20 10:44:42 Searching Shortest Path...
  2021.12.20 10:44:42 Shortest Path: {vertices: [0, 1, 22, 38, 39, 16, 17], distance: 6, duration: 11}
  2021.12.20 10:44:42 Searching Fastest Path...
  2021.12.20 10:44:42 Fastest Path: {vertices: [0, 1, 4, 10, 12, 14, 16, 17], distance: 7, duration: 9}
  ```

## Логика программы

1. Получаете параметры графа от пользователя.
    - `depth`
    - `new_vertices_count`
1. Подготавливаете окружение.
    - `prepare_temp_directory()`
1. Генерируете игру.
    - `const auto game = game_generator.generate();`
1. Выполняете поиск кратчайшего пути.
    - `game.find_shortest_path();`
1. Выполняете поиск скорейшего пути.
    - `game.find_fastest_path();`
1. Параллельно с выполнением программы логируете данные.
  1. `Game is Preparing...`
  1. `Game is Ready`
  1. `Searching for Shortest Path...`
  1. `Shortest Path: { ... }`
  1. `Searching for Fastest Path...`
  1. `Fastest Path: { ... }`
1. Распечатываете игровую карту в файл `map.json`

# Функция `main` вашей программы

```cpp
// ... some other logic ...

int main() {
  const int depth = handle_depth_input();
  const int new_vertices_count = handle_new_vertices_count_input();
  prepare_temp_directory();

  auto& logger = Logger::get_logger();
  logger.log(game_preparing_string());

  const auto params = GraphGenerator::Params(depth, new_vertices_count);
  const auto game_generator = GameGenerator(params);
  const auto game = game_generator.generate();

  logger.log(game_ready_string(game));
  logger.log(shortest_path_searching_string());

  const auto shortest_path = game.find_shortest_path();

  logger.log(shortest_path_ready_string(shortest_path));
  logger.log(fastest_path_searching_string());

  const auto fastest_path = game.find_fastest_path();

  logger.log(fastest_path_ready_string(fastest_path));

  const auto map_json = game_printing::print_map(game.map());
  write_to_file(map_json, "map.json");

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и `*.hpp` исходные файлы.
- Скомпилированный бинарник.
- `map.json` (результат выполнения программы).
- `makefile` (по желанию).

# Время Выполнения

1 Недели.

# Количество Баллов

10 Баллов.
