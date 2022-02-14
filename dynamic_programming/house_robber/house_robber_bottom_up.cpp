#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int max_robbing(vector<int>& houses) {
    // Base-Cases

    const int total_houses = houses.size();

    if (total_houses < 2) return houses[0];
    if (total_houses < 3) return max(houses[0], houses[1]);

    vector<int> robbed(total_houses, -1);

    robbed[total_houses - 1] = houses[total_houses - 1];
    robbed[total_houses - 2] = max(houses[total_houses - 1], houses[total_houses - 2]);
    // IMPORTANT: The pre-last house could still be skipped for robbing the very last house
    //   - The best possible case could EITHER be 1) Robbing the pre-last house and stopping
    //                                            2) Ribbing the last house and stopping

    // Iteration with Tabulation

    int robbing_current;
    int robbing_next;

    for (int house = total_houses - 3; house >= 0; house--) {
        robbing_current = houses[house] + robbed[house + 2];
        robbing_next = robbed[house + 1];

        robbed[house] = max(robbing_current, robbing_next);
    }

    return robbed[0];
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
