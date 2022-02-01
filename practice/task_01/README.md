# Задача 1

1. Открыть [GitHub.com](github.com)
1. Сделать `fork` репозитория, куда вы будете загружать выполненные задачи (ссылку спросить у меня).
    - [Docs: About Forks](https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/about-forks)
    - [Docs: Fork a Repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo)
1. Склонировать данный `fork` к себе на компьютер, чтобы дальше работать с ним локально.
    - [Docs: Clone a Repo](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)
    - Используйте `SSH` ссылку, а не `HTTPS`.
1. Перейти в склонированную папку.
1. Создайте новую ветку с названием `surname_name/task_01` и переключитесь на неё:
    - Пример названия:
      - `lutkov_grigorii/task_01`
    - Вариант 1, сделать это в 2 действия:
      - `git branch surname_name/task_01`
      - `git switch surname_name/task_01`
    - Вариант 2, короткая форма:
      - `git checkout -b surname_name/task_01`
    - Docs: [Git](https://git-scm.com/book/en/v2/Git-Branching-Branches-in-a-Nutshell), [Atlassian](https://www.atlassian.com/git/tutorials/using-branches)
1. Создайте папку с вашим именем `surname_name`:
    - Пример:
      - `lutkov_grigorii`
1. Перейдите в свою папку.
1. Напишите простую C++ программу `hello_world.cpp`, которая будет выводить на экран 2 строки:
    ```cpp
    #include <iostream>

    int main() {
      std::cout << "Hello World!" << std::endl;
      std::cout << "Surname Name" << std::endl;
      std::cout << "Фамилия Имя" << std::endl;
      return 0;
    }
    ```
1. Чтобы удостовериться, что форматирование текста верное, выполните `clang-format`:
    - `clang-format -i -style=Chromium hello_world.cpp`
1. Скомпилируйте её для `C++17` c использованием `-Werror` флага (мы будем всегда его использовать в обучающих целях):
    - `clang++ hello_world.cpp -o hello_world -std=c++17 -Werror`
1. Очистите командную строку, чтобы не было лишней информации и выполните следующие команды
    - `brew --version`
    - `clang++ --version`
    - `clang-format --version`
    - `g++ --version`
    - `git --version`
    - `git config --global user.name`
    - `git config --global user.email`
    - `./hello_world`
1. Сделайте скриншот окна терминала с полученной информацией.
    ![Screenshot](screenshot.png)
1. Создайте `README.md` файл:
    - [Docs: About Readmes](https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/customizing-your-repository/about-readmes)
1. В `README.md` укажите ваши `Surname Name` и `Фамилия Имя` как заголовок и добавьте скриншот:
    ```md
    # Surname Name
    # Фамилия Имя
    ![Screenshot](screenshot.png)
    ```
1. Добавьте новые файлы в индекс, чтобы `git` отслеживал изменения в них:
    - Вариант 1: перечислить все файлы:
        - `git add README.md hello_world.cpp hello_world screenshot.png`
    - Вариант 2: добавляет все файлы по указанному пути:
        - `git add ./` или `git add .`
    - Docs: [Git](https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository), [GitHub](https://github.com/git-guides/git-add), [Atlassian](https://www.atlassian.com/git/tutorials/saving-changes)
1. Создайте локально новый коммит с названием `Add hello_world app`
    - `git commit -m "Add hello_world app"`
      - Docs: [Git](https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository), [GitHub](https://github.com/git-guides/git-commit), [Atlassian](https://www.atlassian.com/git/tutorials/saving-changes/git-commit)
1. Отправьте ваши изменения в ветке `surname_name/task_01` в ваш `fork` на GitHub:
    - `git push origin surname_name/task_01`
      - Docs: [Git](https://git-scm.com/book/en/v2/Git-Basics-Working-with-Remotes), [GitHub](https://github.com/git-guides/git-push), [Atlassian](https://www.atlassian.com/git/tutorials/syncing/git-push)
1. Переключитесь на ветку `master`
    - `git switch master`
1. Откройте свой `fork` на [GitHub.com](github.com) и создайте `Pull Request` со следующими параметрами:
    - Base Repository: Тот, откуда вы делали `fork`
    - Base Branch: `master`
    - Head Repository: Ваш `fork`
    - Compare Branch: `surname_name/task_01`, в котором вы выполняли работу по конкретной задаче
    - Name: `surname_name/task_01`
    - Status: `Ready for Review`
      - [Docs: Changing the State of a Pull Request](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/changing-the-stage-of-a-pull-request)
    - Reviewers: `Grigorii Lutkov`
    - Labels: `task_01`
    - Description: Оставьте пустым
    - [Docs: About Pull Requests](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests)
    - [Docs: Creating a Pull Request from a Fork](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork)
1. На `Pull Request` автоматически выполнятся проверки на то, что текст вашей программы правильно отформатирован, и что она компилируется без ошибок.
1. Далее я его проверю, если все нормально - изменю статус на `Accepted`.
1. После этого вы сможете нажать кнопку `Merge`, чтобы слить ваш `PR` с веткой `master` общего репозитория.
1. Теперь задача считается выполненной.

Все эти шаги так же описаны в основном [`Workflow`](/workflow.md).

Обратите внимание, что `git` требует обятательного наличия знака новой строки `\n` в конце файла.
Иначе в вашем `Pull Request` вы увидите ошибку - `no newline at end of file`.
Будьте внимательны.

# Содержание `Pull Request`

- `hello_world.cpp` исходный файл.
- `screenshot.png` cкриншот командной строки с данными.
- `README.md` с вашими именем и фамилией (eng + rus) и скриншотом.

# Время Выполнения

1 Неделя.

# Полезные ссылки
- `git`
  - [Docs: Git](https://git-scm.com/doc)
  - [Guides: GitHub](https://github.com/git-guides/)
  - [Guides: Atlassian Git](https://www.atlassian.com/git)
- GitHub
  - [Docs](https://docs.github.com/en)
- Markdown
  - [Docs](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
  - [Guides](https://guides.github.com/features/mastering-markdown/)
- `.gitignore`
  - [Docs](https://git-scm.com/docs/gitignore)
- `README.md`
  - [Docs](https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/customizing-your-repository/about-readmes)
