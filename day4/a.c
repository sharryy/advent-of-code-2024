#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error Opening the File");
        return 1;
    }

    fseek(file, 0, SEEK_END);

    long int file_size = ftell(file);

    char* buffer = malloc(file_size * sizeof(char) + 1);

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

    if (width == -1) {
        perror("Unable to find width through new-line.\n");
        return -1;
    }

    long int count = 0;

    size_t rows = (file_size + 1)/(width + 1);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < width - 3; j++) {
            size_t idx = i * (width + 1) + j;
            if (buffer[idx] == 'X' && buffer[idx + 1] == 'M' && buffer[idx + 2] == 'A' && buffer[idx + 3] == 'S') {
                count++;
            }
        }
    }

    printf("count: %ld\n", count);


    free(buffer);

    return 0;
}
