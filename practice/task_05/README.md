# Задача 5

# 1. Генерировать множество графов

- Доработать программу, чтобы последовательно генерировать 10 графов.
- Запрашивать входные параметры только 1 раз, и использовать их для всех графов.
- Для каждого графа создавать отдельный `JSON` файл.

# 2. Добавить Логирование

1. Написать `Logger`, который будет выводить следующую информацию в консоль и в файл с названием `log.txt`:
    ```
    time: Graph 1, Generation Started
    time: Graph 1, Generation Ended {
      depth: number,
      new_vertices_num: number,
      vertices: count, [depth_0_count, depth_1_count, ...],
      edges: count, {gray: count, green: count, blue: count, yellow: count, red: count}
    }
    ```
1. Файл создавать внутри поддиректории `temp`.
    - Пример:
      - `/task_dir_name/name_surname/temp/log.txt`
1. `JSON` файл переместить туда же.

# 3. Обновить `/.gitignore`

1. Добавить директорию `temp` в конец файла `/.gitignore`:
    - Пример:
      - `task_dir_name/name_surname/temp/`
1. Соответственно, этой директории в вашем ПР быть не должно.

# Содержание `Pull Request`

- `*.cpp` и/или `*.hpp` исходные файлы.
- Скомпилированный бинарник.
- Изменения в `/.gitignore`.

# Рабочая директория

`/02_knight_and_princess/name_surname/*`

# Время Выполнения

1 Неделя

# Количество Баллов

10 Баллов
