// Reference: https://onlinejudge.org/external/100/10041.pdf

#include <stdio.h>
#include <stdlib.h>

// Maximum 500 street numbers
#define MAX_STREET_NUMBERS 500

// Solution: Finding the Median Street-Number (Has the most appropriate house) -> Finding distances to each other house
//    1) Finding the median - Requires greedy all the street numbers and choosing the middle one
//    2) Finding the distances - Simply adding absolute differences together

// Comparator for greedy integers in ASCENDING order
int int_cmp(const void* item1, const void* item2) {
    return (*((int*) item1) - *((int*) item2));
}

int main() {
    int inputs_count; // Number of the inputs
    int relatives_count; // Number of the relatives
    int relatives_street_numbers[MAX_STREET_NUMBERS]; // Street Number of each Relative (Relative-Indexed array)
    int median_street_number; // Median Street-Number (NOT the index - Actual number)
    int total_distance; // Total distance (Sum of Absolute-Differences)

    scanf("%i", &inputs_count);

    while (inputs_count--) {
        scanf("%d", &relatives_count);

        if (relatives_count == 0) continue;;

        for (int i = 0; i < relatives_count; i++) {
            scanf("%d", &relatives_street_numbers[i]);
        }

        // Performing Quick-Sort
        //   1. Input-array to be sorted
        //   2. Length of the array (Number of items)
        //   3. Size of each item
        //   4. Comparator for comparing items against each other -> ASC / DESC ordering
        qsort(relatives_street_numbers, relatives_count, sizeof(int), int_cmp);

        median_street_number = relatives_street_numbers[relatives_count / 2];

        total_distance = 0;

        for (int i = 0; i < relatives_count; i++) {
            total_distance += abs(relatives_street_numbers[i] - median_street_number);
        }

        printf("%d\n", total_distance);
    }

    return 0;
}
