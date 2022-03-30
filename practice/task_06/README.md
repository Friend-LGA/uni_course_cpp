# Задача 6

# Реализовать многопоточную генерацию графа

Доработать класс `GraphGenerator` следующим образом:
- Серые грани должны генерироваться многопоточно.
  Образно говоря, каждая отдельная ветка, отходящая от корневой вершины, должна генерироваться в своём потоке.

  Пример, если `new_vertices_count = 3`, соответственно 3 потока:
  ```
                 ┌──────────────────────────────────────────────╮
                 | branch 1, thread 1                     - ... |
                 |                          - (vertex 15) - ... |
                 |            - (vertex 05) - (vertex 19) - ... |
                 | (vertex 1) - (vertex 08) - (vertex 20) - ... |
                 |            - (vertex 09) - (vertex 19) - ... |
                 |                          - (vertex 24) - ... |
                 |                                        - ... |
                 ╰──────────────────────────────────────────────╯
                 ┌──────────────────────────────────────────────╮
                 | branch 2, thread 2                     - ... |
  ┌──────────╮   |                          - (vertex 13) - ... |
  | root     |   |            - (vertex 04) - (vertex 14) - ... |
  | vertex 0 | - | (vertex 2) - (vertex 10) - (vertex 17) - ... |
  ╰──────────╯   |            - (vertex 11) - (vertex 20) - ... |
                 |                          - (vertex 22) - ... |
                 |                                        - ... |
                 ╰──────────────────────────────────────────────╯
                 ┌──────────────────────────────────────────────╮
                 | branch 3, thread 3                     - ... |
                 |                          - (vertex 16) - ... |
                 |            - (vertex 06) - (vertex 18) - ... |
                 | (vertex 3) - (vertex 07) - (vertex 21) - ... |
                 |            - (vertex 12) - (vertex 23) - ... |
                 |                          - (vertex 25) - ... |
                 |                                        - ... |
                 ╰──────────────────────────────────────────────╯
  ```
    - Максимальное число потоков `std::thread::hardware_concurrency()`, независимо от `new_vertices_count`
      - `const int kMaxThreadsCount = std::thread::hardware_concurrency();`
    - Если все потоки заняты, соответственно следующие ветви ждут своей очереди.
- После того, как вершины и серые грани сгенерированы, переходим к остальным цветам граней:
  - Зеленые грани генерируются в отдельном потоке
  - Желтые грани генерируются в отдельном потоке
  - Красные грани генерируются в отдельном потоке

### Логика генерации серых граней

- У вас должен быть пул потоков, содержащий в себе по 1 воркеру (`worker`) на поток.
- Каждый воркер запускает внутри себя бесконечный цикл и проверяет в нем, есть ли для него новая работа (`job`).
- Каждая работа - это `lambda` функция, которая энкапсулирует в себе вызов генерации новой ветви.
- Если есть доступная работа - воркер берет её из списка и выполняет.
- Когда воркер освобождается, он снова проверяет, есть ли для него доступная работа.
- Как только все работы выолнены, воркеры останавливаются и генерация завершается.
- Использовать рекурсию.

### Логика генерации остальных цветных граней

1) Оборачиваете генерацию граней каждого отдельного цвета в отдельный поток (`std::thread`).
2) Так как обработка вершин не взаимосвязана, используйте многопоточную версию цикла `for` с параллельной политикой выполнения `std::execution::par`:

```cpp
std::for_each(std::execution::par, begin, end, lambda_function);
```

Ссылки:
- [`for_each`](https://en.cppreference.com/w/cpp/algorithm/for_each)
- [`execution_policy`](https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t)

## Работа с потоками

Базовой структурой для работы с потоками в `C++` является [`std::thread`](https://en.cppreference.com/w/cpp/thread/thread).

При создании `std::thread` необходимо
1) Указать функцию или лямбда функцию, которую он будет выполнять.
2) Выполнить одну из следующих операций:
    - `.join()` - означает что родительский поток в этом месте дождется завершения
    выполнения порожденного потока, и только после этого продолжит своё выполнение.
    - `.detach()` - означает что родительский поток не будет дожидаться завершения
    выполнения порожденного потока и сразу же продолжит своё выполнение.

До момента выхода из скопа, где вы создали поток, обязательно нужно выполнить либо
`join`, либо `detach`, иначе программа выкинет исключение.

```cpp
void some_function() {
  int a = 1;
  int b = 5;
  int c = 0;
  // Создаем поток, который выполнит лямда функцию и сложит a + b
  const auto thread = std::thread([a, b, &c]() {
    c = a + b;
  });
  // Выведет на экран "0"
  std::cout << c << std::endl;
  // Дожидаемся выполнения потока
  thread.join();
  // Выведет на экран "6"
  std::cout << c << std::endl;
}
```

## Синхронизация потоков

Когда у вас есть разделяемые ресурсы между потоками, другими словами,
когда есть несколько потоков, которые обращаются и изменяют одни и те же ресурсы,
необходимо такие ресурсы синхронизировать.

Для этого давайте рассмотри 3 базовых инструмента:

