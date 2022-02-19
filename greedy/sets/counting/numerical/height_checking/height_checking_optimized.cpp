// Reference: https://leetcode.com/problems/height-checker/
// Tags: Greedy, Set, Numerical, Counting-Sort
// Complexity:
//  Time: O(N) - Using Counting-Sort as a Subroutine
//  Space: O(1) - Just the frequencies (Static size of the Array)


#include <iostream>
#include <vector>

// Range: Bounded and limited
#define MIN_HEIGHT 1
#define MAX_HEIGHT 100

using namespace std;

// Optimization: NOT actually building the Ordered-Array - Checking mismatches at runtime

int height_checking(vector<int>& heights) {
    vector<int> height_counts(MAX_HEIGHT + 1, 0);

    for (int const &height : heights) height_counts[height]++;

    int check_pointer = 0;

    int mismatching_positions = 0;

    int height_count;

    for (int height = MIN_HEIGHT; height <= MAX_HEIGHT; height++) {
        height_count = height_counts[height];

        while (height_count--) {
            if (heights[check_pointer] != height) {
                mismatching_positions++;
            }

            check_pointer++;
        }
    }

    return mismatching_positions;
}

int main() {
    // Input: [1,1,4,2,1,3]
    // Output: 3

    vector<int> heights{1, 1, 4, 2, 1, 3};

    cout << height_checking(heights) << endl;

    return 0;
}
