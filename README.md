# My C Journy: From Syntax to Systems

A disciplined journey to master the "mother of all languages." This repository tracks my daily progress as I move from basic logic to low-level systems programming.

## The Philosophy
* **The Man Page Protocol:** Read the `man` pages (Section 2 & 3) before searching for tutorials.
* **Manual Memory:** Understand what is happening on the Stack vs. the Heap.
* **Zero Magic:** No high-level abstractions—just C and the Standard Library.

---

## 🛠 Phase 1: The Foundation Builders
*Focus: Mastering the Standard Library and Logic Basics.*

| Day | Project | Status | Key Concept |
| :--- | :--- | :---: | :--- |
| 01 | [Unit Converter](./Phase1/01_unit_conv.c) | 🏗️ | `scanf`, `printf`, Floats |
| 02 | [Grade Calc](./Phase1/02_grade_calc.c) | ⏳ | Control Flow (If/Else) |
| 03 | [Number Guesser](./Phase1/03_guessing.c) | ⏳ | `rand()`, `srand()`, `time.h` |
| 04 | [String Reverser](./Phase1/04_reverser.c) | ⏳ | Arrays & Null Terminators |
| 05 | [Password Sanitizer](./Phase1/05_sanitizer.c) | ⏳ | `ctype.h` & Logic Flags |
| 06 | [File Cat](./Phase1/06_cat.c) | ⏳ | File Pointers & `EOF` |
| 07 | [Word Counter](./Phase1/07_word_count.c) | ⏳ | State Logic & `fgets` |
| 08 | [Dynamic Array](./Phase1/08_malloc.c) | ⏳ | `malloc`, `free`, The Heap |
| 09 | [Phonebook](./Phase1/09_structs.c) | ⏳ | Structs & Memory Layout |
| 10 | [Simple Timer](./Phase1/10_timer.c) | ⏳ | `unistd.h` & `sleep()` |

---

## 📖 Essential Commands

### Compilation
To compile a project using the GNU Compiler Collection (GCC):
```bash
gcc -Wall -Wextra -Werror project.c -o project

> **Note:** `-Wall -Wextra -Werror` ensures the compiler tells me about every possible mistake.

### Documentation
To access the manual pages directly from the terminal:

* `man 3 printf` (Library functions)
* `man 2 open` (System calls)

### Future Milestones
- [ ] **Phase 2:** Intermediate Logic (Pointers, Recursion, Bitwise Ops)
- [ ] **Phase 3:** Data Structures (Linked Lists, Binary Trees)
- [ ] **Phase 4:** Systems Programming (Process Forking, Sockets, Threads)