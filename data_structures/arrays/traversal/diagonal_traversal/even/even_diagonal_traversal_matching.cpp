#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Performance: Using a Vector / Array is better than using a Hash-Table in this case - Bounded SMALL range
//    - Tested and measured

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

vector<int> find_diagonal_order(vector<vector<int>>& mat) {
    // Matrix: Finding the size of the matrix (Even)

    const int rows = mat.size();
    const int columns = mat[0].size();

    // Step 0. Initializing the Map of Diagonals to store each Diagonal positions / items

    const int diagonals_count = rows + columns - 1;

    vector<list<int>> diagonals(diagonals_count + 1);

    // Step 1. Building / Populating each Diagonal with items that belong to it
    //   - Top to Bottom / First to Last Rows ordering
    //   -> Has to be reversed for Top-Right traversal

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            diagonals[row + col].push_back(mat[row][col]);
        }
    }

    vector<int> traversal(rows * columns);
    int traversal_pointer = 0;

    for (int diagonal_num = 0; diagonal_num <= diagonals_count; diagonal_num++) {
        list<int>& d = diagonals[diagonal_num];

        if (diagonal_num % 2 == 0) {
            // Top-Right Diagonal - Outputting from the last rows to the first rows
            for(list<int>::reverse_iterator it = d.rbegin(); it != d.rend(); it++) {
                traversal[traversal_pointer++] = *it;
            }
        } else {
            // Bottom-Left Diagonal - Outputting from the first rows to the last rows
            for(list<int>::iterator it = d.begin(); it != d.end(); it++) {
                traversal[traversal_pointer++] = *it;
            }
        }
    }

    return traversal;
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
    // Input: [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [1,2,4,7,5,3,6,8,9]

    vector<vector<int>> mat{
            vector<int>{1, 2, 3},
            vector<int>{4, 5, 6},
            vector<int>{7, 8, 9}
    };

    vector<int> traversal = find_diagonal_order(mat);

    print_traversal(traversal);

    return 0;
}
