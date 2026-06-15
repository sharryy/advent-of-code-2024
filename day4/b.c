#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("input.txt", "r");

  if (file == NULL) {
    perror("Unable to open the file");
    return -1;
  }

  fseek(file, 0, SEEK_END);

  long int file_size = ftell(file);

  char *buffer = malloc(file_size * sizeof(char) + 1);

  fseek(file, 0, SEEK_SET);

  size_t bytes_read = fread(buffer, sizeof(char), file_size, file);

  buffer[bytes_read] = '\0';

  long int width = -1;

  for (size_t i = 0; i < file_size; i++) {
    if (buffer[i] == '\n') {
      width = i;
      break;
    }
  }

  long int rows = (file_size + 1) / (width + 1);

  printf("rows: %ld - width: %ld\n", rows, width);

  long int count = 0;

  for (size_t i = 1; i < rows - 1; i++) {
    for (size_t j = 1; j < width - 1; j++) {
      size_t idx = i * (width + 1) + j;
      size_t top_left_idx = idx - (width + 1) - 1;
      size_t top_right_idx = idx - (width + 1) + 1;
      size_t bottom_left_idx = idx + (width + 1) - 1;
      size_t bottom_right_idx = idx + (width + 1) + 1;

      if (buffer[idx] != 'A') {
        continue;
      } else {
        if (buffer[top_left_idx] == 'M' &&
            buffer[bottom_right_idx] == 'S' &&
            buffer[top_right_idx] == 'M' &&
            buffer[bottom_left_idx] == 'S') {
          count++;
        }

        if (buffer[top_left_idx] == 'M' &&
            buffer[bottom_right_idx] == 'S' &&
            buffer[top_right_idx] == 'S' &&
            buffer[bottom_left_idx] == 'M') {
          count++;
        }

        if (buffer[top_left_idx] == 'S' &&
            buffer[bottom_right_idx] == 'M' &&
            buffer[top_right_idx] == 'M' &&
            buffer[bottom_left_idx] == 'S') {
          count++;
        }

        if (buffer[top_left_idx] == 'S' &&
            buffer[bottom_right_idx] == 'M' &&
            buffer[top_right_idx] == 'S' &&
            buffer[bottom_left_idx] == 'M') {
          count++;
        }
      }
    }
  }

  printf("count: %ld\n", count);
}
