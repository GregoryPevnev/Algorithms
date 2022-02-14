#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int max_earn_for(unordered_map<int, int>& total_nums, int num, vector<int>& earnings) {
    // Base Case: Out of bounds - No earnings

    if (num < 0) return 0;

    // Recursion with Memoization

    if (earnings[num] == -1) {
        // Recurrence 1. Including the current number and skipping the following consecutive number
        int earnings_with_current = total_nums[num] + max_earn_for(total_nums, num - 2, earnings);

        // Recurrence 2. Excluding the current number for the following consecutive number
        int earnings_without_current = max_earn_for(total_nums, num - 1, earnings);

        // Maximizing the earnings for the current number by choosing the best option
        earnings[num] = max(earnings_with_current, earnings_without_current);
    }

    return earnings[num];
}

int max_earn(vector<int>& nums) {
    // Step 1. Computing the total earnings that could be made by deleting a specific number
    //   - Deleting a number pretty much means deleting all instances of the number (Optimal in every way)

    unordered_map<int, int> total_nums;
    int max_num = -1;

    for (int const &num : nums) {
        total_nums[num] += num;

        max_num = max(max_num, num);
    }

    // Step 2. Calculating how much can be earned from each specific number as the maximum-number starting point
    //  - Does NOT necessary mean including the number, just considering it
    //  -> Checking all POSSIBLE number inclusions starting from the Maximum-Number to find the one which earns the most
    //  => Using Dynamic-Programming (Top-Down)

    vector<int> earnings(max_num + 1, -1);

    return max_earn_for(total_nums, max_num, earnings);
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [3,4,2]
    // Output: 6
    vector<int> nums1{3, 4, 2};
    cout << max_earn(nums1) << endl;

    // Input: [2,2,3,3,3,4]
    // Output: 9
    vector<int> nums2{2, 2, 3, 3, 3, 4};
    cout << max_earn(nums2) << endl;

    return 0;
}
