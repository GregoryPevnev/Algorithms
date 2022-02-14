// Reference: https://leetcode.com/problems/non-overlapping-intervals/
// Specific solution that uses the same approach as the regular interval-scheduling - counting differently

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

// Same as the regular Interval-Scheduling solution - Counting removed / dropped Intervals instead
int min_intervals_to_remove(vector<vector<int>>& intervals) {
    int current_time = INT32_MIN;
    int removed_intervals = 0;

    sort(intervals.begin(), intervals.end(), interval_cmp());

    for (vector<int> const interval : intervals) {
        if (current_time > interval[0]) {
            removed_intervals++;
        } else {
            current_time = interval[1];
        }
    }

    return removed_intervals;
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
