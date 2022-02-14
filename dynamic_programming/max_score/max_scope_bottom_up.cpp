#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int max_score(vector<int>& nums, vector<int>& multipliers) {
    // Step 0. Determining and saving
    //   1) Total numbers provided for operations
    //   2) Number of multipliers / total operations to be performed

    const int nums_count = nums.size();

    const int multipliers_count = multipliers.size();

    // Step 1. Initializing the Table of computed scores for the possible positions

    // Important: Adding 1 to handle the base-cases (out of bounds)
    //   -> Having out of bound cases result in 0 (no score)
    vector<vector<int>> scores(multipliers_count + 1, vector<int>(multipliers_count + 1, 0));

    // Step 2. Calculating the maximum score for each interval with each number of remaining Multipliers / Operations
    //    - Interval describes the positions of the Start Pointer (Tracked) and End Pointer (Inferred) -> Start-Pointer
    //    - Count describes the number of remaining Multipliers and operations with them -> Count
    //  -> Calculating the best score to get for each interval for each remaining number of positions

    int end;
    int start_move_score, end_move_score;

    // Flow: Starting from the end - All operations except the last one used up
    //   1. Considering all numbers of remaining positions
    //   2. Considering all POSSIBLE intervals that can be formed -> Starting from the Count each time

    for (int count = multipliers_count - 1; count >= 0; count--) {
        // SUPER-IMPORTANT: Starting from the counter instead of starting from the very beginning / end
        //      -> Allows considering only all the POSSIBLE intervals that could be formed
        for (int start = count; start >= 0; start--) {
            // a) Calculating the corresponding End-Pointer
            end = nums_count - 1 - (count - start);

            // b) Case 1. Moving the start -> Start multiplication result and score for the moved Start-Pointer Interval
            start_move_score = (nums[start] * multipliers[count]) + scores[start + 1][count + 1];

            // c) Case 2. Moving the end -> End multiplication result and score for the moved End-Pointer Interval
            end_move_score = (nums[end] * multipliers[count]) + scores[start][count + 1];

            // d) Choosing the case which provides the best results
            scores[start][count] = max(start_move_score, end_move_score);
        }
    }

    // Step 3. Returning the maximum score for the initial position with the ALL Multipliers / Operations allowed

    return scores[0][0];
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: nums = [1,2,3], multipliers = [3,2,1]
    // Output: 14
    vector<int> nums1{1, 2, 3};
    vector<int> multipliers1{3, 2, 1};
    cout << max_score(nums1, multipliers1) << endl;

    // Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
    // Output: 102
    vector<int> nums2{-5, -3, -3, -2, 7, 1};
    vector<int> multipliers2{-10, -5, 3, 4, 6};
    cout << max_score(nums2, multipliers2) << endl;

    return 0;
}
