# Workflow

1. Сделать `fork` репозитория, куда вы будете загружать выполненные задачи (ссылку спросить у меня).
    - [Docs: About Forks](https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/about-forks)
    - [Docs: Fork a Repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo)
1. Для каждой новой задачи создаете новый `branch`:
    - Формат названий бранчей следующий:
      - `name_surname/task_number`
    - Пример:
      - `grigorii_lutkov/task_01`
1. Для каждой новой задачи, при необходимости, создаете подпапку:
    - Формат иерархии директорий следующий:
      - `/task_dir_name/name_surname/*`
      - `task_dir_name` дано в описании каждой задачи (`Рабочая директория`)
    - Пример:
      - `/01_hello_world/grigorii_lutkov/*`
1. Все изменения должны находиться только внутри данной папки. Так как мы все работаем в одном общем репозитории, то каждый работает только внутри своей папки и не трогает файлы других студентов. Каждый отдельный `branch` должен включать в себя только те изменения, которые имеют отношения к конкретной задаче.
1. Когда задача готова, создаете `Pull Request` со следующими параметрами:
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
1. Я провожу ревью и дальнешее развитие может быть:
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

# Common Mistakes

## 1. Неверное название бранчей (`branch`)

Повторяю:
- Формат названий бранчей следующий:
  - `name_surname/task_number`
- Пример:
  - `grigorii_lutkov/task_01`

## 2. Неверная иерархия директорий

Повторяю:
- Формат иерархии директорий следующий:
  - `/task_dir_name/name_surname/*`
- Пример:
  - `/01_hello_world/grigorii_lutkov/*`

## 3. Добавление в `Pull Request` неотносящихся изменений

К примеру, при добавлении файлов первой задачи, вы, зачем-то, удаляете файлы других студентов из репозитория :))

`Pull Request` представляет собой ваш `branch`, который, в свою очередь, представляет собой логически завершенный блок работы, включающий в себя только те изменения, которые необходимы для реализации поставленной задачи.

Вернемся к примеру выше: для реализации первой задачи, необходимости удалять чужие файлы из репозитория нет.

## 4. No Newline at End of File

У текстовых фалов есть определенный формат, и, следуя этому формату, заканчиваться они должны символом новой строки. Это необходимо чтобы правильно определять количество строк в файле.

Кому сильно интересно:
- [Дискуссия 1](https://stackoverflow.com/questions/5813311/whats-the-significance-of-the-no-newline-at-end-of-file-log)
- [Дискуссия 2](https://unix.stackexchange.com/questions/18743/whats-the-point-in-adding-a-new-line-to-the-end-of-a-file)

## 5. `using namespace`

Использовать `using namespace` считается плохой практикой.
Вместе этого лучше использовать ограниченный `using` (см. [aliases](/02_knowledge_check/13_aliases)):

```cpp
using std::cout;
using std::endl;
using short_name = foo::bar::baz::long_name;
```

Или просто писать полностью:

```cpp
std::cout << "..." << std::endl;
```

Кому сильно интересно:
- [Дискуссия](https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice)
