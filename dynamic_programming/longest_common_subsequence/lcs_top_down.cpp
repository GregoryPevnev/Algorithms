#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

int longest_common_subsequence_for(
    string text1,
    string text2,
    int pos1,
    int pos2,
    vector<vector<int>>& lengths
) {
    // Base-Case: Position of a string going out of bounds (Either first or second)

    if (pos1 >= text1.size() || pos2 >= text2.size()) {
        return 0;
    }

    // Recursion with Memoization

    if (lengths[pos1][pos2] == -1) {
        if (text1[pos1] == text2[pos2]) {
            // Case 1. Match is found -> Incrementing the number of matches + Moving BOTH Positions
            lengths[pos1][pos2] = longest_common_subsequence_for(text1, text2, pos1 + 1, pos2 + 1, lengths) + 1;
        } else {
            // Case 2. No Match is found -> Trying out 2 Recurrences
            //    a) Moving the position of the first string
            //    b) Moving the position of the second string
            //  -> Checking which one provides the LCS in the long run
            lengths[pos1][pos2] = max(
                longest_common_subsequence_for(text1, text2, pos1, pos2 + 1, lengths),
                longest_common_subsequence_for(text1, text2, pos1 + 1, pos2, lengths)
            );
        }
    }

    return lengths[pos1][pos2];
}

int longest_common_subsequence(string text1, string text2) {
    vector<vector<int>> lengths(text1.size(), vector<int>(text2.size(), -1));

    return longest_common_subsequence_for(text1, text2, 0, 0, lengths);
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
