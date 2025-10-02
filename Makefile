CC       ?= clang
CFLAGS   ?= -O3 -std=c17 -Wall -Wextra -pedantic
BIN_DIR  := build

DAY1_PART1 := $(BIN_DIR)/day1_part1
DAY1_PART2 := $(BIN_DIR)/day1_part2
DAY2_PART1 := $(BIN_DIR)/day2_part1
DAY2_PART2 := $(BIN_DIR)/day2_part2

TARGETS := $(DAY1_PART1) $(DAY1_PART2) $(DAY2_PART1) $(DAY2_PART2)

.PHONY: all run clean day1_part1 day1_part2 day2_part1 day2_part2

all: $(TARGETS)

run: all
	@echo "\nDay 1 Part 1"
	./$(DAY1_PART1) < day1/input.txt
	@echo "\nDay 1 Part 2"
	./$(DAY1_PART2) < day1/input.txt
	@echo "\nDay 2 Part 1"
	./$(DAY2_PART1) < day2/input.txt
	@echo "\nDay 2 Part 2"
	./$(DAY2_PART2) < day2/input.txt

clean:
	rm -rf $(BIN_DIR)

day1_part1: $(DAY1_PART1)
	./$(DAY1_PART1) < day1/input.txt

day1_part2: $(DAY1_PART2)
	./$(DAY1_PART2) < day1/input.txt

day2_part1: $(DAY2_PART1)
	./$(DAY2_PART1) < day2/input.txt

day2_part2: $(DAY2_PART2)
	./$(DAY2_PART2) < day2/input.txt

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(DAY1_PART1): day1/a.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(DAY1_PART2): day1/b.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(DAY2_PART1): day2/a.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(DAY2_PART2): day2/b.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@
