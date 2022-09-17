# `IDE`: Development Environment

## Recomended IDE
- [Visual Studio Code](https://code.visualstudio.com)
- [Atom](https://atom.io)
- [Sublime Text](https://www.sublimetext.com)

## If You Know What You're Doing
- [Vim](https://www.vim.org)

Лично я рекомендую использовать `VSCode`.

# [`WSL`](https://en.wikipedia.org/wiki/Windows_Subsystem_for_Linux): Windows Subsystem for Linux

Если вы используете Windows и ещё не используете WSL, то это пора исправлять.

1. Рекомендую установить современный [`Windows Terminal`](https://www.microsoft.com/ru-ru/p/windows-terminal/9n0dx20hk701) из Microsoft Store.
1. Установить `WSL` следуя [инструкции](https://docs.microsoft.com/en-us/windows/wsl/install).
1. Установить `Linux` дистрибутив, например [`Ubuntu`](https://www.microsoft.com/ru-ru/p/ubuntu/9nblggh4msv6).
1. Теперь вы можете использовать `Ubuntu` через `WSL` внутри `Windows Terminal`, ура ура.

# [Homebrew (`brew`)](https://brew.sh)

## For `MacOS`

`Homebrew` - стандартный менеджер пакетов для `MacOS`.

1. Установить `Xcode` или `Command Line Tools`:
    - `Xcode`: установить из [`AppStore`](https://apps.apple.com/ru/app/xcode/id497799835).
    - `Command Line Tools`: использовать команду:
      - `sudo xcode-select --install`
1. Установить `Homebrew` следуя [инструкции](https://brew.sh).
1. Проверить версию, чтобы убедиться что все работает:
    - `brew --version`
    - `Homebrew 3.6.0`

## For `Linux`

Скорее всего вы используете `Ubuntu`.
Проблема в том, что в ней установлены устаревшие пакеты, так как они тестируются для каждой конкретной версии системы.
Чтобы пользоваться современными версиями, то проще всего будет установить `Homebrew`.

1. Предварительная подготовка необходимых инструментов:
    - `sudo apt install build-essential procps curl wget file git`
1. Установить `Homebrew` следуя [инструкции](https://docs.brew.sh/Homebrew-on-Linux).
1. Проверить версию, чтобы убедиться что все работает:
    - `brew --version`
    - `Homebrew 3.6.0`

# Compilation

Для компиляции мы будем использовать [`clang`](https://clang.llvm.org/).

1. Установить `LLVM` и `clang++`:
    - `brew install llvm`
1. Проверить версию, чтобы убедиться что все работает:
    - `clang++ --version`
    - `Homebrew clang version 14.0.0`
    - Должна быть выше `>= 14.0.0`

Версия `g++` так же должна быть свежей, так как от неё есть зависимости.

1. Установить `GCC`:
    - `brew install gcc`
1. Проверить версию, чтобы убедиться что все работает:
    - `g++ --version`
    - `g++ (Homebrew GCC 12.0.0) 12.0.0`
    - Должна быть выше `>= 12.0.0`

Возможно ваша система будет показывать не установленную через `brew` либу, а старую, идущую в комплекте с ОС.
В таком случае у вас есть 2 пути:

1. Обновить вашу переменную окружения `$PATH`, так чтобы путь до новых версий был первым в поиске.
    - Пример:
      ```
      export PATH="/usr/local/opt/llvm/bin:$PATH"
      export PATH="/usr/local/opt/gcc/bin:$PATH"
      export PATH="$PATH:/$HOME/bin:/usr/local/bin:/usr/local/sbin"
      ```
1. Создать `alias` или `function`.
    - Пример:
      ```
      alias clang_new=/usr/local/opt/llvm/bin/clang++
      alias gcc_new=/usr/local/opt/gcc/bin/g++
      ```

# Code Formatting, Linter

Для форматирования кода мы будем использовать [`clang-format`](https://clang.llvm.org/docs/ClangFormat.html).

1. Установить `clang-format`:
    - `brew install clang-format`
1. Проверить версию, чтобы убедиться что все работает:
    - `clang-format --version`
    - `Homebrew clang-format version 14.0.0`
    - Должна соответствовать версии `clang`

# [`VCS`](https://en.wikipedia.org/wiki/Version_control): Version Control System

Нашей системой контроля версий будет [`git`](https://git-scm.com).

1. Установить `git`:
    - `brew install git`
1. Проверить версию, чтобы убедиться что все работает:
    - `git --version`
    - `git version 2.37.0`
1. Настроить ([Docs](https://docs.github.com/en/get-started/getting-started-with-git)):
    - Имя: `git config --global user.name "Mona Lisa"`
    - Email: `git config --global user.email "email@example.com"`
        - Адрес должен совпадать с тем, который вы указывали при регистрации на `GitHub`.
1. Проверить настройки:
    - `git config --global -l`

# [GitHub](github.com)

Работа будет вестиcь в общем репозитории на [`GitHub`](github.com).

1. Зарегистрируйтесь/Войдите на [`GitHub`](github.com).
1. Сгенерируйте и добавьте `SSH` ключ по [инструкции](https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh/about-ssh).

# `VSCode` Setup

`VSCode` поддерживает `clang` и `clang-format` из коробки. Для этого просто нужно установить официальный плагин для `C++`:

- [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

Так же нужно обновить настройки:

1. Откройте настройки:
    - `File` или `Code` -> `Preferences` -> `Settings`.
1. Update `clang-format` `Fallback Style`:
    - Search for `C_Cpp.clang_format_fallbackStyle`.
    - Set it to `Chromium`.
1. Update `clang` version of `C++`:
    - Search for `C_Cpp.default.compilerArgs`.
    - Add item `-std=c++17`.
1. Specify `clang` compiler path:
    - Search for `C_Cpp.default.compilerPath`.
    - Specify path to your `clang++` binary.
      - Пример: `/usr/local/opt/llvm/bin/clang++`
      - Чтобы узнать ваш путь, можете воспользоваться командой:
        - `where clang++`

Форматировать файл в `VSCode` можно сочетанием клавиш: (`alt` или `opt`) + `shift` + `f`.

# Shell

Рекомендация:
Лично я использую `zsh`, на мой взгляд он удобней, чем `bash`.
Чтобы расширить его возможности, есть крутой фреймворк [`oh-my-zsh`](https://github.com/ohmyzsh/ohmyzsh).

# Hello World App

Чтобы проверить, что всё нормально работает, давайте напишем простенькое `Hello World` приложение:

1. Create `hello_world.cpp` file:
    ```cpp
    #include <iostream>

    int main() {
      std::cout << "Hello World!" << std::endl;
      return 0;
    }
    ```
2. Use `clang++` to compile `hello_world.cpp`
    - `clang++ hello_world.cpp -o hello_world -std=c++17 -Werror`
    - Useful Clang Flags:
      - `-std=c++17` to specify version of C++ 17
      - `-Werror` to treat all warnings as errors
      - `-Wno-...` to disable specific warning
      - [All Flags](https://clang.llvm.org/docs/DiagnosticsReference.html)
3. Run compiled `hello_world` app
    - `./hello_world`

# Useful Links
- [`clang` Documentation](https://clang.llvm.org)
- [`clang-format` Documentation](https://clang.llvm.org/docs/ClangFormat.html)
- `git` Documentation and Guides:
  - [GitHub: Set Up Git](https://docs.github.com/en/get-started/quickstart/set-up-git)
  - [GitHub: Getting Started with Git](https://docs.github.com/en/get-started/getting-started-with-git)
  - [GitHub: Git Guides](https://github.com/git-guides)
  - [Wiki: Version Control](https://en.wikipedia.org/wiki/Version_control)
  - [Wiki: Git](https://en.wikipedia.org/wiki/Git)
- [GitHub](github.com)
