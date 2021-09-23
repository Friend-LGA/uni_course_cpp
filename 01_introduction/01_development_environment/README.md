# IDE: Development Environment

## Recomended IDE
- [Visual Studio Code](https://code.visualstudio.com/)
- [Atom](https://atom.io/)
- [Sublime Text](https://www.sublimetext.com/)

## If You Know What You're Doing
- [Vim](https://www.vim.org/)

Лично я рекомендую использовать `VSCode`.

# Compilation

1. Install `LLVM` and `clang` ([Docs](https://clang.llvm.org/))
    - `MacOS`: You should already have it
    - `Linux`: Use your favourite package manager
      - Пример:
        - `sudo apt install llvm`
        - `sudo apt install clang`
    - `Windows`: Should be possible to install with [Chocolate](https://community.chocolatey.org/)
      - `choco install llvm`
      - `choco install clang`
2. Check `clang++` version to validate installation is complete
    - `clang++ --version`

# Code Formatting, Linter

1. Install `clang-format` ([Docs](https://clang.llvm.org/docs/ClangFormat.html))
    - `MacOS`: Use [`homebrew`](https://brew.sh/)
      - `brew install clang-format`
    - `Linux`: Use your favourite package manager
      - Пример:
        - `sudo apt install clang-format`
    - `Windows`: Should be possible to install with [Chocolate](https://community.chocolatey.org/)
      - `choco install clang-format`
2. Check `clang-format` version to validate installation is complete
    - `clang-format --version`

Также его можно интегрировать в ваш `IDE`. К примеру для `VSCode` вы можете установить официальный плагин для `C++`, который включает в себя `clang-format`:
  - [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
