#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 4096

int main()
{
    char buffer[MAX_LINE_LENGTH];

    bool is_enabled = true;

    FILE* file = fopen("input.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    long long int sum = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        const size_t length = strlen(buffer);

        for (size_t i = 0; i < length; i++)
        {
            if (strncmp(buffer + i, "don't()", 7) == 0)
            {
                is_enabled = false;
                i += (7 - 1); // for loop advances by 1 automatically
            }

            else if (strncmp(buffer + i, "do()", 4) == 0)
            {
                is_enabled = true;
                i += (4 - 1); // for loop advances by 1 automatically
            }

            if (is_enabled && strncmp(buffer + i, "mul(", 4) == 0)
            {
                int number1, number2;
                int chars_consumed = 0; // To store how many characters sscanf reads

                char next_char;

                const int items_scanned = sscanf(buffer + i + 4, "%d,%d%c%n", &number1, &number2, &next_char,
                                                 &chars_consumed);

                if (items_scanned == 3 && next_char == ')')
                {
                    sum += (long long)number1 * number2;
                    i += 4 + chars_consumed - 1;
                    // The -1 is because the for loop will add 1 back on the next iteration.
                }
            }
        }
    }

    fclose(file);
    printf("%lld\n", sum);
    return 0;
}
