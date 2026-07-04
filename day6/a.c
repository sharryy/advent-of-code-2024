#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define OBSTACLE '#'

typedef enum direction_t { NORTH, EAST, SOUTH, WEST } direction_t;

int already_visited(char *table, int position) {
  if (table[position] == 1) {
    return 1;
  }

  return 0;
}

void visit_location(char *table, int position) { table[position] = 1; }

int main() {
  FILE *file = fopen("input.txt", "r");

  if (file == NULL) {
    perror("Unable to open the file.\n");
    return -1;
  }

  fseek(file, 0, SEEK_END);

  size_t size = ftell(file);

  fseek(file, 0, SEEK_SET);

  char *buffer = calloc(size + 1, 1);

  fread(buffer, 1, size, file);

  buffer[size] = '\0';

  int columns = -1;

  for (int i = 0; i < size; i++) {
    if (buffer[i] == 0x0a) {
      columns = i;
      break;
    }
  }

  int position = -1;
  direction_t direction = NORTH;

  for (int i = 0; i < size; i++) {
    if (buffer[i] == '^') {
      position = i;
      direction = NORTH;
      break;
    }
  }

  int count = 0;
  int move = 1;

  char *lookup_table = calloc(size + 1, sizeof(int));

  if (lookup_table == NULL) {
    perror("Unable to allocate hash table.\n");
    return -1;
  }

  char marker[] = {'^', '>', 'v', '<'};
  int offsets[] = {-(columns + 1), +1, +(columns + 1), -1};

  while (move) {
    int new_pos = position + offsets[direction];

    if (new_pos >= 0 && new_pos < size) {
      if (buffer[new_pos] != OBSTACLE) {
        buffer[new_pos] = marker[direction];
        position = new_pos;
        if (!already_visited(lookup_table, new_pos)) {
          visit_location(lookup_table, new_pos);
          count++;
        }
      } else {
        direction = (direction + 1) % 4;
        buffer[position] = marker[direction];
      }
    } else {
      move = 0;
    }
  }

  for (int i = 0; i < size; i++) {
    printf("%c", buffer[i]);
  }

  printf("\n");

  printf("visited: %d\n", count);
}
