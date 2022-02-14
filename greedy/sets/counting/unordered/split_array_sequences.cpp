// Reference: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// Guide: https://leetcode.com/problems/split-array-into-consecutive-subsequences/solution/
// Tags: Greedy, Set, Hash-Map, Counting
// Complexity: O(N) - Iterating and using Hash Access / Modifications

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

bool is_possible_to_split(vector<int>& nums) {
    // Step 1. Building a Hash-Map of frequencies for each Number -> Helps with checks

    unordered_map<int, int> num_counts;
    for (int const &num : nums) num_counts[num]++;

    // Step 2. Iterating over each number and checking whether it can become a part of a Sequence

    // Mapping whether a sequence can be formed with a specific number as the last number of that sequence
    //   - Checking for the preceding number to check if the current number can be included into ANY Sequences
    //   -> Having the LAST number of the Sequence point to the ACTUAL COUNT of the opened Sequences with it as the head
    unordered_map<int, int> opened_sequences;

    // For each number (NOT distinct / unique - ALL repetitions)
    for (int const &num : nums) {
        // If it was already used up for existing Sequences -> Skip
        if (num_counts[num] == 0) continue;

        if (opened_sequences[num - 1] > 0) {
            // Case 1. The current number can be added to an open Sequence -> Should always be prioritized

            // Decreasing the Counter for the current number - Making it used
            num_counts[num]--;

            // Changing the head of the Sequence to be the current number - The last in the current Sequence
            opened_sequences[num - 1]--;
            opened_sequences[num]++;
        } else if (num_counts[num + 1] > 0 && num_counts[num + 2] > 0) {
            // Case 2. The current number cannot be added to an existing Sequence (First / Non-Consecutive / etc.)
            //   -> And there are 2 following numbers that can be used for forming a new Sequence

            // Using the current and the following numbers -> Decreasing their usage
            num_counts[num]--;
            num_counts[num + 1]--;
            num_counts[num + 2]--;

            // Starting a new Sequence with the last number as the head
            opened_sequences[num + 2]++;
        } else {
            // If there are NO open Sequences for the current number AND a brand new Sequence CANNOT be formed
            //   -> Thw current number cannot be included into ANY Sequence
            //   => FALSE
            return false;
        }
    }

    // All numbers and their instances were successfully included into their Sequences

    return true;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main () {
    // Input: [1,2,3,3,4,5]
    // Output: true
    vector<int> nums1{1, 2, 3, 3, 4, 5};
    cout << is_possible_to_split(nums1) << endl;

    // Input: [1,2,3,3,4,4,5,5]
    // Output: true
    vector<int> nums2{1, 2, 3, 3, 4, 4, 5, 5};
    cout << is_possible_to_split(nums2) << endl;

    // Input: [1,2,3,4,4,5]
    // Output: false
    vector<int> nums3{1, 2, 3, 4, 4, 5};
    cout << is_possible_to_split(nums3) << endl;

    return 0;
}
