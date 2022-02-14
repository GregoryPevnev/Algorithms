// Reference: https://leetcode.com/problems/continuous-subarray-sum/
// Tags: Sequence, Prefix Sum, Hash-Map, Unbounded Range

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Idea: If there are two positions in the Array which have the same Current-Sum / Prefix-Sum (Modded / Remainder)
//       Then the sub-array of values between them has a total sum of a multiple of K

// Solution: Finding ANY two positions which have the same MODDED Prefix-Sum / Remainder of the Current-Sum
//    -> Checking whether the length is at least 2 by storing and comparing the positions / indices

// Optimization: Cannot use Indexed-Array / Vector as a Map - The range of values is extremely large

bool check_subarray_sum(vector<int>& nums, int k) {
    const int nums_length = nums.size();

    if (nums_length < 2) return false;

    // Initializing the Map for storing the visited Positions - The initial K-Sum is 0 (Prior to the values)
    // Important: Cannot use Indexed-Array / Vector as a Map - K is too large
    unordered_map<int, int> ksum_positions;
    ksum_positions[0] = -1;

    // Remainder of the Current-Sum / Prefix-Sum MODDED by K -> K-Sum
    long current_ksum = 0;

    // For each item in the array and its position
    for (int position = 0; position < nums_length; position++) {
        // Update / Recalculate the new K-Sum (Prefix-Sum MODDED by K)
        current_ksum = (current_ksum + nums[position]) % k;

        // Checking whether it's the first time that such a K-Sum is encountered
        //     -> Setting it otherwise
        if (ksum_positions.find(current_ksum) == ksum_positions.end()) {
            ksum_positions[current_ksum] = position;

            continue;
        }

        // If it was encountered then checking the length -> Returning true if correct
        if ((position - ksum_positions[current_ksum]) >= 2) {
            return true;
        }
    }

    // If no repeating K-Sums were found or if they consisted of only a single element -> False
    return false;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: nums = [23,2,4,6,7], k = 6
    // Output: true
    vector<int> nums1{23, 2, 4, 6, 7};
    int target_sum1 = 6;
    cout << check_subarray_sum(nums1, target_sum1) << endl;

    // Input: nums = [23,2,6,4,7], k = 6
    // Output: true
    vector<int> nums2{23, 2, 6, 4, 7};
    int target_sum2 = 6;
    cout << check_subarray_sum(nums2, target_sum2) << endl;

    return 0;
}

