// Reference: https://leetcode.com/problems/intervals-between-identical-elements
// Guide: https://leetcode.com/problems/intervals-between-identical-elements/discuss/1647454/C%2B%2B-or-prefix-and-suffix-array-or-with-explanation
// Tags: Greedy, Prefix Sum, Suffix Sum, Hash-Map, Positions / Indexes

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// TODO: Proper explanation with a Diagram

// Hash-Map from value to an array of positions at which the value can be found
typedef unordered_map<int, vector<int>> positions_map;

vector<long long> interval_distances(vector<int>& values) {
    const int total_values = values.size();

    // Step 1. Building the Map of positions for each Value

    positions_map value_positions;

    for (int i = 0; i < total_values; i++) {
        value_positions[values[i]].push_back(i);
    }

    // Step 2. Calculating Prefix and Suffix Interval-Distances for each Position of a value
    //   Prefix: Total distance from a specific position to all preceding positions with the same value
    //   Suffix: Total distance from a specific position to all following positions with the same value

    vector<long long> prefix_sums(total_values, 0);
    vector<long long> suffix_sums(total_values, 0);

    // Temporary variables
    int positions_length; // Number of positions for a specific value
    long long new_sub_intervals_length; // Total length of all new Sub-Intervals Distances for a new Position

    // For each Array of Positions of Values
    for (positions_map::iterator it = value_positions.begin(); it != value_positions.end(); it++) {
        // Initialize the Array of Positions
        vector<int>& positions = it->second;
        positions_length = positions.size();

        // Calculating Prefix-Sums with all Interval Distances - Iterating from the start (Accumulating from the start)
        //   - The first Position is not going to have any preceding Intervals
        for (int i = 1, c = 1; i < positions_length; i++, c++) {
            // Total lengths of Sub-Intervals for the new Position
            new_sub_intervals_length = long(positions[i] - positions[i - 1]) * c;

            // Total length of all Intervals for the new Position
            //    1) Total length of all Intervals for the previous Position
            //    2) Sub-Intervals for the current Position
            prefix_sums[positions[i]] =  prefix_sums[positions[i - 1]] + new_sub_intervals_length;
        }

        // Calculating Suffix-Sums with all Interval Distances - Iterating from the end (Accumulating from the end)
        //   - The last Position is not going to have any following Intervals
        for (int i = positions_length - 2, c = 1; i >= 0; i--, c++) {
            // Total lengths of Sub-Intervals for the new Position
            new_sub_intervals_length = long(positions[i + 1] - positions[i]) * c;

            // Total length of all Intervals for the new Position
            //    1) Total length of all Intervals for the previous Position
            //    2) Sub-Intervals for the current Position
            suffix_sums[positions[i]] =  suffix_sums[positions[i + 1]] + new_sub_intervals_length;
        }
    }

    // Step 3. Calculating Interval-Distances for each Position -> Sum of
    //    1) Preceding Interval-Distances of the Position (Prefix-Sums)
    //    2) Following Interval-Distances of the Position (Suffix-Sums)

    vector<long long> distances(total_values);

    for (int i = 0; i < total_values; i++) {
        distances[i] = prefix_sums[i] + suffix_sums[i];
    }

    return distances;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

void print_distances(const vector<long long>& distances) {
    cout << "[ ";
    for (long long const &idx : distances) cout << idx << " ";
    cout << "]" << endl;
}

int main() {
    // Input: [2,1,3,1,2,3,3]
    // Output: [4,2,7,2,4,4,5]
    vector<int> v{2, 1, 3, 1, 2, 3, 3};
    const vector<long long> result = interval_distances(v);
    print_distances(result);

    return 0;
}

