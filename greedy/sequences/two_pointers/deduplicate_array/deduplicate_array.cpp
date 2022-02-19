#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int deduplicate_array(vector<int>& nums) {
    const int total_nums = nums.size();

    // The first element is NOT a duplicate by definition
    int deduplicated_pointer = 0;

    // Important: Can start with the second element - The first one stays no matter what
    int original_pointer = 1;

    while (original_pointer < total_nums) {
        while (original_pointer < total_nums && nums[original_pointer] == nums[deduplicated_pointer]) {
            original_pointer++;
        }

        if (original_pointer < total_nums) {
            nums[++deduplicated_pointer] = nums[original_pointer++];
        }
    }

    return deduplicated_pointer + 1;
}

// ---------------------------------------------------------------------------------------------------------------------
// Testing
// ---------------------------------------------------------------------------------------------------------------------

void print_nums(vector<int>& nums, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) cout << " " << nums[i] << " ";
    cout << "]" << endl;
}

int main() {
    // Input: [0,0,1,1,1,2,2,3,3,4] (10 items)
    // Output: [0,1,2,3,4] (5 items)

    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int size = deduplicate_array(nums);

    print_nums(nums, size);

    return 0;
}
