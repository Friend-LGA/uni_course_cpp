# Practice

1. Задача практикума - используя инструменты `C++ 17` и объектно-ориентированное программирование написать игру, которая будет играть сама в себя. То, что мы должны получить в итоге:
    - Игровое поле, представляющее собой граф (дерево).
    - В начале этого поля находится рыцарь.
    - В конце этого поля находится принцесса.
    - Переход между клетками игрового поля (вершинами графа) занимает определенное время.
    - При переходе есть вероятность что рыцарь наткнется на противника (дракон, виверна, тролль, и т.д.) и завяжется схватка.
    - У рыцаря и у его противников есть характеристики (здоровье, выносливость, атака, и т.д.).
    - Нужно найти кратчайший и наиболее безопасный пути к принцессе, а так же подобрать оптимальные характеристики для рыцаря.
1. Eсть общий репозиторий, к которому у всех есть/будет доступ.
   Каждая задача представляет собой `Pull Request` в этот репозиторий.
   Когда `Pull Request` прошел все проверки, одобрен мной и залит вами в `master`, тогда задача считается выполненной.
   Процесс работы подробно расписан в секции [Workflow](workflow.md).
1. Каждая задача рассчитана на определенное время выполнения.
   За каждую неделю задержки отнимается по `5` баллов.
   За каждые отнятые `10` баллов в конце семестра нужно будет выполнить дополнительную задачу.

# Sections

- [Rules](rules.md)
- [Workflow](workflow.md)
- [Naming Convention](naming_convention.md)
- [`C` vs `C++`](c_vs_cpp.md)
- [Common Mistakes](common_mistakes.md)

# Plan

- Неделя 0. [Initial Setup](initial_setup)
- Неделя 1. [Hello World!](task_01)
- Неделя 2. [Graph Generation](task_02)
- Неделя 3. [JSON Representation](task_03)
- Неделя 4. [Generation Probabilities](task_04)
- Неделя 5. [Multiple Graphs and Logger](task_05)
- Неделя 6. [Concurrent Edges Generation](task_06)
- Неделя 7. [Concurrent Graphs Generation](task_07)
- Неделя 8. [Concurrent Graphs Traversal](task_08)
- Неделя 9. [Basic Game](task_09)
- Неделя 10. [Advanced Game](./)
  - Add Params, Fights and Blessings
  - Adjustable Params (Parallel)
  - Add Enemies and Blessings
- Неделя 11. [Graph Development](./)
  - Multiple Players (Parallel)
  - Add Enemies and Blessings
- ...
