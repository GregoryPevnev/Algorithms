#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int max_robbing_for(vector<int>& houses, int house, vector<int>& robbed) {
    // Base Case

    if (house >= houses.size()) return 0;

    // Recursion with Memoization

    if (robbed[house] == -1) {
        // Recurrence 1: Robbing this house and going to the one after the next one (If there is one)
        int robbing_current = houses[house] + max_robbing_for(houses, house + 2, robbed);

        // Recurrence 2: Skipping this house and going to consider the next one
        int robbing_next = max_robbing_for(houses, house + 1, robbed);

        // Choosing the recurrence which brings the highest amount
        robbed[house] = max(robbing_current, robbing_next);
    }

    return robbed[house];
}

int max_robbing(vector<int>& houses) {
    vector<int> robbed(houses.size(), -1);

    return max_robbing_for(houses, 0, robbed);
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [1,2,3,1]
    // Output: 4
    vector<int> houses1 {1, 2, 3, 1};
    cout << max_robbing(houses1) << endl;

    // Input: [2,7,9,3,1]
    // Output: 12
    vector<int> houses2 {2, 7, 9, 3, 1};
    cout << max_robbing(houses2) << endl;

    return 0;
}
