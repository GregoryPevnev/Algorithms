// Reference: https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

bool can_jump(vector<int>& jumps) {
    const int jumps_count = jumps.size();

    if (jumps_count == 0) return false;

    if (jumps_count == 1) return true;

    int last_position = jumps_count - 1, check_position = jumps_count - 2;

    while (check_position >= 0) {
        if (check_position + jumps[check_position] >= last_position) last_position = check_position;

        check_position--;
    }

    return last_position == 0;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [2,3,1,1,4]
    // Output: true
    vector<int> jumps1{2, 3, 1, 1, 4};
    cout << can_jump(jumps1) << endl;

    // Input: [3,2,1,0,4]
    // Output: false
    vector<int> jumps2{3, 2, 1, 0, 4};
    cout << can_jump(jumps2) << endl;

    return 0;
}
