// Reference: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Comparator: Making sure Balloons that start first go first in the sorted list
bool balloon_cmp(const vector<int>& balloon1, const vector<int>& balloon2) {
    return balloon1[0] < balloon2[0];
}

int min_arrows_count(vector<vector<int>>& balloons) {
    // Details regarding the current subset of spanning Balloons that can be shot down by a single arrow
    bool is_spanning = false; // Determines whether a Spanning-Interval is present (Only false for the first balloon)
    int spanning_start, spanning_end; // Specifies the start and end of the Spanning-Interval of Balloons
    //   -> Shooting an arrow anywhere between the start and end of the Spanning-Interval of Balloons pops them all

    // Sorting Balloons in ascending order by their Starts
    //    -> Ensures that the Spanning-Intervals of Balloons begin as close to the start as possible
    sort(balloons.begin(), balloons.end(), balloon_cmp);

    // Number of arrows that need to be shot - One for each Spanning-Interval of Balloons
    int arrows_count = 0;

    // Checking each Balloon ordered by their Start
    for (vector<int> const &balloon : balloons) {
        if (is_spanning && balloon[0] >= spanning_start && balloon[0] <= spanning_end) {
            // Case A. There is
            //    1) A Spanning-Interval of Balloons
            //    2) The current Balloon falls into it - At least partially (At least the start needs to be in it)
            //  -> Shrinking the start and end of the Spanning-Interval (Outlines the COMMON spanning-area)
            //  => Specifying the area where a single Arrow can pop ALL the Balloons in the current Spanning-Interval
            // Important: No need to add a new Arrow (The same arrow for ALL the Balloons in the current Interval)
            spanning_start = min(spanning_start, balloon[0]);
            spanning_end = min(spanning_end, balloon[1]);
        } else {
            // Case B. There is either no Spanning-Interval or the current Balloon does NOT fit into it (EVEN PARTIALLY)
            //   1) Initializing the new Spanning-Interval using the width of the current Balloon
            //       -> All the upcoming ones are going to either fall into it and shrink it or NOT fall at all
            is_spanning = true;
            spanning_start = balloon[0];
            spanning_end = balloon[1];

            //   2) Increasing the number of arrows to account for the Arrow for the NEW Spanning-Interval
            //       - That was initialized just now
            arrows_count++;
        }
    }

    return arrows_count;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [[10,16],[2,8],[1,6],[7,12]]
    // Output: 2
    vector<vector<int>> balloons1{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << min_arrows_count(balloons1) << endl;

    // Input: [[1,2],[3,4],[5,6],[7,8]]
    // Output: 4
    vector<vector<int>> balloons2{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << min_arrows_count(balloons2) << endl;

    // Input: points = [[1,2],[2,3],[3,4],[4,5]]
    // Output: 2
    vector<vector<int>> balloons3{{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << min_arrows_count(balloons3) << endl;

    return 0;
}
