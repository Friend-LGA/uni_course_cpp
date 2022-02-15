# Задача 7

# Реализовать многопоточную генерацию графов

1. Запрашивать у пользователя новый входной параметр:
    - `threads_count`: Количество потоков генерации графов.
1. Создать структуру `GraphGenerator::Params`, которая будет включать в себя:
    - `depth`
    - `new_vertices_count`
1. Добавить класс `GraphGenerationController`, который будет принимать в себя аргументы для генерации всех графов:
    - `threads_count`
    - `graphs_count`
    - `graph_generator_params`
1. `GraphGenerationController` должен создавать пулл работников `GraphGenerationController::Worker`, числом `threads_count`.
   Соответственно, каждый свободный работник должен начинать генерировать новый граф, пока все графы не будут готовы.
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
1. Запись `JSON` файлов должна работать как и раньше.

## Пример интерфейса

```cpp
class GraphGenerationController {
 public:
  using JobCallback = std::function<void()>;
  using GenStartedCallback = std::function<void(int index)>;
  using GenFinishedCallback = std::function<void(int index, Graph&& graph)>;

  class Worker {
   public:
    using GetJobCallback = std::function<std::optional<JobCallback>()>;

    enum class State { Idle, Working, ShouldTerminate };

    explicit Worker(const GetJobCallback& get_job_callback);

    void start();
    void stop();

   private:
    std::thread thread_;
    GetJobCallback get_job_callback_;
    State state_ = State::Idle;
  };

  GraphGenerationController(int threads_count,
                            int graphs_count,
                            GraphGenerator::Params&& graph_generator_params);

  void generate(const GenStartedCallback& gen_started_callback,
                const GenFinishedCallback& gen_finished_callback);


 private:
  std::list<Worker> workers_;
  std::list<JobCallback> jobs_;
  // std::mutex ...
};
```

Идея такая: `Worker::start()` создает поток с бесконечным циклом внутри себя, который постоянно проверяет, есть ли доступная `Job` для него.
При удалении `Worker` обязательно должен быть остановлен, иначе у нас останется поток, который уже нельзя будет завершить.
```cpp
void Worker::start() {
  // Проверить что `Worker` ещё не был запущен

  // Создаем поток с бесконечным циклом
  // Ждем появления работы
  thread_ = std::thread([...]() {
              while (true) {
                // Проверка, должны ли мы остановить поток
                if (state_ == State::ShouldTerminate) {
                    return;
                }
                // Проверяем, есть ли для нас работа
                const auto job_optional = get_job_callback();
                if (job_optional.has_value()) {
                    // Работа есть, выполняем её
                    const auto& job = job_optional.value();
                    job();
                }
              }
            });
}

void Worker::stop() {
  // Проверить что `Worker` работает
  // Остановить и завершить поток
  thread_.join();
}

Worker::~Worker() {
  // При удалении мы обязательно должны остановить поток, если он запущен
  stop();
}
```

Запускаем/Останавливаем воркеров и заполняем `jobs` мы соответственно в `GraphGenerationController::generate`:
```cpp
void GraphGenerationController::generate(
    const GenStartedCallback& gen_started_callback,
    const GenFinishedCallback& gen_finished_callback) {
  // Заполняем список работ для воркеров
  for (int i = 0; i < graphs_count_; i++) {
    jobs_.emplace_back([...]() {
      gen_started_callback(i);
      auto graph = graph_generator_.generate();
      gen_finished_callback(i, std::move(graph));
    });
  }

  // Запускаем воркеров
  for (auto& worker : workers_) {
    worker.start();
  }

  // Ждем, что все `jobs` выполнены, и, соответственно, все графы сгенерированы

  // Останавливаем воркеров
}
```

Данный код - не полная реализация, он - это база, которую вы должны доработать.
Не забудьте добавить синхронизацию там, где необходимо.
- `std::mutex`
- `std::atomic`

## Синхронизация потоков

Для синхронизации потоков вам понадобятся 2 инструмента:
- [`std::mutex`](https://en.cppreference.com/w/cpp/thread/mutex)
- [`std::lock_goard`](https://en.cppreference.com/w/cpp/thread/lock_guard)

## Функция `main` вашей программы

```cpp
// ... some other logic ...

std::vector<Graph> generate_graphs(const GraphGenerator::Params& params,
                                   int graphs_count,
                                   int threads_count) {
  auto generation_controller =
      GraphGenerationController(threads_count, graphs_count, std::move(params));

  auto& logger = Logger::get_logger();

  auto graphs = std::vector<Graph>();
  graphs.reserve(graphs_count);

  generation_controller.generate(
      [&logger](int index) {
        logger.log(generation_started_string(index));
      },
      [&logger, &graphs](int index, Graph&& graph) {
        const auto graph_description = printing::print_graph(graph);
        logger.log(generation_finished_string(index, graph_description));
        const auto graph_json = printing::json::print_graph(graph);
        graphs.push_back(graph);
        write_to_file(graph_json, "graph_" + std::to_string(index) + ".json");
      });

  return graphs;
}

int main() {
  const int depth = handle_depth_input();
  const int new_vertices_count = handle_new_vertices_count_input();
  const int graphs_count = handle_graphs_count_input();
  const int threads_count = handle_threads_count_input();
  prepare_temp_directory();

  const auto params = GraphGenerator::Params(depth, new_vertices_count);
  const auto graphs = generate_graphs(std::move(params), graphs_count, threads_count);

  return 0;
}
```

# Содержание `Pull Request`

- `*.cpp` и `*.hpp` исходные файлы.
- `makefile` по желанию.

# Время Выполнения

1 Неделя.
