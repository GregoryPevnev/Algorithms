#include <iostream>
#include <vector>

using namespace std;

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

    // Step 1. Initializing square-sizes for the edge-squares

    vector<vector<int>> squares(rows, vector<int>(columns, 0));

    for (int row = 0; row < rows; row++) {
        squares[row][columns - 1] = square_value(matrix[row][columns - 1]);

        if (matrix[row][columns - 1] == '1') maximal_size = 1;
    }

    for (int column = 0; column < columns; column++) {
        squares[rows - 1][column] = square_value(matrix[rows - 1][column]);

        if (matrix[rows - 1][column] == '1') maximal_size = 1;
    }

    // Step 2. Calculating all the squares and finding the maximal size

    for (int row = rows - 2; row >= 0; row--) {
        for (int column = columns - 2; column >= 0; column--) {
            if (matrix[row][column] == '0') {
                squares[row][column] = 0;
            } else {
                squares[row][column] = min3(
                    squares[row][column + 1], // Right
                    squares[row + 1][column + 1], // Bottom
                    squares[row + 1][column + 1] // Right-Bottom
                ) + 1;

                maximal_size = max(maximal_size, squares[row][column]);
            }
        }
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
