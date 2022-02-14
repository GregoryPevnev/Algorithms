// Reference:
// Tags: Brute Force
// Complexity: O(1)
//    1) For computing all matching Timers: 9999
//    2) For checking each matching Timer: 4

#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Brute-Force Solution: Trying all possible combinations and finding the best one
//   1) Finding a combination by coming up with a specific permutation (Timer with 4 digits)
//   2) Checking whether the current permutation (Timer) is matching / correct
//   3) Finding the cost of the specific permutation (Setting the Timer)
//   4) Finding the minimal cost of all the computed

// Calculating the cost of setting a specific timer - known to be correct
int find_cost(int timer[4], int start, int move_cost, int push_cost) {
    int cost = 0;

    // Skipping the leading 0s - Pushing them is NEVER going to help (Just extra cost for nothing)
    int position = 0;
    while(position < 4 && timer[position] == 0) position++;

    int current = start;

    // Determining the cost of getting the remaining actual digits ->
    //      - Pushing (Always)
    //      - Moving (When not on the correct digit)
    while (position < 4) {
        if (timer[position] != current) {
            current = timer[position];

            cost += move_cost;
        }

        cost += push_cost;

        position++;
    }

    return cost;
}

// Finding the minimal cost by trying all possible combinations that are correct and checking their costs
int find_min_cost(int start, int move_cost, int push_cost, int target_seconds) {
    int minutes, seconds;
    int timer[4];

    int min_cost = INT32_MAX;
    int current_cost;

    // Making all possible permutations of 4 digits (Timers)
    for (int m1 = 0; m1 < 10; m1++) {
        for (int m2 = 0; m2 < 10; m2++) {
            for (int s1 = 0; s1 < 10; s1++) {
                for (int s2 = 0; s2 < 10; s2++) {
                    // Calculating the current Minutes and Seconds in the current permutation of them
                    minutes = m1 * 10 + m2;
                    seconds = s1 * 10 + s2;

                    // Checking whether the current minutes and seconds permutation is correct
                    //    -> Produces the required Seconds
                    if ((minutes * 60 + seconds) == target_seconds) {
                        // Populating the Timer with Minutes and Seconds
                        timer[0] = m1;
                        timer[1] = m2;
                        timer[2] = s1;
                        timer[3] = s2;

                        // Calculating the cost of setting the current Timer
                        current_cost =  find_cost(timer, start, move_cost, push_cost);

                        // Checking whether the cost of setting the Timer is the lowest for the given Target-Seconds
                        min_cost = min(min_cost, current_cost);
                    }
                }
            }
        }
    }

    return min_cost;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: startAt = 1, moveCost = 2, pushCost = 1, targetSeconds = 600
    // Output: 6
    cout << find_min_cost(1, 2, 1, 600) << endl;

    // Input: startAt = 0, moveCost = 1, pushCost = 2, targetSeconds = 76
    // Output: 6
    cout << find_min_cost(0, 1, 2, 76) << endl;

    return 0;
}
