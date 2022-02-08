// Reference: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int find_largest_histogram(vector<int>& heights) {
    const int total_heights = heights.size();

    // Prior Heights -> Hash-Map => Keeping track of # of consecutive heights for a specific position
    unordered_map<int, int> prior_higher_counts; // IMPORTANT: Could just be an array (Using Hash-Map for example)
    prior_higher_counts[0] = 0;

    // Next Heights -> Monotonic Stack
    stack<int> height_idxs;
    height_idxs.push(0);

    int max_area = 0;
    int heights_count;
    int current_area;
    int higher_count;

    for (int i = 1; i < total_heights; i++) {
        higher_count = 0;

        // SUPER-IMPORTANT: POPPING SAME HEIGHTS - OTHERWISE THE COUNTER IS ADDED MULTIPLE TIMES
        while (!height_idxs.empty() && heights[height_idxs.top()] >= heights[i]) {
            // SUPER-IMPORTANT: The current height is NOT included into the Histogram (LESS THAN THE STARTING POINT)
            //   -> NOT ADDING 1 TO THE CALCULATION
            // Heights Count: Prior + Current + Next
            heights_count = prior_higher_counts[height_idxs.top()] + (i - height_idxs.top());
            current_area = heights[height_idxs.top()] * heights_count;

            if (current_area > max_area) max_area = current_area;

            higher_count += prior_higher_counts[height_idxs.top()]; // Taking all the removed heights into account
            higher_count++; // Including the removed height (Since the current height is lower)

            height_idxs.pop();
        }

        // No sense in keeping 0-heights (Same as starting from the clean slate)
        if (heights[i] != 0) {
            height_idxs.push(i);
            prior_higher_counts[i] = higher_count;
        }
    }

    while (!height_idxs.empty()) {
        // SUPER-IMPORTANT: The current height is NOT included into the Histogram (LESS THAN THE STARTING POINT)
        //   -> NOT ADDING 1 TO THE CALCULATION
        // Heights Count: Prior + Current + Next
        heights_count = prior_higher_counts[height_idxs.top()] + (total_heights - height_idxs.top());
        current_area = heights[height_idxs.top()] * heights_count;

        if (current_area > max_area) max_area = current_area;

        height_idxs.pop();
    }

    return max_area;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [2,1,5,6,2,3]
    // Output: 10 (5, 6)
    vector<int> num1{2, 1, 5, 6, 2, 3};
    cout << find_largest_histogram(num1) << endl;

    // Input: [2,1,2]
    // Output: 3
    vector<int> num2{2, 1, 2};
    cout << find_largest_histogram(num2) << endl;

    // Input: [3,6,5,7,4,8,1,0]
    // Output: 20
    vector<int> num3{3, 6, 5, 7, 4, 8, 1, 0};
    cout << find_largest_histogram(num3) << endl;

    // Input: [5,4,4,6,3,2,9,5,4,8,1,0,0,4,7,2]
    // Output: 20
    vector<int> num4{5, 4, 4, 6, 3, 2, 9, 5, 4, 8, 1, 0, 0, 4, 7, 2};
    cout << find_largest_histogram(num4) << endl;
}
