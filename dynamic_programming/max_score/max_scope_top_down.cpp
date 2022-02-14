#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int max_score_for(
    vector<int>& nums,
    vector<int>& multipliers,
    int start,
    int count,
    vector<vector<int>>& scores
) {
    // # of times the end-pointer was moved = # of times the start-pointer was NOT moved
    //    -> Using for inferring the end-pointer position from the last index (moved the calculated number of times)
    int end = nums.size() - 1 - (count - start);

    // Base Case

    if (count >= multipliers.size()) return 0;

    // Recursion with Memoization

    if (scores[start][count] == INT_MIN) {
        // Recurrence 1: Multiplying the Start-Number and Moving the Start-Pointer
        //   -> Multiplication of the Start-Number + The best Score for the remaining interval (After the Start-Pointer)
        int start_score = nums[start] * multipliers[count];
        int new_start_interval_score = max_score_for(nums, multipliers, start + 1, count + 1, scores);
        int total_start_score = start_score + new_start_interval_score;

        // Recurrence 2: Multiplying the End-Number and Moving the End-Pointer
        //   -> Multiplication of the End-Number + The best Score for the remaining interval (Before the End-Pointer)
        int end_score = nums[end] * multipliers[count];
        int new_end_interval_score = max_score_for(nums, multipliers, start, count + 1, scores);
        int total_end_score = end_score + new_end_interval_score;

        // Choosing the recurrence which produces the best Score
        scores[start][count] = max(total_start_score, total_end_score);
    }

    return scores[start][count];
}

int max_score(vector<int>& nums, vector<int>& multipliers) {
    // Important: The start-pointer is incremented at most only by [Multipliers-Count]
    //    -> No need to use the full range for Start-Pointer State-Variable
    const int multipliers_count = multipliers.size();
    vector<vector<int>> scores(multipliers_count, vector<int>(multipliers_count, INT_MIN));

    return max_score_for(nums, multipliers, 0, 0, scores);
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
