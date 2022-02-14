#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int climb_stairs_to_step(vector<int>& stairs, int step, vector<int>& costs) {
    // Base-Case: The top is reached

    if (step >= stairs.size()) return 0;

    // Recursion with Memoization

    if (costs[step] == -1) {
        // Recurrence 1: Climbing one step
        int climb_one_cost = climb_stairs_to_step(stairs, step + 1, costs);

        // Recurrence 2: Climbing two steps
        int climb_two_cost = climb_stairs_to_step(stairs, step + 2, costs);

        // Choosing the recurrence which results in the lowest cost
        costs[step] = min(climb_one_cost, climb_two_cost) + stairs[step];
    }

    return costs[step];
}

int climb_stairs(vector<int>& stairs) {
    vector<int> costs(stairs.size(), -1);

    // Trying multiple starting points - Free (All the states already already computed)

    int first_start_cost = climb_stairs_to_step(stairs, 0, costs);

    int second_start_cost = climb_stairs_to_step(stairs, 1, costs);

    return min(first_start_cost, second_start_cost);
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
