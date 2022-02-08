// Reference: https://leetcode.com/problems/split-array-into-consecutive-subsequences/submissions/
// Tags: Greedy, Set, Tree-Map (Ordering and Counting)
// Complexity: O(NlogM + MKlogM), where
//        - N is the number of ALL numbers (Including Duplicates)
//          M is the number of distinct numbers (Grouped into Counters in the Tree-Set)
//          K is the length of the sequences
//   1) Building a Tree-Map with N items that get deduplicated / grouped into M entries in the Tree-Map -> NlogM
//   2) Iterating over each Group / Counter of numbers -> M
//      a) Iterating over the subsequent expected length of sequences for each current number -> K
//         i) Performing Access and Modification of each successive Counter / Group -> logM
//         -> KlogM
//      -> MKlogM

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Non-Optimal Solution: Relying on the fact that the length of sequences is NOT too large

// Approach: While there are still numbers present
//   1) Taking each LOWEST starting-number and counting the number of sequences it should have (One for each occurrence)
//   2) Checking if there is K - 1 following numbers which can satisfy the current number (Continue ALL the sequences)
//        a) NO: The result is FALSE
//        b) YES: Decreasing the count - Have to start less sequences now (If any)
// If all numbers formed sequences - Then the result is TRUE

bool is_possible_to_divide(vector<int>& nums, int length) {
    // Step 1. Building Tree-Map for
    //    1) Storing and Accessing Counters for each Number -> Counting / Checking / Decreasing
    //    2) Accessing all pairs of Number and its Counter in ASC order -> Iterating from the LOWEST
    //  -> Tree-Map is a perfect Data-Structure for this (Accessing / Modifying and Sorting / Ordering - Does BOTH)

    map<int, int> num_counts;
    for (int const &num : nums) num_counts[num]++;

    // Step 2. Iterating over each distinct number and checking whether there is are sufficient following numbers
    //   -> Decreasing the Counters of following Numbers if the checks are successful
    //   => Decreases number of queues required to be built by them

    int current_num, current_sequences;

    for (map<int, int>::iterator it = num_counts.begin(); it != num_counts.end(); it++) {
        current_num = it->first;
        current_sequences = it->second;

        if (current_sequences == 0) continue;

        for (int num = current_num; num < current_num + length; num++) {
            if ((num_counts[num] -= current_sequences) < 0) {
                return false;
            }
        }
    }

    return true;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main () {
    // Input: nums = [1,2,3,3,4,4,5,6], length = 4
    // Output: true
    vector<int> nums1{1, 2, 3, 3, 4, 4, 5, 6};
    int length1 = 4;
    cout << is_possible_to_divide(nums1, length1) << endl;

    // Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], length = 3
    // Output: true
    vector<int> nums2{3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11};
    int length2 = 3;
    cout << is_possible_to_divide(nums2, length2) << endl;

    // Input: nums = [1,2,3,4], k = 3
    // Output: false
    vector<int> nums3{1, 2, 3, 4};
    int length3 = 3;
    cout << is_possible_to_divide(nums3, length3) << endl;

    return 0;
}
