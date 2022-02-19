#include <iostream>
#include <vector>

using namespace std;

void duplicate_zeros(vector<int>& nums) {
    const int total_nums = nums.size();

    // Step 1. Counting the number of zeroes -> Calculating the shifting factor

    int zeroes = 0;
    int non_zeroes = 0;

    // IMPORTANT: Taking shifting-factor into account (NOT numbers the out-of-range zeroes)
    for (int i = 0; i + zeroes < total_nums; i++) {
        if (nums[i] == 0) {
            zeroes++;
        } else {
            non_zeroes++;
        }
    }

    // Edge-Case: Not performing any movement if there are no zeroes
    if (zeroes == 0) return;

    // Step 2. Calculating the pointers for copying numbers to and from with the shift included / excluded

    int copy_to_pointer = zeroes * 2 + non_zeroes - 1; // With shifting
    int copy_from_pointer = zeroes + non_zeroes - 1; // Without shifting

    // Step 3. Copying, shifting and duplicating numbers

    // Edge-Case: With numbers with duplicated zeroes go out of bounds of the array
    //   -> NOT duplicating the trailing zero (Should get cut off)
    //   => Simply placing it at the end of the array instead
    if (copy_to_pointer == total_nums) {
        nums[copy_to_pointer - 1] = 0;

        copy_to_pointer -= 2;
        copy_from_pointer--;
    }

    // Copying numbers with the following logic
    //   1. Zeroes get copied 2 times - The gap closes / shifting factor gets reduced
    //   2. Other numbers simply get copied once
    while (copy_to_pointer > copy_from_pointer && copy_from_pointer >= 0) {
        if (nums[copy_from_pointer] == 0) {
            nums[copy_to_pointer] = 0;
            nums[copy_to_pointer - 1] = 0;

            copy_to_pointer -= 2;
            copy_from_pointer--;
        } else {
            nums[copy_to_pointer--] = nums[copy_from_pointer--];
        }
    }
}

void print_nums(vector<int>& nums) {
    cout << "[";
    for (int const &num : nums) cout << " " << num << " ";
    cout << "]" << endl;
}

int main() {
    // Input: [1,0,2,3,0,4,5,0]
    // Output: [1,0,0,2,3,0,0,4]

    vector<int> nums{1, 0, 2, 3, 0, 4, 5, 0};

    duplicate_zeros(nums);

    print_nums(nums);

    return 0;
}
