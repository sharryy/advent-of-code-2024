# Advent of Code 2024 — C Assignment

## Assignment Overview
- Solve any four parts from the 2024 Advent of Code challenge using the C programming language.
- Each part (either Part 1 or Part 2) counts as one solved problem; you may mix and match days and parts.
- Submit your solutions as either a `.zip` archive of the C sources or a public GitHub repository link, including plain-text explanations for each part.

## Project Layout
- `day1/a.c`, `day1/b.c` — Solutions for Day 1 Parts A and B with shared `input.txt`.
- `day2/a.c`, `day2/b.c` — Solutions for Day 2 Parts A and B with shared `input.txt`.
- `dayN/a.txt`, `dayN/b.txt` — Plain-text walkthroughs describing problem analysis, algorithm choices, and verification notes.

## Build & Run

Each solution reads from `input.txt` in its respective directory. Compile and run from within each day's folder:

```sh
# Day 1 Part 1
cd day1
clang -o3 -std=c17 a.c -o a
./a

# Day 1 Part 2
clang -o3 -std=c17 b.c -o b
./b

# Day 2 Part 1
cd day2
clang -o3 -std=c17 a.c -o a
./a

# Day 2 Part 2
clang -o3 -std=c17 b.c -o b
./b
```

You can also use `gcc` instead of `clang`:
```sh
gcc -O3 -std=c17 a.c -o a
```

## Packaging for Submission
- Ensure each solution file follows the required naming convention `Day[Number]_part[Number].c` and each explanation file follows `Day[Number]_part[Number].txt`.
- Archive the selected source files and their accompanying explanation text files into a single `.zip`, or push them to a GitHub repository and share the link.
- Include the per-part README files to document reasoning and verification steps.

## Academic Integrity
- Generative AI assistance is permitted, but you must be able to explain every line of code and the reasoning behind your approach.
- Keep copies of inputs, outputs, and notes to support discussion or oral defenses if required.
