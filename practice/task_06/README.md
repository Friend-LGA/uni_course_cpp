# Задача 6

# Реализовать многопоточную генерацию графов

1. Запрашивать у пользователя новый входной параметр:
    - `threads_count`: Количество потоков генерации графов.
1. Создать структуру `GraphGenerator::Params`, которая будет включать в себя:
    - `depth`
    - `new_vertices_num`
1. Добавить класс `GraphGenerationController`, который будет принимать в себя аргументы для генерации всех графов:
    - `threads_count`
    - `graphs_count`
    - `graph_generator_params`
1. `GraphGenerationController` должен создавать пулл работников `GraphGenerationController::Worker`, числом `threads_count`. Соответственно, каждый свободный работник должен начинать генерировать новый граф, пока все графы не будут сгенерированы.
1. `GraphGenerationController` должен иметь интерфейс для старта генерации и для возвращения каждого сгенерированного графа используя `lambda`:
    - ```cpp
      class GraphGenerationController {
        void generate(const GenStartedCallback& gen_started_callback,
                      const GenFinishedCallback& gen_finished_callback);
      };
      ```
1. Собрать все сгенерированные графы в коллекцию.
1. Логирование должно работать как и раньше.
    - Так как логгер у нас один, нужно добавить синхронизацию потоков внутри него.

## Пример интерфейса

```cpp
class GraphGenerationController {
 public:
  using JobCallback = std::function<void()>;
  using GetJobCallback = std::function<std::optional<JobCallback>()>;
  using GenStartedCallback = std::function<void(int)>;
  using GenFinishedCallback = std::function<void(int, Graph)>;

  class Worker {
   public:
    explicit Worker(const GetJobCallback& get_job_callback);

    void start();
    void stop();

   private:
    std::thread thread_;
    GetJobCallback get_job_callback_;
  };

  GraphGenerationController(int threads_count,
                            int graphs_count,
                            GraphGenerator::Params graph_generator_params);

  void generate(const GenStartedCallback& gen_started_callback,
                const GenFinishedCallback& gen_finished_callback);


 private:
  std::list<Worker> workers_;
  std::list<JobCallback> jobs_;
};
```

Идея такая: `Worker::start()` создает поток с бесконечным циклом внутри себя, который постоянно проверяет, есть ли доступная `Job` для него:
```cpp
void Worker::start() {
  // ...
  thread_ = std::thread([]() {
              while (true) {
                if (should_terminate()) {
                    return;
                }
                const auto job_optional = get_job_callback();
                if (job_optional.has_value()) {
                    const auto job_callback = job_optional.value();
                    job_callback();
                }
              }
            });
  // ...
}
```

`Jobs` соответственно мы заполняем в `GraphGenerationController::generate`:
```cpp
void GraphGenerationController::generate(
    const GenStartedCallback& gen_started_callback,
    const GenFinishedCallback& gen_finished_callback) {
  // ...
  for (auto& worker : workers_) {
    worker.start();
  }
  // ...
  for (int i = 0; i < graphs_count_; i++) {
    jobs_.emplace_back([]() {
      gen_started_callback(i);
      auto graph = graph_generator_.generate();
      gen_finished_callback(i, std::move(graph));
    });
  }
  // ...
}
```

Выше - это псевдокод. Можете взять его за основу и доработать, или можете подумать над другим вариантом реализации.

Главное чтобы базовый интерфейс совпадал:
```cpp
class GraphGenerationController {
  class Worker {
    // ...
  };
  void generate(const GenStartedCallback& gen_started_callback,
                const GenFinishedCallback& gen_finished_callback);
  // ...
};
```

## Функция `main` вашей программы

```cpp
// ... some other logic ...

int main() {
  const int depth = handle_depth_input();
  const int new_vertices_num = handle_new_vertices_num_input();
  const int graphs_count = handle_graphs_count_input();
  const int threads_count = handle_threads_count_input();

  const auto params = GraphGenerator::Params(depth, new_vertices_num);
  auto generation_controller =
      GraphGenerationController(threads_count, graphs_count, params);
  auto& logger = prepare_logger();

  auto graphs = std::vector<Graph>();
  graphs.reserve(graphs_count);

  generation_controller.generate(
      [&logger](int index) {
        logger.log(gen_started_string(index));
      },
      [&logger, &graphs](int index, Graph graph) {
        logger.log(gen_finished_string(index, graph));
        graphs.push_back(graph);
      });

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и `*.hpp` исходные файлы.
- Скомпилированный бинарник.

# Время Выполнения

1 Неделя

# Количество Баллов

10 Баллов
