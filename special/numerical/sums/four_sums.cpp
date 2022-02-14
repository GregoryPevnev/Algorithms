// Reference: https://leetcode.com/problems/4sum/
// Important: Ordering in the quadruplets does NOT matter

#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

struct quad {
    int* nums;
    struct quad* next;
};

typedef struct quad quad_t;

quad_t* make_quad(int num1, int num2, int num3, int num4) {
    int* nums = (int*) malloc(sizeof(int) * 4);

    nums[0] = num1;
    nums[1] = num2;
    nums[2] = num3;
    nums[3] = num4;

    quad_t* quad = (quad_t*) malloc(sizeof(quad_t));

    quad->nums = nums;

    return quad;
}

int cmp_nums(const void* num1, const void* num2) {
    return *((int*) num1) - *((int*) num2);
}

// TODO: Comments

// TODO: Better constraints (Iterating until)

int** find_three_sums(int* array, int length, int target_sum, int* output_size) {
    quad_t* quad_list_head = NULL;
    int quads_count = 0;

    int current_num_high, current_num_low; // Outer Loops (High and Low)
    int current_target_sum; // Outer Loops Sum
    int high_idx, low_idx, pair_sum; // Inner Loop
    quad_t* quad; // Temporary Quadruplet

    qsort(array, length, sizeof(int), cmp_nums);

    for (int i = length - 1; i >= 0; i--) {
        // Avoiding making the exact same quads of numbers -> Skipping duplicate-numbers (All located close together)
        if (i < length - 1 && array[i] == array[i + 1]) continue;

        for (int j = 0; j < i; j++) {
            // Avoiding making the exact same quads of numbers -> Skipping duplicate-numbers (All located close together)
            if (j > 0 && array[j] == array[j - 1]) continue;

            // Initializing temporary-values
            current_num_high = array[i];
            current_num_low = array[j];
            current_target_sum = target_sum - current_num_high - current_num_low;
            low_idx = j + 1;
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

                quad = make_quad(current_num_high, current_num_low, array[low_idx], array[high_idx]);
                quad->next = quad_list_head;
                quad_list_head = quad;

                quads_count++;

                low_idx++;
                high_idx--;

                while (low_idx < high_idx && array[low_idx - 1] == array[low_idx]) low_idx++;

                while (low_idx < high_idx && array[high_idx] == array[high_idx + 1]) high_idx--;
            }
        }
    }

    int** output = (int**) malloc(sizeof(int*) * quads_count);

    for (int i = 0; i < quads_count; i++) {
        output[i] = quad_list_head->nums;

        quad_list_head = quad_list_head->next;
    }

    *output_size = quads_count;

    return output;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

void show_quads(int** quads, int quads_count) {
    for (int i = 0; i < quads_count; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", quads[i][j]);
        }

        printf("\n");
    }
}

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
void test1() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int nums_length = 6;
    int target = 0;

    int quads_count;
    int** quads = find_three_sums(nums, nums_length, target, &quads_count);

    show_quads(quads, quads_count);
}

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
void test2() {
    int nums[] = {2, 2, 2, 2, 2};
    int nums_length = 5;
    int target = 8;

    int quads_count;
    int** quads = find_three_sums(nums, nums_length, target, &quads_count);

    show_quads(quads, quads_count);
}

int main() {
    test1();

    test2();

    return 0;
}
