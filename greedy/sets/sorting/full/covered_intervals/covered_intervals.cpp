#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Comparator: Used for sorting intervals
bool compare_intervals(vector<int>& interval1, vector<int>& interval2) {
    // 1) Sorting by the Starting-Time (Ascending)
    if (interval1[0] != interval2[0]) return interval1[0] < interval2[0];

    // 2) Sorting by the Duration (Descending)
    return (interval1[1] - interval1[0]) > (interval2[1] - interval2[0]);
}

int remove_covered_intervals(vector<vector<int>>& intervals) {
    const int total_intervals = intervals.size();

    // Step 1. Sorting / Ordering the Intervals by Starting-Time (ASC) and Duration (DESC)

    sort(intervals.begin(), intervals.end(), compare_intervals);

    // Step 2. Picking candidate Covering-Intervals and skipping all the Covered-Intervals

    int interval_num = 0; // Pointer to the current interval
    int included_intervals_count = 0; // Counter of the number of remaining Intervals (NOT Covered)

    // As long as there are intervals left
    while (interval_num < total_intervals) {
        // a) Picking a candidate Covering-Interval
        vector<int>& current_interval = intervals[interval_num++];

        // b) Skipping all the Covered-Intervals
        while (interval_num < total_intervals && intervals[interval_num][1] <= current_interval[1]) {
            interval_num++;
        }

        // c) Including the Covering-Intervals
        included_intervals_count++;
    }

    // Returning the number of Intervals that were NOT covered

    return included_intervals_count;
}

// ---------------------------------------------------------------------------------------------------------------------
// Testing
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: intervals = [[1,4],[3,6],[2,8]]
    // Output: 2
    vector<vector<int>> intervals{
        vector<int>{1, 4},
        vector<int>{3, 6},
        vector<int>{2, 8}
    };

    cout << remove_covered_intervals(intervals) << endl;

    return 0;
}
