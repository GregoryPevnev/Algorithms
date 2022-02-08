// Reference: https://leetcode.com/problems/daily-temperatures
// Better solution: Does not rely on the limits of temperature-values and generally iterates less

#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Stack
// Items: Storing numbers / indices of days that are waiting for the temperature to rise
// Order: Storing days in correspondence to their temperature in ASCENDING ORDER
//    -> The top element is the waiting day has the LOWEST temperature
// Constraint: Before a day is PUSHED to the stack, all days with lesser temperatures are POPPED) -> ASCENDING ORDER

// Abbreviation: WD = Waiting Days

int* daily_temperatures(int* temperatures, int temperatures_size, int* returnSize){
    int* results = (int*) malloc(sizeof(int) * temperatures_size);
    *returnSize = temperatures_size;


    // Setup: Initializing a stack for keeping track of days that are waiting for the temperature to rise
    //   -> Waiting-Days-Stack (WD-Stack) + Waiting-Days-Stack-Head (WD-Stack-Head)
    //   => Using an array with static size (Number of possible items is given)
    // Note: Instead of explicitly deleting the elements, they are instead rewritten
    int* wd_stack = (int*) malloc(sizeof(int) * temperatures_size);
    int wd_stack_head = -1;

    // Processing: For each day and its temperature
    for (int i = 0; i < temperatures_size; i++) {
        // 1. Taking all the Waiting-Days that have LOWER temperature than the current day (If there are Waiting-Days)
        //     -> Popping Waiting-Days with the LOWER temperature OFF the Waiting-Days-Stack
        //     => Taking advantage of the ASCENDING order (Inspecting the top-element)
        while (wd_stack_head >= 0 && temperatures[wd_stack[wd_stack_head]] < temperatures[i]) {
            // 1.1. Writing the result for the processed / popped Waiting-Days
            results[wd_stack[wd_stack_head]] = i - wd_stack[wd_stack_head];

            // 1.2. Popping the item (Re-Writing in this case)
            wd_stack_head--;
        }

        // 2. Adding the current day to the Waiting-Days-Stack
        wd_stack[++wd_stack_head] = i;
    }

    // Cleanup: Taking all the Waiting-Days in the stack and setting their results to 0
    //   -> Means that warmer days were never found for them
    while(wd_stack_head >= 0) results[wd_stack[wd_stack_head--]] = 0;

    // Teardown: Releasing the stack
    free(wd_stack);

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
