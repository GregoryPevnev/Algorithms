#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int climb_stairs(vector<int>& stairs) {
    // Initializing the Table

    const int total_steps = stairs.size();

    vector<int> costs(total_steps, -1);

    // Defining Base-Cases

    costs[total_steps - 1] = stairs[total_steps - 1];
    costs[total_steps - 2] = stairs[total_steps - 2];

    // Iterating with Tabulation - Choosing the best option based on the computed results

    for (int current_step = total_steps - 3; current_step >= 0; current_step--) {
        costs[current_step] = min(costs[current_step + 1], costs[current_step + 2]) + stairs[current_step];
    }

    return min(costs[0], costs[1]);
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [10,15,20]
    // Output: 15
    vector<int> stairs1{10, 15, 20};
    cout << climb_stairs(stairs1) << endl;

    // Input: [1,100,1,1,1,100,1,1,100,1]
    // Output: 6
    vector<int> stairs2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << climb_stairs(stairs2) << endl;

    return 0;
}
