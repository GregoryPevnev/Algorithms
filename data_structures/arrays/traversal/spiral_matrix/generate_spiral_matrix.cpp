#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

vector<vector<int>> generate_spiral_matrix(const int rows, const int columns) {
    // Matrix: Calculating total numbers for each cell (Same as the number of cells)
    const int total_nums = rows * columns;

    // Bounds: Initializing bounds for the spiral traversal
    int start_row = 0, end_row = rows - 1;
    int start_col = 0, end_col = columns - 1;

    // Row and Column for traversal - Initializing once for performance
    int row, col;

    // Matrix for creating / filling with the items in spiral order
    vector<vector<int>> matrix(rows, vector<int>(columns));

    // Number / Counter for the spiral matrix nums
    int current_num = 1;

    // Performing the traversal in the spiral order
    while (current_num <= total_nums) {
        // Step 1. Top Row - Horizontal to the Right
        for(row = start_row, col = start_col; col <= end_col && current_num <= total_nums; col++) {
            matrix[row][col] = current_num++;
        }

        // Step 2. Right Column - Vertical to the Bottom
        for(row = start_row + 1, col = end_col; row <= end_row && current_num <= total_nums; row++) {
            matrix[row][col] = current_num++;
        }

        // Step 3. Bottom Row - Horizontal to the Left
        for(row = end_row, col = end_col - 1; col >= start_col && current_num <= total_nums; col--) {
            matrix[row][col] = current_num++;
        }

        // Step 4. Left Column - Vertical to the Top
        // Important: Excluding the starting-row to avoid looping
        for(row = end_row - 1, col = start_col; row > start_row && current_num <= total_nums; row--) {
            matrix[row][col] = current_num++;
        }

        // Changing the Bounds afterwards (Shrinking by one)
        start_row++; end_row--;
        start_col++; end_col--;
    }

    return matrix;
}

// ---------------------------------------------------------------------------------------------------------------------
// Testing
// ---------------------------------------------------------------------------------------------------------------------

void print_matrix(vector<vector<int>>& matrix) {
    for (vector<int> const &row : matrix) {
        cout << "[";
        for (int const &cell : row) cout << " " << cell << " ";
        cout << "]" << endl;
    }
}

int main() {
    // Input: rows = 3, columns = 3
    // Output: [[1,2,3],[8,9,4],[7,6,5]]

    const int rows = 3;
    const int columns = 3;

    vector<vector<int>> matrix = generate_spiral_matrix(rows, columns);

    print_matrix(matrix);

    return 0;
}
