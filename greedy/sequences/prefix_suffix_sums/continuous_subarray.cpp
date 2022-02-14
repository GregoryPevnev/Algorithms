// Reference: https://leetcode.com/problems/contiguous-array/
// Tags: Sequence, Prefix Sum, Hash-Map, Hash-Set

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Idea: There is the same number of 1s and 0s between any two positions which have the same differance of 1s and 0s
//    -> The positions with the same Balance make an Interval which beings and ends at those positions
//    => The longest Interval with a specific Balance is the one which has
//          1) The starting position as the first position with the specific Balance
//          2) The ending position as the last position with the specific Balance
// Example: [0, 0, 1, 0, 1] -> [-1, -2, -1, -2, -1] => The range between -1s is 4 (First and Last)
//   - Specifies the Interval [0, 1, 0, 1] (The longest interval with the same number of 1s and 0s)

// Balance: Differance between 1s and 0s - Initially 0, before any elements ()No 1s and 0s
//      Default: 0
//      Counting: Incrementing for 1s and Decrementing for 0s
//      Example: -2 means that there are 2 more 0s than 1s in a sequence
// Example: [0, 1, 1, 1, 0, 0] -> [-1, 0, 1, 2, 1, 0]

// Solution: Finding the longest Interval of starting and ending positions with the same Balance

int find_max_length(vector<int>& nums) {
    const int nums_length = nums.size();

    // Initializing a Hash-Map and a Hash-Set for specifying
    //    1) The first position with a specific Balance
    //    2) Whether a first position with a specific Balance was already encountered
    // Extra: Adding the initial position with the Balance of 0 - Goes before all the numbers
    unordered_map<int, int> balance_positions;
    unordered_map<int, bool> balance_positions_found;
    balance_positions[0] = -1;
    balance_positions_found[0] = true;

    // Initializing the current Balance to 0
    int balance = 0;

    // Storing the current maximum length of an Interval (There could be multiple ones)
    int max_length = 0;

    // For each element
    for (int i = 0; i < nums_length; i++) {
        // 1) Updating the balance accordingly
        if (nums[i] == 1) balance++;
        else balance--;

        // 2) Checking whether there is already a position with such Balance
        if (balance_positions_found[balance]) {
            // a) Yes -> Checking whether the length of the Interval is greater than the current Max-Length
            // Interval: The first position with the current Balance and the current position - Have the same Balance
            max_length = max(max_length, i - balance_positions[balance]);
        } else {
            // b) No -> Setting the current position as the first position with the current Balance
            //    => Could make an Interval with subsequent positions with the same Balance (If they are found)
            balance_positions[balance] = i;
            balance_positions_found[balance] = true;
        }
    }

    return max_length;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [1,0,0,0,1,1,1]
    // Output: 6
    vector<int> nums{1, 0, 0, 0, 1, 1, 1};
    cout << find_max_length(nums) << endl;

    return 0;
}
