# Repository Instructions

LeetCode & NeetCode problem-solving workspace in modern C++ (C++23).

---

## Core Rule: Scaffolding Only

Whenever a problem is provided (URL, title, or requests like "set this problem", "next problem"):
- **Never implement the algorithm.** Scaffolding only.
- Set up `main.cpp` so the user can immediately implement and test the solution themselves.

---

## Problem Setup Workflow

1. **Archive Check**:
   - If `main.cpp` contains an unarchived solution, save it to `archive/leetcode/<slug>.cpp` or `archive/neetcode/<slug>.cpp` (using the URL slug in kebab-case).

2. **Scaffold `main.cpp`**:

   - **Header Comment**: Strictly minimal — 5 lines only (Number/Title, Difficulty, Link):
     ```cpp
     /**
      * 1. Two Sum
      * Difficulty: Easy
      * Link: https://leetcode.com/problems/two-sum/description/
      */
     ```

   - **Headers & Namespace**:
     Include `#include <print>` (C++23), `<vector>`, `<string>`, `<algorithm>`, `<iostream>`, and any container headers needed (`<queue>`, `<stack>`, `<unordered_map>`, etc.), followed by `using namespace std;`.

   - **Data Structures (if needed)**:
     For Linked List or Tree problems, include standard LeetCode definitions (`ListNode`, `TreeNode`) and simple helper functions so test cases in `main()` can construct and print them.

   - **`class Solution`**:
     - Exact class and method signature from the problem.
     - Body contains ONLY parameter suppression (e.g. `(void)nums;`) to prevent `-Wunused-parameter` warnings, a dummy return (`return 0;`, `return {};`, `return false;`), and `// TODO: Implement solution`.

   - **`int main()`**:
     - Instantiate `Solution sol;`.
     - Wrap each example test case in its own block `{ ... }` to avoid variable name collisions and allow easy commenting.
     - Print `Output` and `Expected` using `println(...)`.

3. **Verify Build**:
   - Run `make` to ensure `main.cpp` compiles with zero warnings and zero errors.

---

## Workspace & Build Commands

- `main.cpp`: Active problem development.
- `archive/leetcode/<slug>.cpp`, `archive/neetcode/<slug>.cpp`: Archived solutions.

### Commands
- `make` : Build `main.cpp`
- `make run` : Build and run `main.cpp`
- `make debug` : Launch LLDB on `build/main`
- `make SRC='archive/leetcode/<slug>.cpp' run` : Build and run a specific archived file
- `make clean` : Remove build artifacts
