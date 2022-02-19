// Reference: https://leetcode.com/problems/4sum-ii

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int four_sums_count(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> first_sums;

    for (int const & num1 : nums1) {
        for (int const & num2 : nums2) {
            first_sums[num1 + num2]++;
        }
    }

    int total_sums = 0;

    for (int const & num3 : nums3) {
        for (int const & num4 : nums4) {
            total_sums += first_sums[0 - (num3 + num4)];
        }
    }

    return total_sums;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [1,2], [-2,-1], [-1,2], [0,2]
    // Output: 2
    vector<int> nums1{1, 2};
    vector<int> nums2{-2, -1};
    vector<int> nums3{-1, 2};
    vector<int> nums4{0, 2};
    cout << four_sums_count(nums1, nums2, nums3, nums4) << endl;

    return 0;
}

