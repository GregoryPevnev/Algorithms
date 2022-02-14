#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find_pairs(vector<int>& nums, int k) {
    unordered_map<int, int> num_freq;
    for (int const &num : nums) num_freq[num]++;

    int total_pairs = 0;

    for (unordered_map<int, int>::iterator it = num_freq.begin(); it != num_freq.end(); it++) {
        if (k == 0) {
            total_pairs += it->second > 1 ? 1 : 0;
        } else {
            total_pairs += num_freq.find(it->first + k) != num_freq.end() ? 1 : 0;
        }
    }

    return total_pairs;
}

int main() {
    // Input: nums = [3,1,4,1,5], k = 2
    // Output: 2
    vector<int> nums1{3, 1, 4, 1, 5};
    int k1 = 2;
    cout << find_pairs(nums1, k1) << endl;

    // Input: nums = [1,2,3,4,5], k = 1
    // Output: 4
    vector<int> nums2{1, 2, 3, 4, 5};
    int k2 = 1;
    cout << find_pairs(nums2, k2) << endl;

    // Input: nums = [1,3,1,5,4], k = 0
    // Output: 1
    vector<int> nums3{1, 3, 1, 5, 4};
    int k3 = 0;
    cout << find_pairs(nums3, k3) << endl;

    return 0;
}
