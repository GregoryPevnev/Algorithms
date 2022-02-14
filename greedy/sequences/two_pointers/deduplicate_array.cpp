// Reference: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Note: Generic solution for allowing for any number of maximum duplicates
// Tags: Greedy, Sequence, Two Pointers

#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Removing Duplicates from a SORTED / ORDERED Array
//    - In-Place (Returning the new size)
//    - Allowing up to K duplicate values

// Note: K is the factor for Max-Duplication / Max-Duplicates allowed in the array

int deduplicate_array(vector<int>& nums, int max_duplicates) {
    const int total_nums = nums.size();

    // Keeping 2 arrays in the provided array:
    //   1) Original sorted array
    //   2) Deduplicated sub-array in the beginning

    int p1 = 0; // Pointer to the end of original array - Inspecting the new values
    int p2 = 0; // Pointer to the end of deduplicated array - Can be used for checking the last duplicate-sequence

    while (p1 < total_nums) {
        // Putting the current number from the original array into the deduplicated array if
        // 1) The deduplicated array is less than K (Safe even with K duplicates)
        // 2) The Kth least recent value the deduplicated array is STRICTLY less than the current original value
        //     - Given the constraint that no K digits are repeating in the Deduplicated Sub-Array
        //     -> The current value is NOT a duplicate if it is NOT the same as the value of the last duplicate-sequence
        if (p2 < max_duplicates || nums[p2 - max_duplicates] < nums[p1]) {
            nums[p2++] = nums[p1];
        }

        // Moving the original-array pointer to inspect the next value
        p1++;
    }

    return p2; // The value of Pointer 2 is K (Index AFTER the end of the deduplicated array)
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

void print_array(vector<int>& nums, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) cout << nums[i] << " ";
    cout << "]" << endl;
}

int main() {
    vector<int> nums{1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5};

    int size = deduplicate_array(nums, 3);

    print_array(nums, size);

    return 0;
}
