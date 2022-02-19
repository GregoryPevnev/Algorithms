// Reference: https://leetcode.com/problems/relative-sort-array/
// Tags: Greedy, Set, Numerical, Counting-Sort
// Complexity:
//  Time: O(N) - Using Counting-Sort as a Subroutine
//  Space: O(N) - Frequencies and a produced Ordered-Array

#include <iostream>
#include <vector>

// Range: Bounded and limited
#define MIN_HEIGHT 1
#define MAX_HEIGHT 100

using namespace std;

// Approach: Sorting the heights to have them in a non-decreasing order -> Counting the number of mismatches
//   - Using Counting-Sort, since the range of numerical values is small and bounded

int height_checking(vector<int>& heights) {
    const int total_heights = heights.size();

    vector<int> height_counts(MAX_HEIGHT + 1, 0);

    for (int const &height : heights) height_counts[height]++;

    vector<int> ordered_heights(total_heights);
    int ordered_heights_pointer = 0;

    int height_count;

    for (int height = MIN_HEIGHT; height <= MAX_HEIGHT; height++) {
        height_count = height_counts[height];

        while (height_count--) {
            ordered_heights[ordered_heights_pointer++] = height;
        }
    }

    int mismatching_positions = 0;

    for (int pos = 0; pos < total_heights; pos++) {
        if (heights[pos] != ordered_heights[pos]) {
            mismatching_positions++;
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
