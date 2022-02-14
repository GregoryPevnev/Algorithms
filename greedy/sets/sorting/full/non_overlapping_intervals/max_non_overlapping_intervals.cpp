// Reference: https://leetcode.com/problems/non-overlapping-intervals/
// Generic solution that uses the common interval-scheduling problem

#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Sorting Intervals in ascending order by their End-Times
struct interval_cmp {
    bool operator()(const vector<int>& interval1, const vector<int>& interval2) {
        return interval1[1] < interval2[1];
    }
};

// Regular Interval-Scheduling Algorithm
//   1. Sorting by End-Times to optimize choosing the Intervals that allow for the most upcoming Intervals
//   2. Choosing each Interval one by one and checking whether it is possible to select it
int max_non_overlapping_intervals(vector<vector<int>>& intervals) {
    int included_intervals = 0;
    int current_time = INT32_MIN;

    sort(intervals.begin(), intervals.end(), interval_cmp());

    for (vector<int> const interval : intervals) {
        if (interval[0] < current_time) continue;

        included_intervals++;
        current_time = interval[1];
    }

    return included_intervals;
}

// Determining the MINIMUM number of activity_selection that need to be removed for all the other activity_selection to NOT be overlapping
//   1) Counting the maximum number of Non-Overlapping Intervals
//   2) Finding the differance between the a) Total of Intervals and b) Max Non-Overlapping
//        -> The differance is the SMALLEST number of Intervals removed to make the rest Non-Overlapping
int min_intervals_to_remove(vector<vector<int>>& intervals) {
    return intervals.size() - max_non_overlapping_intervals(intervals);
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [[1,2],[2,3],[3,4],[1,3]]
    // Output: 1
    vector<vector<int>> intervals1{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << min_intervals_to_remove(intervals1) << endl;

    // Input: [[1,2],[1,2],[1,2]]
    // Output: 2
    vector<vector<int>> intervals2{{1, 2}, {1, 2}, {1, 2}};
    cout << min_intervals_to_remove(intervals2) << endl;

    // Input: [[1,2],[2,3]]
    // Output: 0
    vector<vector<int>> intervals3{{1, 2}, {2, 3}};
    cout << min_intervals_to_remove(intervals3) << endl;
}
