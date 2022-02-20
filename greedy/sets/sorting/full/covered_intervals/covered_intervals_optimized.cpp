#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Optimizations:
//   1. Sorting by the Ending-Time
//   2. Storing End-Time directly (The only parameter needed)

// Comparator: Used for sorting intervals
// Important: Since the Starting-Time is the same, comparing the Ending-Time is the same as comparing the Lengths
bool compare_intervals(vector<int>& interval1, vector<int>& interval2) {
    // 1) Sorting by the Starting-Time
    if (interval1[0] != interval2[0]) return interval1[0] < interval2[0];

    // 2) Sorting by the Ending-Time
    return interval1[1] > interval2[1];
}

int remove_covered_intervals(vector<vector<int>>& intervals) {
    const int total_intervals = intervals.size();

    sort(intervals.begin(), intervals.end(), compare_intervals);

    int interval_num = 0;
    int included_intervals_count = 0;

    int current_covering_end;

    while (interval_num < total_intervals) {
        current_covering_end = intervals[interval_num++][1];

        while (interval_num < total_intervals && intervals[interval_num][1] <= current_covering_end) {
            interval_num++;
        }

        included_intervals_count++;
    }

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
