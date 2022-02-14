#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int longest_common_subsequence(string text1, string text2) {
    // Step 0. Determining and saving lengths of both text-sequences

    const int text1_length = text1.size();
    const int text2_length = text2.size();

    // Step 1. Initializing table of maximum lengths from each starting positions for BOTH text-sequences
    //    - Adding an extra length in order to accommodate out of bounds base-cases

    vector<vector<int>> lengths(text1_length + 1, vector<int>(text2_length + 1, 0));

    // Step 2. Finding the maximum length for each combination of starting position
    //   - Starting from the end in order for the Tabulation to work properly

    for (int pos1 = text1_length - 1; pos1 >= 0; pos1--) {
        for (int pos2 = text2_length - 1; pos2 >= 0; pos2--) {
            if (text1[pos1] == text2[pos2]) {
                // Case 1. Matching characters -> Moving both positions
                lengths[pos1][pos2] = lengths[pos1 + 1][pos2 + 1] + 1;
            } else {
                // Case 2. Mismatching characters -> Moving the position which gives the longest sequence result
                lengths[pos1][pos2] = max(lengths[pos1 + 1][pos2], lengths[pos1][pos2 + 1]);
            }
        }
    }

    // Step 3. Returning the length of the longest text-sequence from the starting positions / initial positions

    return lengths[0][0];
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: text1 = "abcde", text2 = "ace"
    // Output: 3
    string text1 = "abcde";
    string text2 = "ace";
    cout << longest_common_subsequence(text1, text2) << endl;

    return 0;
}
