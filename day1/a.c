/** @see https://adventofcode.com/2024/day/1 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOCATIONS 2000

int comparator(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int left_list[MAX_LOCATIONS];
    int right_list[MAX_LOCATIONS];

    int location_count = 0;

    long long int sum = 0;

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

    qsort(left_list, location_count, sizeof(int), comparator);
    qsort(right_list, location_count, sizeof(int), comparator);

    for (int i = 0; i < location_count; i++)
    {
        sum += llabs((long long)left_list[i] - right_list[i]);
    }

    printf("%lld\n", sum);

    return 0;
}
