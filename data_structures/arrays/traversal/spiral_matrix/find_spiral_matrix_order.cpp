#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

vector<int> find_spiral_matrix_order(vector<vector<int>>& matrix) {
    // Matrix: Calculating rows, columns and cells
    const int rows = matrix.size();
    const int columns = matrix[0].size();
    const int cells = rows * columns;

    // Bounds: Initializing bounds for the spiral traversal
    int start_row = 0, end_row = rows - 1;
    int start_col = 0, end_col = columns - 1;

    // Row and Column for traversal - Initializing once for performance
    int row, col;

    // Path for outputting the traversal / spiral order
    vector<int> path(cells);
    int path_top = 0;

    // Performing the traversal in the spiral order
    while (path_top < cells) {
        // Step 1. Top Row - Horizontal to the Right
        for(row = start_row, col = start_col; col <= end_col && path_top < cells; col++) {
            path[path_top++] = matrix[row][col];
        }

        // Step 2. Right Column - Vertical to the Bottom
        for(row = start_row + 1, col = end_col; row <= end_row && path_top < cells; row++) {
            path[path_top++] = matrix[row][col];
        }

        // Step 3. Bottom Row - Horizontal to the Left
        for(row = end_row, col = end_col - 1; col >= start_col && path_top < cells; col--) {
            path[path_top++] = matrix[row][col];
        }

        // Step 4. Left Column - Vertical to the Top
        // Important: Excluding the starting-row to avoid looping
        for(row = end_row - 1, col = start_col; row > start_row && path_top < cells; row--) {
            path[path_top++] = matrix[row][col];
        }

        // Changing the Bounds afterwards (Shrinking by one)
        start_row++; end_row--;
        start_col++; end_col--;
    }

    return path;
}

// ---------------------------------------------------------------------------------------------------------------------
// Testing
// ---------------------------------------------------------------------------------------------------------------------

void print_path(vector<int>& path) {
    cout << "[";
    for (int const &num : path) cout << " " << num << " ";
    cout << "]" << endl;
}

int main() {
    // Input: [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    // Output: [1,2,3,4,8,12,11,10,9,5,6,7]

    vector<vector<int>> matrix {
        vector<int>{1, 2, 3, 4},
        vector<int>{5, 6, 7, 8},
        vector<int>{9, 10, 11, 12}
    };

    vector<int> path = find_spiral_matrix_order(matrix);

    print_path(path);

    return 0;
}

