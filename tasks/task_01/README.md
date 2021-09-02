# Задача 1

1. Создать пустой репозиторий на [GitHub](github.com) с названием "cpp_hello_world"
2. Инициализировать `git` репозиторий локально
    - `git init`
3. Создайте файлы
    - `.gitignore`
    - `README.md`
4. В `README.md` укажите ваши "Имя Фамилия"
5. Сделайте эти файлы отслеживаемыми
    - Вариант 1: перечислить все файлы
        - `git add .gitignore README.md`
    - Вариант 2: символ `.` добавляет все файлы
        - `git add .`
5. Создайте локально новый коммит в ветке `master` с названием "Init"
    - `git commit -m "Init"`
6. Добавьте синхронизируемый репозиторий с GitHub по SSH ссылке
    - `git remote add origin git@github.com:username/repository_name.git`
7. Запушьте ваши изменения в ветке `master` на GitHub
    - `git push origin master`
8. Создайте новую ветку с названием `hello_world` и переключитесь на неё
    - Вариант 1: сделать это в 2 действия
        - `git branch hello_world`
        - `git switch hello_world`
    - Вариант 2: короткая форма
        - `git checkout -b hello_world`
9. Создайте простое C++ приложение `hello_world.cpp`, которое будет выводить на экран 2 строки
    ```cpp
    #include <iostream>

    int main() {
      std::cout << "Hello World!" << std::endl << "Имя Фамилия" << std::endl;
      return 0;
    }
    ```
10. Скомпилируйте его для C++17 c использованием `-Werror` флага (мы будем всегда его использовать в обучающих целях)
    - `clang++ hello_world.cpp -o hello_world -std=c++17 -Werror`
11. Выполните скомпилированную программу
    - `./hello_world`
12. Создайте локально новый коммит в ветке `hello_world` с названием "Add hello world app"
13. Запушьте изменения в ветке `hello_world`
15. Переключитесь на ветку `master`
14. Смерджите ветку `hello_world` с веткой `master`
    - `git merge hello_world`
15. Запушьте изменения в `master`
16. Очистите командную строку, чтобы не было лишней информации и выполните следующие команды
    - `clang++ --version`
    - `git --version`
    - `./hello_world`
17. Сделайте скриншот окна терминала с полученной информацией.
18. Закоммитьте скриншот в репозиторий.
19. Обновите `README.md` чтобы оно показывало полученный скриншот.
20. Закоммитьте изменения.

# Пример скриншота
![Screenshot](tasks/task_01/screenshot.png)

# Полезные ссылки:
- [`git` документация](https://git-scm.com/doc)
- [GitHub документация](https://docs.github.com/en)
