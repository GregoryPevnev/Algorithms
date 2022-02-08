// Reference: https://leetcode.com/problems/two-sum/
// Note: Implementing generic solution (Can reach ANY target-sum with ANY number of pairs)
// Important: Using Pointers-Approach - Could also be solved using Maps (Hash-Tables)
//    -> Allows to be reused as a sub-routine in Three-Sum / Four-Sum / K-Sum

#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

struct pair {
    int* nums;
    struct pair* next;
};

typedef struct pair pair_t;

pair_t* make_pair(int num1, int num2) {
    int* nums = (int*) malloc(sizeof(int) * 2);

    nums[0] = num1;
    nums[1] = num2;

    pair_t* pair = (pair_t*) malloc(sizeof(pair_t));

    pair->nums = nums;

    return pair;
}

int cmp_nums(const void* num1, const void* num2) {
    return *((int*) num1) - *((int*) num2);
}

// TODO: Comments

// TODO: Adding Edge-Cases + Iterating until 2 (Three elements present)

int** find_pair_sums(int* array, int length, int target_sum, int* output_size) {
    pair_t* pair_list_head = NULL;
    int pairs_count = 0;

    pair_t* pair;
    int low_idx = 0, high_idx = length - 1;
    int pair_sum;

    qsort(array, length, sizeof(int), cmp_nums);

    while(low_idx < high_idx) {
        // Computing the sum of the current pair of Low and High numbers
        pair_sum = array[low_idx] + array[high_idx];

        // Case 1. NOT Reaching the Target-Sum (Underflow)
        //   -> Taking a greater Low-Number

        if (pair_sum < target_sum) {
            low_idx++;

            continue;
        }

        // Case 2. NOT Reaching the Target-Sum (Overflow)
        //   -> Taking a smaller High-Number

        if (pair_sum > target_sum) {
            high_idx--;

            continue;
        }

        // Case 3. Reaching the current Target-Sum -> Adding a Triple to the list

        pair = make_pair(array[low_idx], array[high_idx]);
        pair->next = pair_list_head;
        pair_list_head = pair;

        pairs_count++;

        // SUPER-IMPORTANT: Skipping BOTH because the Target-Sum can ONLY be reached combining these TWO numbers
        //   If "A + B = C"
        //   Then "A + D != C" (If "D != B")
        //   Then "D + B != C" (If "D != A")
        //  -> Skipping duplicates as well (TO only return unique combinations)
        low_idx++;
        high_idx--;

        while(low_idx < high_idx && array[low_idx - 1] == array[low_idx]) low_idx++;

        while(low_idx < high_idx && array[high_idx] == array[high_idx + 1]) high_idx--;
    }

    int** output = (int**) malloc(sizeof(int*) * pairs_count);

    for (int i = 0; i < pairs_count; i++) {
        output[i] = pair_list_head->nums;

        pair_list_head = pair_list_head->next;
    }

    *output_size = pairs_count;

    return output;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

// Input: nums = [3,2,4], target = 6
// Output: [[2, 4]]

int main() {
    int nums[] = {3, 2, 4};
    int nums_length = 3;
    int target = 6;

    int pairs_count;
    int** pairs = find_pair_sums(nums, nums_length, target, &pairs_count);

    for (int i = 0; i < pairs_count; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", pairs[i][j]);
        }

        printf("\n");
    }

    return 0;
}
