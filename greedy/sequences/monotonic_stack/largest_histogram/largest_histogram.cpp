// Reference: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int find_largest_histogram(vector<int>& heights) {
    const int number_of_heights = heights.size();

    stack<int> height_idxs;
    height_idxs.push(0);

    int current_height_idx;
    int lower_height_start_idx, lower_height_end_idx;
    int number_of_heights_between;
    int current_area;
    int max_area = 0;

    for (int i = 1; i < number_of_heights; i++) {
        while (!height_idxs.empty() && heights[height_idxs.top()] >= heights[i]) {
            current_height_idx = height_idxs.top();
            height_idxs.pop();

            lower_height_start_idx = height_idxs.empty() ? -1 : height_idxs.top();

            lower_height_end_idx = i;

            number_of_heights_between = lower_height_end_idx - lower_height_start_idx - 1;

            current_area = heights[current_height_idx] * number_of_heights_between;

            if (current_area > max_area) max_area = current_area;
        }

        height_idxs.push(i);
    }

    while (!height_idxs.empty()) {
        current_height_idx = height_idxs.top();
        height_idxs.pop();

        lower_height_start_idx = height_idxs.empty() ? -1 : height_idxs.top();

        lower_height_end_idx = number_of_heights;

        number_of_heights_between = lower_height_end_idx - lower_height_start_idx - 1;

        current_area = heights[current_height_idx] * number_of_heights_between;

        if (current_area > max_area) max_area = current_area;
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
