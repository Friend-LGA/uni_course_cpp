# Workflow

1. Сделать `fork` репозитория, куда вы будете загружать выполненные задачи (ссылку спросить у меня).
    - [Docs: About Forks](https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/about-forks)
    - [Docs: Fork a Repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo)
1. Склонировать данный `fork` к себе на компьютер, чтобы дальше работать с ним локально.
    - [Docs: Clone a Repo](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)
    - Используйте `SSH` ссылку, а не `HTTPS`.
1. Если у вас уже есть форк, то нужно поддерживать его в актуальном состоянии, и периодически подтягивать изменения из родителького репозитория:
    - [Docs: Syncing a Fork](https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/syncing-a-fork)
1. Для каждой новой задачи создаете новый `branch`:
    - Формат названий бранчей следующий:
      - `name_surname/task_number`
    - Пример:
      - `grigorii_lutkov/task_01`
    - Docs: [Git](https://git-scm.com/book/en/v2/Git-Branching-Branches-in-a-Nutshell), [Atlassian](https://www.atlassian.com/git/tutorials/using-branches)
1. Все файлы должны находиться в вашей подпапке:
    - Формат иерархии директорий следующий:
      - `/name_surname/*`
    - Пример:
      - `/grigorii_lutkov/*`
1. Все изменения должны находиться только внутри данной папки. Так как мы все работаем в одном общем репозитории, то каждый работает только внутри своей папки и не трогает файлы других студентов. Каждый отдельный `branch` должен включать в себя только те изменения, которые имеют отношения к конкретной задаче.
1. Когда задача готова, вы должны прогнать ваши файлы через `linter`:
    - Мы будем используем `clang-format`, инструкция по установки описана в [`Initial Setup`](initial_setup).
    - Файл конфигурации уже лежит в корне общего репозитория и выглядит так: [`.clang-format`](.clang-format).
      - Единственная и самая главная настройка, которую мы будем использовать:
        - `BasedOnStyle: Chromium` - означает, что за основу взято форматирование, принятое в команде, которая пишет `Chromium`.
    - Все, что вам нужно сделать, это:
      - Перейти в директорию с вашей задачей.
      - Выполнить форматирование `.hpp` и `.cpp` файлов:
        - Вариант 1, в одну строку:
          - `clang-format -i -style=Chromium *.(cpp|hpp)`
        - Вариант 2, в две строки, у кого в одну строку не работает:
          - `clang-format -i -style=Chromium *.cpp`
          - `clang-format -i -style=Chromium *.hpp`
            - `-i` - означает `Inplace`, то есть `linter` будет обновлять файлы при форматировании.
            - `-style=Chromium` - базовый стиль форматирования.
            - `*.cpp` - путь и маска, по которому искать файлы.
    - Можно создать `makefile` и автоматизировать этот процесс. Это уже по желанию.
1. После этого создаете `Pull Request` со следующими параметрами:
    - Base Repository: Общий репозиторий
    - Base Branch: `master`
    - Head Repository: Ваш `fork` общего репозитория
    - Compare Branch: `branch`, в котором вы выполняли работу по конкретной задаче
    - Name: `name_surname/task_number`
      - Пример:
        - `grigorii_lutkov/task_01`
    - Status: `Ready for Review`
      - [Docs: Changing the State of a Pull Request](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/changing-the-stage-of-a-pull-request)
    - Reviewers: `Grigorii Lutkov`
    - Labels: `task_number`
      - Пример:
        - `task_01`
    - Description: Оставьте пустым
    - [Docs: About Pull Requests](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests)
    - [Docs: Creating a Pull Request from a Fork](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/creating-a-pull-request-from-a-fork)
1. На `Pull Request` автоматически выполняются проверки (`GitHub Actions`):
    - `clang` компилирует ваши файлы и выполняет программу.
    - `linter` проверяет соответствие ваших файлов ожидаемому формату.
    - Вы можете следить за выполнением этих `jobs` на странице `Pull Request`.
    - Если все `ок`, `Pull Request` помечается зеленой галочкой.
    - Если где-то произошла ошибка, `Pull Request` помечается красным крестиком.
1. Если проверки прошли удачно, я провожу код ревью и дальнешее развитие может быть:
    - Я подтверждаю изменения.
      - Вы можете мерджить `Pull Request`
        - [Docs: Merging a Pull Request](https://docs.github.com/en/github/collaborating-with-pull-requests/incorporating-changes-from-a-pull-request/merging-a-pull-request)
    - Я оставляю комментарии и запрашиваю изменения.
      - Исправляете ошибки
      - Коммитите исправления в свой `branch`
      - `Pull Request` обновится автоматически
      - Запрашиваете ревью:
        - [Docs: Requesting a Pull Request Review](https://docs.github.com/en/github/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/requesting-a-pull-request-review)
1. Повторяем предыдущий шаг, пока не добьемся успеха.

# Updating Your Fork

Если у вас заблокирован `merge` для вашего `Pull Request`, или есть другая необходимость получить свежие изменения из общего мастера, то нужно следовать следующей логике:

1. Обновить ваш форк
    - [Docs: Syncing a Fork](https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/syncing-a-fork)
1. Перейти в локальный master
    - `git checkout master`
1. Обновить локальный master
    - `git pull origin master`
1. Перейти в свою ветку
    - `git checkout name_of_my_branch`
1. Добавить в неё новые изменения из мастера
    - `git merge master`
    - Docs: [Git](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging), [Atlassian](https://www.atlassian.com/git/tutorials/using-branches/git-merge)
1. Обновить свой PR
    - `git push origin name_of_my_branch`

# Rollback Changes from Pull Request

Если у вас в `Pull Request` есть изменения файлов относительно `master`, которые вы хотите откатить, то можно выполнить следующие команды:
- `git checkout master -- file_path`
- `git checkout master -- directory_path`

Полностью логика выглядит так:
- Обновляетесь на свежий `master`
  - Читать выше, [Updating Your Fork](#updating-your-fork)
- Переходите в свой `branch`
  - `git switch your_branch`
  - или
  - `git checkout your_branch`
- Откатываете изменение для файлов:
  - `git checkout master -- file_path`
- Создаете `commit` с изменениями
  - `git add .`
  - `git commit -m "Commit Message"`
- Обновляете ваш `Pull Request`
  - `git push origin your_branch`
