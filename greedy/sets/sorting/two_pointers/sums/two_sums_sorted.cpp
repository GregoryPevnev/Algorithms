// Reference: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Tags: Greedy, Sorting, Set, Two-Pointers
// Complexity: O(N) - Single pass with two pointers
// Note: Simplification / Leading problem to a proper two-sums implementation with Constant-Space

#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

vector<int> two_sum_from_sorted(vector<int>& numbers, const int target_sum) {
    int start_pointer = 0;
    int end_pointer = numbers.size() - 1;

    int current_sum;

    while (start_pointer < end_pointer) {
        current_sum = numbers[start_pointer] + numbers[end_pointer];

        if (current_sum == target_sum) {
            return vector<int>{start_pointer + 1, end_pointer + 1};
        }

        if (current_sum < target_sum) start_pointer++;
        else end_pointer--;
    }

    // Target sum is not found
    return vector<int>{};
}

// ---------------------------------------------------------------------------------------------------------------------
// Testing
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: numbers = [2,7,11,15], target_sum = 9
    // Output: [1,2]

    vector<int> numbers{2, 7, 11, 15};
    const int target_sum = 9;

    vector<int> positions = two_sum_from_sorted(numbers, target_sum);

    if (positions.empty()) {
        cout << "Items that produce the target sum were not found" << endl;
    } else {
        cout << "[" << positions[0] << ", " << positions[1] << "]" << endl;
    }

    return 0;
}

