#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

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
  int direction = 1;

  for (int i = 0; i < size; i++) {
    if (buffer[i] == '^') {
      position = i;
      direction = 1;
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

  while (move) {

    switch (direction) {
    case 1:
      // "NORTH"
      {
        int new_position = position - (columns + 1);

        if (new_position >= 0 && new_position < size) {
          if (buffer[new_position] != '#') {
            buffer[new_position] = '^';
            position = new_position;
            if (!already_visited(lookup_table, new_position)) {
              visit_location(lookup_table, new_position);
              count++;
            }
          } else {
            direction = 3;
            buffer[position] = '>';
          }
        } else {
          move = 0;
        }
      }

      break;
    case 2:
      // "SOUTH"
      {
        int new_position = position + (columns + 1);

        if (new_position >= 0 && new_position < size) {
          if (buffer[new_position] != '#') {
            buffer[new_position] = 'v';
            position = new_position;
            if (!already_visited(lookup_table, new_position)) {
              visit_location(lookup_table, new_position);
              count++;
            }
          } else {
            direction = 4;
            buffer[position] = '<';
          }
        } else {
          move = 0;
        }
      }

      break;
    case 3: {
      // "EAST"

      int new_position = position + 1;

      if (new_position >= 0 && new_position < size) {
        if (buffer[new_position] != 0x0a && buffer[new_position] != '#') {
          buffer[new_position] = '>';
          position = new_position;
          if (!already_visited(lookup_table, new_position)) {
            visit_location(lookup_table, new_position);
            count++;
          }
        } else {
          direction = 2;
          buffer[position] = 'v';
        }
      } else {
        move = 0;
      }
    }

    break;
    case 4:
      // "WEST"
      {
        int new_position = position - 1;

        if (new_position >= 0 && new_position < size) {
          if (buffer[new_position] != 0x0a && buffer[new_position] != '#') {
            buffer[new_position] = '<';
            position = new_position;
            if (!already_visited(lookup_table, new_position)) {
              visit_location(lookup_table, new_position);
              count++;
            }
          } else {
            direction = 1;
            buffer[position] = '^';
          }
        } else {
          move = 0;
        }
      }

      break;
    }
  }

  for (int i = 0; i < size; i++) {
    printf("%c", buffer[i]);
  }

  printf("\n");

  printf("visited: %d\n", count);
}
