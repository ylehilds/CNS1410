# C++ Programming Fundamentals & OOP

A portfolio-ready collection of **C++ programming exercises, labs, and small projects**. The work progresses from basic syntax and control flow to **modular design and object-oriented programming**, with an emphasis on clean code, problem decomposition, and the Standard Library. All source material lives under `src/`.

## What This Repository Covers
- **Core C++ syntax & control flow:** variables, types, operators, `if/else`, loops, console I/O.
- **Functions & modularity:** headers vs. implementations, parameter passing, return semantics.
- **Data handling:** arrays, C-strings and `std::string`, `std::vector`, basic algorithms.
- **Memory model:** references vs. values, pointers, RAII mindset, dynamic allocation where appropriate.
- **Object-Oriented Programming:** classes, encapsulation, constructors/destructors, operator overloading; introductions to inheritance and polymorphism.
- **File I/O & parsing:** reading/writing structured data, basic error handling.
- **Applied practice:** focused console apps and exercises that showcase each concept.

## Tech Stack
- **Language:** C++ (C++14 or later recommended).
- **Toolchains:** `g++`, `clang++`, or MSVC.
- **IDEs:** CLion, Visual Studio, or VS Code (C/C++ extensions), MinGW.
- **Dependencies:** Standard Library (STL) only; projects are intentionally light on third-party libraries to emphasize fundamentals.
- **Testing approach:** console output checks; you can optionally add a lightweight unit test framework (e.g., doctest/Catch2) per exercise.

## Repository Structure (typical)
    src/
      ├─ labs/                 # Guided labs aligned with weekly topics
      ├─ Projects/             # Cumulative assignments that combine multiple concepts
      ├─ my_own_exercises/     # Personal drills and extra practice
      └─ utils/                # (Optional) shared headers and helpers
    README.md
    LICENSE
*Note: Exact folder names may vary; explore `src/` to view the available assignments and exercises.*

## Getting Started
**Prerequisites**
- A modern C++ compiler and basic build tools.
- (Optional) An IDE for easier navigation and debugging.

**Clone**

    git clone https://github.com/ylehilds/CNS1410.git
    cd CNS1410

**Quick compile (single file)**

    # From repo root; replace the path with any source file you want to run
    g++ -std=c++14 -O2 -Wall -Wextra -o program src/labs/lab1.cpp
    ./program

**Compile multiple sources**

    # Example: build a project composed of multiple .cpp files
    g++ -std=c++14 -O2 -Wall -Wextra src/Projects/Project1/*.cpp -o project1
    ./project1

**(Optional) CMake workflow (if a CMakeLists.txt is present in a subfolder)**

    mkdir -p build
    cd build
    cmake ..
    cmake --build .
    ./<target-name>

**IDE workflow (recommended for exploration)**
1. Open the folder in CLion / Visual Studio / VS Code / MinGW.
2. Mark `src/` as your source root if prompted.
3. Build and run any lab or project; set breakpoints to step through logic.

## Tips for Clean Builds & Debugging
- Enable warnings: add `-Wall -Wextra -Wpedantic`; for MSVC, use `/W4`.
- Debug builds: add `-g` (GCC/Clang) and consider `-fsanitize=address,undefined` to catch memory and UB issues.
- Separate logic from I/O: write pure functions where possible; it simplifies testing and reuse.
- Prefer Standard Library containers/algorithms (`std::vector`, `std::sort`, `std::accumulate`) for clarity and safety.

## Topics & Learning Outcomes
- Program structure, compilation model, and headers/implementation separation.
- Flow control, iteration patterns, and input validation.
- Designing and using functions; basic API design and documentation.
- Data representation (strings, arrays, vectors) and algorithmic thinking.
- OOP patterns in C++: class design, invariants, and operator overloads.
- Introduction to inheritance, virtual functions, and polymorphism.
- Persistent data with file streams and simple parsing strategies.

## Why It’s Portfolio-Worthy
- **Breadth → depth:** clear progression from basics to OOP, with runnable artifacts.
- **Readable code:** small, focused programs that demonstrate best practices.
- **Interview-friendly:** examples that are easy to open, compile, and step through.
- **Extensible:** a strong base to add unit tests, refactors, profiling, and advanced features.

## Ideas for Future Enhancements
- Add unit tests (doctest/Catch2) and a simple CI workflow (GitHub Actions) to build selected targets.
- Introduce additional STL containers (`std::map`, `std::set`, `std::queue`) and problem-focused exercises.
- Create a small “toolbox” library in `utils/` (input parsing, formatting, math helpers).
- Provide datasets and expected outputs for reproducible I/O-driven assignments.
- Add a top-level CMake build to unify compilation of multiple labs/projects.

## License & Author
- **License:** MIT — see `LICENSE`.
- **Author:** Lehi Alcantara — https://www.lehi.dev — lehi@lehi.dev