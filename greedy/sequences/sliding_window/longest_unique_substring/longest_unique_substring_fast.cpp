// Reference: https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <iostream>
#include <vector>

#define ALPHABET_SIZE 256

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Optimization: Storing the last positions of each encountered character
//     -> Jumping to them directly in case of duplication / finding the same character

int longest_unique_substring(string str) {
    const int length = str.size();

    if (length == 0) return 0;

    vector<int> substr_char_positions(ALPHABET_SIZE, -1);
    substr_char_positions[str[0]] = 0;

    int start = 0, end = 1;

    int max_length = 1;

    while (end < length) {
        max_length = max(max_length, end - start);

        // Moving the start of the window directly to the character AFTER the last occurrence
        //    - Only if the occurrence is within the current sub-string (Not from before the moving)
        if (substr_char_positions[str[end]] >= start) {
            start = substr_char_positions[str[end]] + 1;
        }

        substr_char_positions[str[end]] = end;

        end++;
    }

    // Important: Taking the final substring into the account

    return max(max_length, end - start);
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: "abcabcdbb"
    // Output: 4
    cout << longest_unique_substring("abcabcdbb") << endl;

    // Input: "bbbbb"
    // Output: 1
    cout << longest_unique_substring("bbbbb") << endl;

    // Input: "pwwkew"
    // Output: 3
    cout << longest_unique_substring("pwwkew") << endl;

    // Input: " "
    // Output: 1
    cout << longest_unique_substring(" ") << endl;

    // Input: "au"
    // Output: 2
    cout << longest_unique_substring("au") << endl;

    return 0;
}

