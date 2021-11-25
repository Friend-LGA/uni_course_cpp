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
  thread_ = std::thread([]() {
              while (true) {
                // Проверка флага, должны ли мы остановить поток
                if (should_terminate()) {
                    return;
                }
                // Проверяем, есть ли для нас работа
                const auto job_optional = get_job_callback();
                if (job_optional.has_value()) {
                    // Работа есть, выполняем её
                    const auto job_callback = job_optional.value();
                    job_callback();
                }
              }
            });
}

void Worker::stop() {
  // Проверить что `Worker` работает
  // Установить флаг на то что поток должен быть остановлен
  thread_.join(); // ждем завершения потока
}

Worker::~Worker() {
  // При удалении мы обязательно должны остановить поток
  if (is_working()) {
    stop();
  }
}
```

Запускаем/Останавливаем воркеров и заполняем `jobs` мы соответственно в `GraphGenerationController::generate`:
```cpp
void GraphGenerationController::generate(
    const GenStartedCallback& gen_started_callback,
    const GenFinishedCallback& gen_finished_callback) {
  // Запускаем воркеров
  for (auto& worker : workers_) {
    worker.start();
  }

  // Заполняем список работы для воркеров
  for (int i = 0; i < graphs_count_; i++) {
    jobs_.emplace_back([]() {
      gen_started_callback(i);
      auto graph = graph_generator_.generate();
      gen_finished_callback(i, std::move(graph));
    });
  }

  // Ждем что все `jobs` выполнены и, соответственно, все графы сгенерированы

  // Останавливаем воркеров
  for (auto& worker : workers_) {
    worker.start();
  }
}
```

Данный код - не полная реализация, он - это база, которую вы должны доработать.

## Синхронизация потоков

Для синхронизации потоков вам понадобятся 2 инструмента:
- [`std::mutex`](https://en.cppreference.com/w/cpp/thread/mutex)
- [`std::lock_goard`](https://en.cppreference.com/w/cpp/thread/lock_guard)

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
        const auto graph_printer = GraphPrinter(graph);
        write_to_file(graph_printer.print(),
                      "graph_" + std::to_string(index) + ".json");
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
