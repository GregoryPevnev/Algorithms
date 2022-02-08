// Reference: https://leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Adapted BFS

int min_jumps(vector<int>& jumps) {
    const int jumps_count = jumps.size();

    const int last_position = jumps_count - 1; // End of the traversal / target position to reach
    int max_position = 0; // Last position that can be reached from the current level (Just the start in the beginning)
    int current_position = 0; // Current position that is being considered

    int jump_levels = 0; // Number of BFS levels / jump levels to reach the last-position / target-position

    // Until the Last-Position is within the reach from the current level (Can be prior level or the same level)
    while (max_position != last_position) {
        // Initializing running / temporary accumulator for the NEXT Maximum-Position
        int level_max_position = max_position;

        // Iterating until the end of this level / Considering all the position from the current level
        //    -> Checking the latest / furthest position that can be accessed from each position in the current level
        //    => Finding the furthest position that can be reached from the current level (Max / Accumulating)
        while(current_position <= max_position) {
            level_max_position = max(level_max_position, jumps[current_position] + current_position);

            current_position++;
        }

        // Assigning the next Max-Position -> End-Position for the next level
        max_position = min(level_max_position, last_position);

        // Incrementing the number of jumps - One jump per level (Optimal)
        jump_levels++;
    }

    // Returning the minimum number of jumps = Jumps between the levels in the BFS
    return jump_levels;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [2,3,0,1,4]
    // Output: 2
    vector<int> jumps1{2, 3, 0, 1, 4};
    cout << min_jumps(jumps1) << endl;

    return 0;
}
