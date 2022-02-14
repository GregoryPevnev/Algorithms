#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int max_earn(vector<int>& nums) {
    // Step 1. Computing the total earnings that could be made by deleting a specific number
    //   - Deleting a number pretty much means deleting all instances of the number (Optimal in every way)

    unordered_map<int, int> total_nums;
    int max_num = -1;

    for (int const &num : nums) {
        total_nums[num] += num;

        max_num = max(max_num, num);
    }

    // Step 2. Calculating how much can be earned from each specific number as the minimum-number starting point
    //  - Does NOT necessary mean including the number, just considering it
    //  -> Checking all POSSIBLE number inclusions starting from 1 to find the one which earns the most
    //  => Using Dynamic-Programming (Bottom-Up)
    // Important: Takes the deletion logic into account - earnings consecutive numbers cannot be included at once

    vector<int> earnings(max_num + 1, -1);

    // Base-Cases
    // Maximum-Number: Can only be included when maximizing with it as the starting point
    // Number before the Maximum-Number: Can either be included itself or have the Maximum-Number included instead

    earnings[max_num] = total_nums[max_num];
    earnings[max_num - 1] = max(total_nums[max_num], total_nums[max_num - 1]);

    // Iterating with Tabulation: Considering all the lesser numbers as starting-points for earnings
    //   -> Maximizing earnings for each starting-point number
    //   => Eventually reaching the first position

    int earnings_with_current;
    int earnings_without_current;

    for (int num = max_num - 2; num >= 1; num--) {
        // Recurrence 1. Including the current number and skipping the following consecutive number
        earnings_with_current = total_nums[num] + earnings[num + 2];

        // Recurrence 2. Excluding the current number for the following consecutive number
        earnings_without_current = earnings[num + 1];

        // Maximizing the earnings for the current number by choosing the best option
        earnings[num] = max(earnings_with_current, earnings_without_current);
    }

    // Maximum Earnings is the same as the maximum earnings for the very first position

    return earnings[1];
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
