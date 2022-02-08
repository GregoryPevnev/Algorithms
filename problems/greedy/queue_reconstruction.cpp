// Reference: https://leetcode.com/problems/queue-reconstruction-by-height/
// Tags: Greedy, Set, Sorting (Complex) + Unconventional performance
// Takeaway: Never doubt the solution due to the performance - Only start optimizing if the solution fails Time-Wise
//    -> Sometimes inserting into a Vector / Dynamic-Array is NOT such a bad thing

#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

bool people_cmp(const vector<int>& p1, const vector<int>& p2) {
    if (p1[0] == p2[0]) return p1[1] < p2[1];

    return p1[0] > p2[0];
}

vector<vector<int>> reconstruct_queue(vector<vector<int>> people) {
    vector<vector<int>> queue; queue.reserve(people.size());

    sort(people.begin(), people.end(), people_cmp);

    for (vector<int> const &person : people) {
        queue.insert(queue.begin() + person[1], person);
    }

    return queue;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

void print_queue(vector<vector<int>>& people) {
    for (vector<int> const &person : people) {
        cout << "[" << person[0] << ", " << person[1] << "]" << " ";
    }
    cout << endl;
}

int main() {
    // Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    // Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

    vector<vector<int>> people {
        vector<int>{7, 0},
        vector<int>{4, 4},
        vector<int>{7, 1},
        vector<int>{5, 0},
        vector<int>{6, 1},
        vector<int>{5, 2}
    };

    vector<vector<int>> queue = reconstruct_queue(people);

    print_queue(queue);

    return 0;
}
