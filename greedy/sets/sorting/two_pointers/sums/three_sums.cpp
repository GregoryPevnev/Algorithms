// Reference: https://leetcode.com/problems/3sum/
// Note: Implementing generic solution (Can reach ANY target-sum)
// Important: Ordering in the triplets does NOT matter

#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

struct triple {
    int* nums;
    struct triple* next;
};

typedef struct triple triple_t;

triple_t* make_triple(int num1, int num2, int num3) {
    int* nums = (int*) malloc(sizeof(int) * 3);

    nums[0] = num1;
    nums[1] = num2;
    nums[2] = num3;

    triple_t* triple = (triple_t*) malloc(sizeof(triple_t));

    triple->nums = nums;

    return triple;
}

int cmp_nums(const void* num1, const void* num2) {
    return *((int*) num1) - *((int*) num2);
}

int** find_three_sums(int* array, int length, int target_sum, int* output_size) {
    triple_t* triple_list_head = NULL;
    int triples_count = 0;

    int current_num; // Outer Loop
    int current_target_sum; // Outer Loop Sum
    int high_idx, low_idx, pair_sum; // Inner Loop
    triple_t* triple; // Temporary Tripled

    qsort(array, length, sizeof(int), cmp_nums);

    for (int i = length - 1; i >= 0; i--) {
        // Avoiding making the exact same triples of numbers -> Skipping duplicate-numbers (All located close together)
        if (i < length - 1 && array[i] == array[i + 1]) continue;

        // Initializing temporary-values
        current_num = array[i];
        current_target_sum = target_sum - current_num;
        low_idx = 0;
        high_idx = i - 1;

        while(low_idx < high_idx) {
            // Computing the sum of the current pair of Low and High numbers
            pair_sum = array[low_idx] + array[high_idx];

            // Case 1. NOT Reaching the current Target-Sum (Underflow)
            //   -> Taking a greater Low-Number

            if (pair_sum < current_target_sum) {
                low_idx++;

                continue;
            }

            // Case 2. NOT Reaching the current Target-Sum (Overflow)
            //   -> Taking a smaller High-Number

            if (pair_sum > current_target_sum) {
                high_idx--;

                continue;
            }

            // Case 3. Reaching the current Target-Sum -> Adding a Triple to the list

            triple = make_triple(current_num, array[low_idx], array[high_idx]);
            triple->next = triple_list_head;
            triple_list_head = triple;

            triples_count++;

            // SUPER-IMPORTANT: Skipping BOTH because the Target-Sum can ONLY be reached combining these TWO numbers
            //   If "A + B = C"
            //   Then "A + D != C" (If "D != B")
            //   Then "D + B != C" (If "D != A")
            // -> Skipping additional
            low_idx++;
            high_idx--;

            while(low_idx < high_idx && array[low_idx - 1] == array[low_idx]) low_idx++;

            while(low_idx < high_idx && array[high_idx] == array[high_idx + 1]) high_idx--;
        }
    }

    int** output = (int**) malloc(sizeof(int*) * triples_count);

    for (int i = 0; i < triples_count; i++) {
        output[i] = triple_list_head->nums;

        triple_list_head = triple_list_head->next;
    }

    *output_size = triples_count;

    return output;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

// Input: nums = [-1,0,1,2,-1,-4], target = 0
// Output: [[-1,-1,2],[-1,0,1]]

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int nums_length = 6;
    int target = 0;

    int triples_count;
    int** triples = find_three_sums(nums, nums_length, target, &triples_count);

    for (int i = 0; i < triples_count; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", triples[i][j]);
        }

        printf("\n");
    }

    return 0;
}
