// Reference: https://leetcode.com/problems/daily-temperatures
// Worse solution: Relies too much on the limits / bounds of the temperature and iterates a little too much

#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

#define MAX_TEMP 100

int* daily_temperatures(int* temperatures, int temperatures_size, int* return_size){
    int* results = (int*) malloc(sizeof(int) * temperatures_size);
    *return_size = temperatures_size;

    int last_temp_day[MAX_TEMP + 1];

    for (int i = 0; i <= MAX_TEMP; i++) last_temp_day[i] = -1;

    int next_day_num;

    for (int i = temperatures_size - 1; i >= 0; i--) {
        next_day_num = -1;

        for (int j = temperatures[i] + 1; j <= MAX_TEMP; j++) {
            if (last_temp_day[j] != -1 && (next_day_num == -1 || last_temp_day[j] < next_day_num)) {
                next_day_num = last_temp_day[j];
            }
        }

        results[i] = next_day_num == -1 ? 0 : (next_day_num - i);
        last_temp_day[temperatures[i]] = i;
    }

    return results;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

// Input: temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
// Output: [1, 1, 4, 2, 1, 1, 0, 0]

int main() {
    int temperatures[8] = {73, 74, 75, 71, 69, 72, 76, 73};
    int temperatures_size = 8;

    int results_size;
    int* results = daily_temperatures(temperatures, temperatures_size, &results_size);

    printf("[");
    for (int i = 0; i < results_size; i++) {
        printf("%d", results[i]);

        if (i != (results_size - 1)) printf(", ");
    }
    printf("]\n");

    return 0;
}
