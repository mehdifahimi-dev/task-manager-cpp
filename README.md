# Task Manager (C++)

## Overview
A terminal-based task manager built in C++ to practice object-oriented programming and modular application design. Built as part of my C++ learning journey, focusing on clean architecture and structured code.

---

## Features
- Add new tasks
- Remove tasks
- View all tasks
- Menu-driven user interface
- Input validation for user commands

---

## Concepts Used
- Object-Oriented Programming (classes, encapsulation)
- Modular design with separated concerns
- Control flow and user interaction
- Basic memory management

---

## Technologies
- C++14
- VS Code
- Git

---

## Prerequisites
- g++ compiler with C++14 support

---

## How to Run

**Compile:**
```bash
g++ -std=c++14 -o task_manager *.cpp
```

**Run:**
```bash
./task_manager
```

---

## Notes
This application stores data in memory during runtime — all tasks reset when the program is closed. This was intentional to keep the focus on:
- Core application logic
- System design
- Object-oriented structure

---

## Future Improvements
- Add file persistence (save/load tasks)
- Improve user interface
- Add task categories and priorities
- Implement database support (e.g., SQLite)