1\) [`std::atomic`](https://en.cppreference.com/w/cpp/atomic/atomic) - используется, когда вам нужно синхронизировать обращение к примитивным типам.
Помогает избежать оверхэда, возникающего при работе с `std::mutex`.

```cpp
std::atomic<bool> atomic_bool = false;

const auto thread1 = std::thread([&atomic_bool]() {
  if (atomic_bool) {
    atomic_bool = false;
  }
});

const auto thread2 = std::thread([&atomic_bool]() {
  if (!atomic_bool) {
    atomic_bool = true;
  }
});
```

В данном коде у нас с вами происходит, так называемое "Race Condition".
Оба потока обращаются и изменяют одни и те же данные. В этом случае
логика программы будет предсказуема, так как мы используем `std::atomic`.

2\) [`std::mutex`](https://en.cppreference.com/w/cpp/thread/mutex) - используется для синхронизации общей логики между потоками. Для начала синхронизации необходимо вызвать
`.lock()`, и для завершения синхронизации - `.unlock()`.

```cpp
bool flag = false;
std::mutex flag_mutex;

const auto thread1 = std::thread([&flag, &flag_mutex]() {
  flag_mutex.lock();
  if (flag) {
    flag = false;
  }
  flag_mutex.unlock();
});

const auto thread2 = std::thread([&flag, &flag_mutex]() {
  flag_mutex.lock();
  if (!flag) {
    flag = true;
  }
  flag_mutex.unlock();
});
```

3\) [`std::lock_guard`](https://en.cppreference.com/w/cpp/thread/lock_guard) - используется как альтернатива ручному контролю блокировки `std::mutex`.
При использовании `std::lock_guard` нет необходимости выывать `lock` и `unlock`,
так как деструктор объекта `std::lock_guard` вызовет `unlock` автоматически.

Возможные ошибки при ручном контроле блокировок:
```cpp
std::mutex some_mutex;

// Пример 1
some_mutex.lock();
if (flag) {
  // ...
} else if (other_flag) {
  // Ошибка!!! `some_mutex` остался заблокированным
  return false;
} else {
  // Ошибка!!! `some_mutex` остался заблокированным
  throw std::runtime_error();
}
some_mutex.unlock();
```

Использование `std::lock_guard`:
```cpp
const std::lock_guard lock(mutex);
if (flag) {
  // ...
} else if (other_flag) {
  return false;
} else {
  throw std::runtime_error();
}
```

# Псевдокод

```cpp
class GraphGenerator {

  Graph generate() const {
    auto graph = Graph();
    graph.add_vertex();

    generate_grey_edges(...);

    // Обернуть в поток `std::thread green_thread`
    generate_green_edges(...);

    // Обернуть в поток `std::thread yellow_thread`
    generate_yellow_edges(...);

    // Обернуть в поток `std::thread red_thread`
    generate_red_edges(...);

    // Ждем, когда все грани будут сгенерированы
    green_thread.join();
    yellow_thread.join();
    red_thread.join();

    return graph;
  }

  void generate_grey_edges(...) {
    // Job - это lambda функция,
    // которая энкапсулирует в себе генерацию одной ветви
    using JobCallback = std::function<void()>;
    auto jobs = std::list<JobCallback>();

    // Заполняем список работ для воркеров
    for (int i = 0; i < new_vertices_count; i++) {
      jobs.push_back(
          [...]() {
            generate_grey_branch(...);
          });
    }

    // Создаем воркера,
    // который в бесконечном цикле проверяет,
    // есть ли работа, и выполняет её
    const auto worker = [&should_terminate, &jobs_mutex, &jobs]() {
        while (true) {
          // Проверка флага, должны ли мы остановить поток
          if (should_terminate) {
            return;
          }
          // Проверяем, есть ли для нас работа
          const auto job_optional = [...]() -> std::optional<JobCallback> {
            if (has_job()) {
              return get_job();
            }
            return std::nullopt;
          }();
          if (job_optional.has_value()) {
            // Работа есть, выполняем её
            const auto& job = job_optional.value();
            job();
          }
        }
      };

    // Создаем и запускаем потоки с воркерами
    const auto threads_count = std::min(kMaxThreadsCount, new_vertices_count);
    auto threads = std::vector<std::thread>();
    threads.reserve(threads_count);
    // fill threads

    // Ждем, когда все ветви будут сгенерированы
    while (...) {}

    // Останавливем всех воркеров и потоки
    should_terminate = true;
    for (auto& thread : threads) {
      thread.join();
    }
  }

  void generate_grey_branch(...) {
    // рекурсивно вызывает сам себя
    generate_grey_branch(...);
  }

}
```

Не забудьте добавить синхронизацию там, где необходимо.
- `std::atomic`
- `std::mutex`
- `std::lock_guard`

# Частые Ошибки

- [Не инициализированные переменные](/practice/common_mistakes.md#uninitialised-variables)

# Функция `main` вашей программы

Без изменений.

# Содержание `Pull Request`

- `*.cpp` и `*.hpp` исходные файлы.
- `makefile` по желанию.

# Время Выполнения

1 Неделя.
