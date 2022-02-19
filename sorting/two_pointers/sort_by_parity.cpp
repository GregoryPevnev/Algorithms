// Reference: https://leetcode.com/problems/sort-array-by-parity/
// Tags: Sorting, Two-Pointers

#include <iostream>
#include <vector>

using namespace std;

void sort_by_parity(vector<int>& nums) {
    int start_pointer = 0; // Searching for ODD numbers for swapping
    int end_pointer = nums.size() - 1; // Searching for EVEN numbers for swapping

    int temp_num;

    while(start_pointer < end_pointer) {
        // Skipping all the EVEN numbers -> Moving forwards
        while(start_pointer < end_pointer && nums[start_pointer] % 2 == 0) start_pointer++;

        // Skipping all the ODD numbers -> Moving backwards
        while(start_pointer < end_pointer && nums[end_pointer] % 2 == 1) end_pointer--;

        if (start_pointer < end_pointer) {
            temp_num = nums[start_pointer];
            nums[start_pointer] = nums[end_pointer];
            nums[end_pointer] = temp_num;
        }
    }
}

void print_nums(vector<int>& nums) {
    cout << "[";
    for (int const &num : nums) cout << " " << num << " ";
    cout << "]" << endl;
}

int main() {
    // Input: [2, 1, 3, 4]
    // Output: [2, 4, 3, 1]

    vector<int> nums{2, 1, 3, 4};

    sort_by_parity(nums);

    print_nums(nums);

    return 0;
}
