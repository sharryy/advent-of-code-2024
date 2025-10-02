/** @see https://adventofcode.com/2024/day/1 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOCATIONS 2000

typedef struct
{
    int value;
    int count;
} frequency_t;

int comparator(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int freq_comparator(const void* a, const void* b)
{
    const int key = *(int*)a;

    const frequency_t* item = b;

    return key - item->value;
}

int main(void)
{
    int left_list[MAX_LOCATIONS];
    int right_list[MAX_LOCATIONS];

    int location_count = 0;

    long long int similarity = 0;

    FILE* file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    while (location_count < MAX_LOCATIONS && fscanf(file, "%d %d", &left_list[location_count],
                                                    &right_list[location_count]) == 2)
    {
        location_count++;
    }

    fclose(file);

    qsort(right_list, location_count, sizeof(int), comparator);

    frequency_t frequency[MAX_LOCATIONS];

    int unique_count = 0;

    if (location_count > 0)
    {
        frequency[0].value = right_list[0];
        frequency[0].count = 1;
        unique_count = 1;

        for (int i = 1; i < location_count; i++)
        {
            if (right_list[i] == right_list[i - 1])
            {
                frequency[unique_count - 1].count++;
            }
            else
            {
                frequency[unique_count].value = right_list[i];
                frequency[unique_count].count = 1;
                unique_count++;
            }
        }
    }

    for (int i = 0; i < location_count; i++)
    {
        int number_left = left_list[i];

        const frequency_t* found = bsearch(&number_left, frequency, unique_count, sizeof(frequency_t), freq_comparator);

        if (found != NULL)
        {
            similarity += (long long)number_left * found->count;
        }
    }

    printf("%lld\n", similarity);

    return 0;
}
