# Задача 5

# 1. Разбить вашу программу на отдельные файлы.

Разбить вашу программу на отдельные `header` и `source` файлы.
Соответственно у вас должна получиться примерно такая структура:
- `main.cpp`
- `graph.hpp`
- `graph.cpp`
- `graph_generator.hpp`
- `graph_generator.cpp`
- `graph_printer.hpp`
- `graph_printer.cpp`
- `logger.hpp`
- `logger.cpp`

Возможно у вас будет больше или меньше файлов, этот список дан чтобы вы поняли общую идею.

# 2. Генерировать множество графов

- Запрашивать у пользователя новый входной параметр:
  - `graphs_count`: Количество генерируемых графов.
- Доработать программу, чтобы последовательно генерировать `graphs_count` графов.
- Запрашивать входные параметры только 1 раз, и использовать их для всех графов.
- Для каждого графа создавать отдельный `JSON` файл.

# 3. Добавить Логирование

1. Написать `Logger`, который будет использоваться для вывода следующей информацию в консоль и в файл с названием `log.txt`:
    ```
    time: Graph 1, Generation Started
    time: Graph 1, Generation Finished {
      depth: number,
      new_vertices_num: number,
      vertices: count, [depth_0_count, depth_1_count, ...],
      edges: count, {gray: count, green: count, blue: count, yellow: count, red: count}
    }
    ```
1. Реализовать логгер используя паттерн `Singleton`.
    - [Wiki: Singleton Pattern](https://en.wikipedia.org/wiki/Singleton_pattern)
1. В публичном интерфейсе у него должен быть только один метод для логирования данных:
    - ```cpp
      class Logger {
       public:
        void log(const std::string& string) const;
      };
      ```
1. Файл `log.txt` создавать внутри поддиректории `temp`.
    - Пример:
      - `/task_dir_name/name_surname/temp/log.txt`
1. `JSON` файлы переместить туда же.

# 3. Обновить `/.gitignore`

1. Добавить директорию `temp` в конец файла `/.gitignore`:
    - Пример:
      - `task_dir_name/name_surname/temp/`
1. Соответственно, этой директории в вашем ПР быть не должно.

# Содержание `Pull Request`

- `*.cpp` и `*.hpp` исходные файлы.
- Скомпилированный бинарник.
- Изменения в `/.gitignore`.

# Рабочая директория

`/02_knight_and_princess/name_surname/*`

# Время Выполнения

1 Неделя

# Количество Баллов

10 Баллов
