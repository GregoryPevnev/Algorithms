#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

vector<int> find_diagonal_order(vector<vector<int>>& mat) {
    // Matrix: Finding the size of the matrix (Even)

    const int rows = mat.size();
    const int columns = mat[0].size();

    // Initialization

    // 1) Position (Row and Column) - Starting from the Top-Left
    int row = 0, col = 0;

    // 2) Direction - Set to Top-Right in the beginning
    int row_dir = -1, col_dir = 1;

    // 3) Result for the traversal
    vector<int> result(rows * columns);
    int result_pointer = 0;

    // Simulation / Walking - Until the final position is reached

    while (!(row == rows - 1 && col == columns - 1)) {
        // 1) Moving in the specified direction as long as it is valid -> Going out of bound
        while(row >= 0 && row < rows && col >= 0 && col < columns) {
            result[result_pointer++] = mat[row][col];

            row += row_dir;
            col += col_dir;
        }

        // 2) Preparing for the next diagonal

        // Preparation 1. Determining the direction - Making the opposite
        //   a) From Top-Right to Bottom-Left
        //   b) From Bottom-Left to Top-Right

        row_dir *= -1;
        col_dir *= -1;

        // Preparation 2. Computing the new starting position for the next diagonal

        if (col == columns) {
            // Up-Right. Case 1) Going down by 2 rows and repositioning to the last column
            row += 2;
            col = columns - 1;
        } else if (row == -1) {
            // Up-Right. Case 2) Repositioning to the first row
            row = 0;
        } else if (row == rows) {
            // Down-Left. Case 1) Going right by 2 columns and repositioning to the last row
            col += 2;
            row = rows - 1;
        } else if (col == -1) {
            // Down-Left. Case 2) Repositioning to the first column
            col = 0;
        }
    }

    // Final: Populating the very last position - Bottom-Right

    result[result_pointer] = mat[row][col];

    // Result: Returning the final traversal

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
