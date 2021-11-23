# Практика

1. Задача практикума - написать игру, которая будет играть сама в себя. То, что мы должны получить:
    - Игровое поле, представляющее собой граф.
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
1. Каждая задача рассчитана на определенное время выполнения и количество баллов.
   За каждую неделю задержки отнимается по `5` баллов.
   За каждые `-10` баллов в конце семестра, нужно будет выполнить допольнительную задачу.

# Plan

- Неделя 0. [Initial Setup](initial_setup)
- Неделя 1. [Hello World!](task_01)
- Неделя 2. [Graph Generation](task_02)
- Неделя 3. [JSON Representation](task_03)
- Неделя 4. [Generation Probabilities](task_04)
- Неделя 5. [Multiple Graphs and Logger](task_05)
- Неделя 6. [Concurrent Graphs Generation](task_06)
- Неделя 7. [Shortest Path Algorith](./)
  - Add Edge Durations
  - Single Pair (Sequential Algorithm)
- Неделя 8. [Shortest Path Algorith](./)
  - Single Pair (Parallel Algorithm)
- Неделя 9. [Graph Development](./)
  - Add Params, Fights and Blessings
- Неделя 10. [Shortest Path Algorith](./)
  - Multiple Pair (Parallel Algorithm)
- Неделя 11. [Graph Development](./)
  - Adjustable Params (Parallel)
  - Add Enemies and Blessings
- Неделя 12. [Graph Development](./)
  - Multiple Players (Parallel)
  - Add Enemies and Blessings
- ...

Подробные описания задач готовятся по мере вашего прогресса.

# Разделы

- [Rules](rules.md)
- [Workflow](workflow.md)
- [Naming Convention](naming_convention.md)
- [`C` vs `C++`](c_vs_cpp.md)
- [Common Mistakes](common_mistakes.md)
