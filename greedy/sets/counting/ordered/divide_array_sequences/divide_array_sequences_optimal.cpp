// Reference: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// Guide: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/discuss/470238/JavaC%2B%2BPython-Exactly-Same-as-846.-Hand-of-Straights
// Tags: Greedy, Set, Queue (First and Last), Tree-Map (Ordering and Counting)
// Complexity: O(NlogM + M), where
//        - N is the number of ALL numbers (Including Duplicates)
//          M is the number of distinct numbers (Grouped into Counters in the Tree-Set)
//   1) Building a Tree-Map with N items that get deduplicated / grouped into M entries in the Tree-Map -> NlogM
//   2) Iterating over the Counters of Numbers -> M
//       a) Checking whether Sequences are completed
//       b) Opening new Sequences that need to be completed
//       c) Managing metadata and running values

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Note: Providing a Diagram and a detailed explanation from the Notebook

// Optimal Solution: The performance does NOT depend on the lengths of sequences to be built in any way

bool is_possible_to_divide(vector<int>& nums, int length) {
    // Step 1. Building Tree-Map for
    //    1) Storing and Accessing Counters for each Number -> Counting / Checking / Decreasing
    //    2) Accessing all pairs of Number and its Counter in ASC order -> Iterating from the LOWEST
    //  -> Tree-Map is a perfect Data-Structure for this (Accessing / Modifying and Sorting / Ordering - Does BOTH)

    map<int, int> num_counts;
    for (int const &num : nums) num_counts[num]++;

    // Step 2. Iterating over numbers and their counters -> Checking whether sequences can be formed

    // Keeping running values and counters
    //   1) Total starting positions of sequences that have not been completed yet
    //   2) Counter of the number of TOTAL Sequences that need to be completed - Total of all numbers
    //  -> Checking whether the following numbers an their Counters can be satisfy the current Queues
    int opened_count = 0; // Number of starting-positions - One for each distinct number
    int current_sequences = 0; // Total opened sequences that need completion - Multiple for each number possible

    // Keeping track of how many sequences were started for each position (History)
    //    -> Accessing the # of sequences started for the first numbers / least recent items
    //    => Queue is a perfect structure for modifying and accessing History (Least Recent / Most Recent)
    queue<int> started_sequences;

    // Storing the current and the last numbers + Started sequences for the current number
    int new_number, last_number;
    int new_sequences; // The number of sequences that need to be formed from the current number / position

    for (map<int, int>::iterator it = num_counts.begin(); it != num_counts.end(); it++) {
        // a) Initializing the new number and the number of sequences that
        //     i) Can be satisfied
        //     ii) Can be started
        new_number = it->first;
        new_sequences = it->second;

        // b) Checking whether it is impossible to satisfy the current sequences

        // Case 1. The previous sequence(s) have not been completed + The current number is NOT consecutive
        if (opened_count > 0 && last_number + 1 != new_number) return false;

        // Case 2. The previous sequence(s) have not been completed + The current number cannot satisfy all of them
        //   - There is less instances of the current number than it is needed for all opened Sequences to complete
        if (opened_count > 0 && current_sequences > new_sequences) return false;

        // c) Computing the number of Sequence that are ACTUALLY going to be started from the current number / position
        //     -> Recording it in the History

        // Taking into account all the current Sequences that are satisfied
        new_sequences -= current_sequences;

        // Starting the brand new sequences if possible
        //    - If there are MORE instances of the current number than required to just COMPLETE the current Sequences
        //    -> Upping the counter of positions from which some Sequences were opened
        if (new_sequences > 0) {
            opened_count++;
            current_sequences += new_sequences;
        }

        // Recording the number of sequences opened from the current number / position
        started_sequences.push(new_sequences);

        // d) In case a certain number of Sequences COULD be completed by getting so far
        //      - An old number / position when out of bounds of the length of running Sequences

        if (started_sequences.size() >= length) {
            // If any sequences were opened from the Kth last number / position
            //   -> i) Decreasing the number of the positions / numbers from which the Sequences were opened
            //      ii) Decreasing the number of the actual current Sequences that are opened (JUST GOT COMPLETED)
            if (started_sequences.front() > 0) {
                opened_count--;

                current_sequences -= started_sequences.front();
            }

            // Erasing from the History
            started_sequences.pop();
        }

        // e) Saving the current number fo checking for consecutive Sequences

        last_number = new_number;
    }

    // Step 3. Providing results

    // a) If there are any positions from which the Sequences have NOT been completed -> FALSE
    if (opened_count > 0) return false;

    // b) Otherwise -> TRUE
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
