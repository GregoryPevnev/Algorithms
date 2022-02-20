#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int min_size_subarray_sum(vector<int>& nums, const int target_sum) {
    // Details: The length of the sequence
    const int total_nums = nums.size();

    // Sliding Window Initialization
    // 1) Bounds
    int start = 0, end = 1;
    // 2) State
    int current_sum = nums[0];

    // Storing results - Current sub-array size and the smallest sub-array size wit
    //   -> Have the sum which is greater or equal to the target sum
    int min_size = 0, current_size;

    // Moving the Sliding-Window until the end corresponds to the end of the sequence
    while (end < total_nums) {
        if (current_sum < target_sum) {
            // Case 1. The current sum is LESS -> Increasing the current sum by moving the end
            current_sum += nums[end];
            end++;
        } else  {
            // Case 2. The current sum is GREATER or EQUAL -> Decreasing the current sum by moving the start
            // Additional: Checking if the current sub-array (window) is the smallest matching one
            current_size = end - start;
            min_size = min_size == 0 ? current_size : min(min_size, current_size);

            current_sum -= nums[start];
            start++;
        }
    }

    // Moving the Sliding-Window until all possible final starting positions are checked as well
    while (start < total_nums && current_sum >= target_sum) {
        current_size = end - start;
        min_size = min_size == 0 ? current_size : min(min_size, current_size);

        current_sum -= nums[start];
        start++;
    }

    return min_size;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: nums = [2,3,1,2,4,3], target_sum = 7
    // Output: 2
    vector<int> nums1{2, 3, 1, 2, 4, 3};
    const int target_sum1 = 7;
    cout << min_size_subarray_sum(nums1, target_sum1) << endl;

    // Input: nums = [1,2,3,4,5], target_sum = 11
    // Output: 3
    vector<int> nums2{1, 2, 3, 4, 5};
    const int target_sum2 = 11;
    cout << min_size_subarray_sum(nums2, target_sum2) << endl;

    return 0;
}
