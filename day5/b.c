#include <errno.h>
#include <malloc/_malloc_type.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long sum = 0;

typedef struct rules_t {
  int a;
  int b;
} rules_t;

int compare(int a, int b, rules_t *rules, int rules_count) {
  for (int i = 0; i < rules_count; i++) {
    int first = rules[i].a;
    int second = rules[i].b;

    if (a == first && b == second) {
      return -1;
    }

    if (a == second && b == first) {
      return 1;
    }
  }

  return 0;
}

int check_validity(int *accumulator, rules_t *rules, int num_rules,
                   int num_elements) {

  int first_index = -1;
  int second_index = -1;
  int correct = 1;

  for (int k = 0; k < num_rules; k++) {
    int first = rules[k].a;
    int second = rules[k].b;

    for (int i = 0; i < num_elements; i++) {
      if (accumulator[i] == first) {
        first_index = i;
      }

      if (accumulator[i] == second) {
        second_index = i;
      }
    }

    if (first_index != -1 && second_index != -1) {
      if (first_index > second_index) {
        correct = 0;
      }
    }

    first_index = -1;
    second_index = -1;
  }

  if (correct == 0) {
    for (int i = 0; i < num_elements - 1; i++) {
      for (int j = 0; j < num_elements - i - 1; j++) {
        int resp =
            compare(accumulator[j], accumulator[j+1], rules, num_rules);

        if (resp == 1) {
          int temp = accumulator[j];
          accumulator[j] = accumulator[j+1];
          accumulator[j+1] = temp;
        }
      }
    }

    int mid = num_elements / 2;
    return accumulator[mid];
  }

  return 0;
}

int main() {
  FILE *file = fopen("input.txt", "r");

  if (file == NULL) {
    perror("Unable to open file.\n");
    return -1;
  }

  fseek(file, 0, SEEK_END);

  size_t size = ftell(file);

  fseek(file, 0, SEEK_SET);

  char buf[size + 1];

  size_t bytes_read = fread(buf, sizeof(char), size, file);

  buf[bytes_read] = '\0';

  int rules_boundary = -1;

  for (int i = 0; i < size; i++) {
    if (buf[i] == 0x0a && buf[i + 1] == 0x0a) {
      rules_boundary = i + 1; // include final \n for rules
      break;
    }
  }

  int updates_start = rules_boundary + 1;

  rules_t *rules = malloc(rules_boundary * sizeof(rules_t));

  if (rules == NULL) {
    perror("Unable to allocate memory.\n");
    return -1;
  }

  int a, b, number_of_rules = 0;

  for (int i = 0; i < rules_boundary; i += 6) {
    if (sscanf(buf + i, "%d|%d", &a, &b) == 2) {
      rules[number_of_rules].a = a;
      rules[number_of_rules++].b = b;
    }
  }

  char *end = NULL;
  char *input = buf + updates_start;
  int count = 0;
  int *accumulator = calloc(64, sizeof(int));

  while (*input != '\0') {
    long number = strtol(input, &end, 10);

    if (end == input) {
      printf("Nothing to read.\n");
      break;
    }

    accumulator[count++] = number;

    input = end;

    if (*input == 0x2c) {
      input++;
    } else if (*input == 0x0a) {
      int mid = check_validity(accumulator, rules, number_of_rules, count);
      sum += mid;
      count = 0;
      input++;
    }
  }

  free(rules);
  free(accumulator);

  printf("sum: %lld\n", sum);
}
