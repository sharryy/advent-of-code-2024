#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LEVELS_PER_LINE 100

bool is_report_safe(const int report[], const int count)
{
    if (count < 2)
    {
        return false;
    }

    const int first_diff = report[1] - report[0];

    int diff_abs = abs(first_diff);

    if (diff_abs == 0 || diff_abs > 3)
    {
        return false;
    }

    const int expected_direction = (first_diff > 0) ? 1 : -1;

    for (int i = 1; i < count - 1; i++)
    {
        const int current_diff = report[i + 1] - report[i];

        diff_abs = abs(current_diff);

        const int current_direction = (current_diff > 0) ? 1 : -1;

        if (diff_abs == 0 || diff_abs > 3 || current_direction != expected_direction)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    char buffer[MAX_LINE_LENGTH];

    FILE* file = fopen("input.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int safe_reports_count = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int report[MAX_LEVELS_PER_LINE];
        int level_count = 0;

        char* token = strtok(buffer, " \t\n");

        while (token != NULL && level_count < MAX_LEVELS_PER_LINE)
        {
            report[level_count++] = atoi(token);
            token = strtok(NULL, " \t\n");
        }

        if (is_report_safe(report, level_count))
        {
            safe_reports_count++;
        }
    }

    fclose(file);
    printf("%d\n", safe_reports_count);

    return 0;
}
