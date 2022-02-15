// Reference: https://leetcode.com/problems/single-number/
// Complexity: O(N) Time with O(1) Space

// Logic: Every number with a second instance of the number gets cancelled out, EXCEPT the single number

#include <iostream>
#include <vector>

using namespace std;

int single_number(vector<int>& nums) {
    int x = 0;

    for (int const &num : nums) x ^= num;

    return x;
}

int main() {
    // Input: nums = [4,1,2,1,2]
    // Output: 4
    vector<int> nums{4, 1, 2, 1, 2};
    cout << single_number(nums) << endl;

    return 0;
}
