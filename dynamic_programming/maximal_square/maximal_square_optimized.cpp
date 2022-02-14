#include <iostream>
#include <vector>

using namespace std;

// Optimization: Only storing the square-sizes from the previous considered row
//   - Never accessing any rows EXCEPT the previous one
//   -> Makes sense to just cache / keep the previous row square-sizes
//   => Updating at runtime

int min3(int v1, int v2, int v3) {
    return min(v1, min(v2, v3));
}

int square_value(char val) {
    return val == '1' ? 1 : 0;
}

int find_maximal_square(vector<vector<char>>& matrix) {
    // Step 0. Determining dimensions of the matrix and the maximal size (none by default)

    const int rows = matrix.size();
    const int columns = matrix[0].size();

    int maximal_size = 0;

    // Step 1. Initializing the previous row to the very bottom row (Iterating from bottom to top)
    //   + Checking if there is a square with at least the value of 1 (Minimum size by default)

    vector<int> previous_row(columns);

    for (int column = 0; column < columns; column++) {
        previous_row[column] = square_value(matrix[rows - 1][column]);

        if (matrix[rows - 1][column] == '1') maximal_size = 1;
    }

    // Step 2. Calculating all the squares and finding the maximal size

    vector<int> current_row(columns);

    for (int row = rows - 2; row >= 0; row--) {
        current_row[columns - 1] = square_value(matrix[row][columns - 1]);

        maximal_size = max(maximal_size, current_row[columns - 1]);

        for (int column = columns - 2; column >= 0; column--) {
            if (matrix[row][column] == '0') {
                current_row[column] = 0;
            } else {
                current_row[column] = min3(
                    current_row[column + 1], // Right
                    previous_row[column], // Bottom
                    previous_row[column + 1] // Right-Bottom
                ) + 1;

                maximal_size = max(maximal_size, current_row[column]);
            }
        }

        previous_row = current_row;
    }

    // Step 3. Returning the area of the maximal square using the found maximal size

    return maximal_size * maximal_size;
}

int main() {
    // Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    // Output: 4
    vector<vector<char>> matrix {
        vector<char>{'1', '0', '1', '0', '0'},
        vector<char>{'1', '0', '1', '1', '1'},
        vector<char>{'1', '1', '1', '1', '1'},
        vector<char>{'1', '0', '0', '1', '0'}
    };
    cout << find_maximal_square(matrix) << endl;

    return 0;
}
