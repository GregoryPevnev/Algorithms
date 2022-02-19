#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

vector<int> find_diagonal_order(vector<vector<int>>& nums) {
    const int rows = nums.size();

    unordered_map<int, list<int>> diagonals;

    int max_diagonal_num = -1;
    int items_count = 0;

    int columns;

    for (int row = 0; row < rows; row++) {
        columns = nums[row].size();

        for (int column = 0; column < columns; column++) {
            diagonals[row + column].push_back(nums[row][column]);

            max_diagonal_num = max(max_diagonal_num, row + column);
            items_count++;
        }
    }

    vector<int> result(items_count);
    int result_pointer = 0;

    for (int diagonal_num = 0; diagonal_num <= max_diagonal_num; diagonal_num++) {
        list<int>& diagonal = diagonals[diagonal_num];

        for (list<int>::reverse_iterator it = diagonal.rbegin(); it != diagonal.rend(); it++) {
            result[result_pointer++] = *it;
        }
    }

    return result;
}

// ---------------------------------------------------------------------------------------------------------------------
// Testing
// ---------------------------------------------------------------------------------------------------------------------

void print_traversal(vector<int>& traversal) {
    cout << "[";
    for (int const &num : traversal) cout << " " << num << " ";
    cout << "]" << endl;
}

int main() {
    // Input: [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
    // Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]

    vector<vector<int>> nums{
        vector<int>{1, 2, 3, 4, 5},
        vector<int>{6, 7},
        vector<int>{8},
        vector<int>{9, 10, 11},
        vector<int>{12, 13, 14, 15, 16},
    };

    vector<int> traversal = find_diagonal_order(nums);

    print_traversal(traversal);

    return 0;
}
