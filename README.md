# Advent of Code 2024 — C Assignment

## Assignment Overview
- Solve any four parts from the 2024 Advent of Code challenge using the C programming language.
- Each part (either Part 1 or Part 2) counts as one solved problem; you may mix and match days and parts.
- Submit your solutions as either a `.zip` archive of the C sources or a public GitHub repository link, including plain-text explanations for each part.

## Project Layout
- `day1/a.c`, `day1/b.c` — Solutions for Day 1 Parts A and B with shared `input.txt`.
- `day2/a.c`, `day2/b.c` — Solutions for Day 2 Parts A and B with shared `input.txt`.
- `dayN/a.md`, `dayN/b.md` — Per-part walkthroughs describing problem analysis, algorithm choices, and verification notes.

## Build & Run
1. Configure the project (optional if compiling directly):
   ```sh
   cmake -S /Users/sharryy/CLionProjects/advent-of-code -B /Users/sharryy/CLionProjects/advent-of-code/cmake-build-debug
   ```
2. Build and run a specific part, for example Day 1 Part A:
   ```sh
   cmake --build /Users/sharryy/CLionProjects/advent-of-code/cmake-build-debug --target day1_a
   /Users/sharryy/CLionProjects/advent-of-code/cmake-build-debug/day1/day1_a
   ```
3. Alternatively, compile a file directly with `clang` or `gcc`:
   ```sh
   clang -O3 -std=c17 /Users/sharryy/CLionProjects/advent-of-code/day1/a.c -o day1_part1
   ./day1_part1
   ```

## Packaging for Submission
- Ensure each solution file follows the required naming convention `Day[Number]_part[Number].c` and each explanation file follows `Day[Number]_part[Number].txt`.
- Archive the selected source files and their accompanying explanation text files into a single `.zip`, or push them to a GitHub repository and share the link.
- Include the per-part README files to document reasoning and verification steps.

## Academic Integrity
- Generative AI assistance is permitted, but you must be able to explain every line of code and the reasoning behind your approach.
- Keep copies of inputs, outputs, and notes to support discussion or oral defenses if required.
