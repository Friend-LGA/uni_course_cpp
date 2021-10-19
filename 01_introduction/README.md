# `IDE`: Development Environment

## Recomended IDE
- [Visual Studio Code](https://code.visualstudio.com)
- [Atom](https://atom.io)
- [Sublime Text](https://www.sublimetext.com)

## If You Know What You're Doing
- [Vim](https://www.vim.org)

Лично я рекомендую использовать `VSCode`.

# `WSL`: Windows Subsystem for Linux

Если вы используете Windows, то можно сильно упростить свою жизнь используя `WSL`.
В нашем случае лучше использовать `WSL`, чтобы у всех было одинаковое окружение.

1. Рекомендую установить совеременный [`Windows Terminal`](https://www.microsoft.com/ru-ru/p/windows-terminal/9n0dx20hk701) из [`Microsoft Store`](https://www.microsoft.com/ru-ru/p/windows-terminal/9n0dx20hk701).
1. Установить `WSL` следуя [инструкции](https://docs.microsoft.com/en-us/windows/wsl/install).
1. Установить Linux дистрибутив, например [Ubuntu](https://www.microsoft.com/ru-ru/p/ubuntu/9nblggh4msv6).
1. Теперь вы можете использовать `Ubuntu` внутри `Windows Terminal`, ура ура.

# [Homebrew (`brew`)](https://brew.sh)

## For `MacOS`

`Homebrew` is default package manager for `MacOS`.

1. Install either `Xcode` or `Command Line Tools`:
    - `Xcode`: Install from [`AppStore`](https://apps.apple.com/ru/app/xcode/id497799835).
    - `Command Line Tools`: Use this command:
      - `sudo xcode-select --install`
1. Follow [instructions](https://brew.sh) to install `Homebrew`.
    - `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
1. Check `brew` version
    - `brew --version`

## For `Linux`

Скорее всего вы используете `Ubuntu`.
Проблема в том, что в ней установлены устаревшие пакеты, так как они тестируются для каждой конкретной версии системы.
Если вы хотите пользоваться современными версиями, то проще всего будет установить `Homebrew`.
В нашем случае лучше использовать `Homebrew`, чтобы у всех было одинаковое окружение.

1. Install bare minimum of packages:
    - `sudo apt install build-essential procps curl wget file git`
1. Follow instruction [Homebrew-on-Linux](https://docs.brew.sh/Homebrew-on-Linux). 
    - `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
    - `echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"' >> /home/grigorii_lutkov/.profile`
    - `eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"`
1. Check `brew` version
    - `brew --version`

# Compilation

Для клмпиляции мы будем использовать [`clang`]((https://clang.llvm.org/)).

1. Install `LLVM` and `clang`
    - `brew install llvm`
1. Check `clang++` version to validate installation is complete
    - `clang++ --version`

# Code Formatting, Linter

Для форматирования кода мы будем использовать [`clang-format`](https://clang.llvm.org/docs/ClangFormat.html).

1. Install `clang-format`
    - `brew install clang-format`
1. Check `clang-format` version to validate installation is complete
    - `clang-format --version`

# [`VCS`](https://en.wikipedia.org/wiki/Version_control): Version Control System

Нашей системой контроля версий будет [`git`](https://git-scm.com).

1. Install `git`
    - `brew install git`
1. Check `git` version
    - `git --version`
1. Initial Setup ([Docs](https://docs.github.com/en/get-started/getting-started-with-git))
    - Username: `git config --global user.name "Mona Lisa"`
    - Email: `git config --global user.email "email@example.com"`
    - Validate: `git config --global -l`

# [GitHub](github.com)

Работа будет вестиcь в общем репозитории на [`GitHub`](github.com).

1. Create/Login to your account on [GitHub](github.com)
1. Generate and add SSH key following the [guide](https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh/about-ssh)

# VSCode Setup

VSCode поддерживает `clang` и `clang-format` из коробки. Для этого просто нужно установить официальный плагин для `C++`:
  - [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

# Hello World App

Чтобы проверить, что всё нормально работает, давайте напишем простенькое `Hello World` приложение.

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
  - https://docs.github.com/en/get-started/quickstart/set-up-git
  - https://docs.github.com/en/get-started/getting-started-with-git
  - https://github.com/git-guides
  - https://en.wikipedia.org/wiki/Version_control
  - https://en.wikipedia.org/wiki/Git
- [GitHub](github.com)
