#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 140
#define COLUMNS 140
#define XMAS "XMAS"

typedef enum
{
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST,
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST,
    NUM_DIRECTIONS
} direction_t;

typedef struct
{
    int dx;
    int dy;
} direction_vector_t;

const direction_vector_t DIRECTIONS[NUM_DIRECTIONS] = {
    {-1, 0}, // NORTH
    {-1, 1}, // NORTH-EAST
    {0, 1}, // EAST
    {1, 1}, // SOUTH-EAST
    {1, 0}, // SOUTH
    {1, -1}, // SOUTH-WEST
    {0, -1}, // WEST
    {-1, -1} // NORTH-WEST
};


void traverse(char grid[][COLUMNS], int row, int col, int* words_count)
{
    // TODO: Implement Traversing Of Graph
}

int main()
{
    char grid[ROWS][COLUMNS];
    char buffer[COLUMNS + 2]; // +1 for null terminator, +1 for newline
    int rows_read = 0;
    int words_count = 0;

    FILE* file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    while (rows_read < ROWS && fgets(buffer, sizeof(buffer), file) != NULL)
    {
        strncpy(grid[rows_read++], buffer, COLUMNS);
    }

    fclose(file);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (grid[i][j] == XMAS[0])
            {
                traverse(grid, i, j, &words_count);
            }
        }
    }

    printf("%d\n", words_count);
}
