// Reference: https://leetcode.com/problems/subarray-sum-equals-k/
// Tags: Sequence, Prefix Sum, Hash-Map

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Idea: A sub-array has a sum of K if all of its elements add up to K
//    -> If the differance between the sums of all numbers between certain positions is K
//       Then the Sub-Array of numbers between them has the running sub-sum equal to K
// Example: Items=[1, 2, 3] -> Sums=[0, 1, 3, 6] (Including that the initial sum before all is 0)
//    =>  1) 3 - 0 = 3 -> [1, 2] is a correct sub-array
//        2) 6 - 3 = 3 -> [3] is a correct sub-array

// Solution: Counting from how many positions can a specific Prefix-Sum be reached with a total sum of values equal to K
//    - Includes the initial position before any of the elements / values (Prefix-Sum = 0)
// Example:
//    Array = [1, -2, 1, 3, 2, 1], K = 3
//    Prefix-Sums: Initial-Sum = 0, [1, -1, 0, 3, 5, 6]
//    Checking Positions: 3 total matching positions
//       1) None: 1 - 3 = -2 -> No such positions
//       2) None: -1 - 3 = -4 -> No such positions
//       3) None: 0 - 3 = -3 -> No such positions
//       4) 2: 3 - 3 = 0 -> Positions -1 and 2
//       5) None
//       6) 1: 6 - 3 = 3 -> Position 3
// Important: Since negative values are possible, there could be multiple positions with identical sums

// Approach:
//   1) Storing the running total-sum of all items -> Computing Prefix-Sum for each Position
//   2) Counting the number of occurrences of each Prefix-Sum -> Can determine the number of possible starting positions
//   3) For each current Prefix-Sum check the number of starting-positions from which the Prefix-Sum can be reached in K
//        -> Counting the number of positions with Prefix-Sum = (Current-Prefix-Sum - K)

int subarray_sums(vector<int>& nums, int target_sum) {
    const int total_nums = nums.size();

    // Initializing the map which points
    // From: Prefix-Sums
    // To: Numbers of positions with the found Prefix-Sums
    unordered_map<int, int> prefix_sums_positions_count; // Number of positions with specific Prefix-Sums
    prefix_sums_positions_count[0] = 1; //  There is one position with the Prefix-Sum=0 - Initial position (-1)

    int total_sum = 0; // Current running Prefix-Sum

    int total_subarrays = 0; // Number of the found subarrays which produce the correct target sum

    // Iterating over each element / value / number
    for (int i = 0; i < total_nums; i++) {
        // 1) Increasing the current Target-Sum
        total_sum += nums[i];

        // 2) Finding the number of starting positions from which we can reach the current position
        //       - With the Sub-Sum of all the intermediate numbers equal to the Target-Sum
        //       -> There is a valid Sub-Array with the Target-Sum from each starting position to the current position
        total_subarrays += prefix_sums_positions_count[total_sum - target_sum];

        // 3) Adding the current position as a position with a specific Prefix-Sum
        prefix_sums_positions_count[total_sum]++;
    }

    // Total number of the correct Sub-Arrays
    return total_subarrays;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: nums = [1,1,1], k = 2
    // Output: 2
    vector<int> nums1{1, 1, 1};
    int target_sum1 = 2;
    cout << subarray_sums(nums1, target_sum1) << endl;

    // Input: nums = [1,2,3], k = 3
    // Output: 2
    vector<int> nums2{1, 2, 3};
    int target_sum2 = 3;
    cout << subarray_sums(nums2, target_sum2) << endl;

    // Input: nums = [1], k = 0
    // Output: 0
    vector<int> nums3{1};
    int target_sum3 = 0;
    cout << subarray_sums(nums3, target_sum3) << endl;

    return 0;
}

