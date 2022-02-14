// Reference: https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <iostream>
#include <vector>

#define ALPHABET_SIZE 256

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Idea:
//   1) Having two pointers for defining the current sub-string -> Start and End Pointers => Sliding Window
//   2) Keeping a Set of characters that were already encountered in the current sub-string
//   3) Changing the Set based on the Start and End Pointers

int longest_unique_substring(string str) {
    // Step 0. Getting the string length and checking whether it is empty -> No characters at all => Nothing

    const int length = str.size();

    if (length == 0) return 0;

    // Step 1. Establishing the sub-string using the Start and End Pointers - Just the first character initially

    int start = 0, end = 1;

    // Step 2. Building a Set of encountered characters -> Adding the first character to the set

    vector<bool> substr_chars(ALPHABET_SIZE, false);
    substr_chars[str[start]] = true;

    // Step 3. Iterating over each character and moving the window accordingly

    int max_length = 1; // The maximum length of the unique substring - Just one character by default

    while (end < length) {
        // a) Checking whether the current substring is the longest one
        max_length = max(max_length, end - start);

        // b) If the current character is already in the subset then the Start-Pointer is moved
        //     -> Moving to the character AFTER the PREVIOUS-OCCURRENCE
        //     => Unsetting all the other encountered characters (Leave the sub-string / window)
        while(substr_chars[str[end]]) {
            substr_chars[str[start]] = false;

            start++;
        }

        // c) Adding the new character to the Set of characters
        //     - Resets the character if the window was moved
        substr_chars[str[end]] = true;

        // d) Going to the next character
        end++;
    }

    // Returning the maximum string-length of a unique sub-string
    // Important: Taking the final substring into the account - NOT considered (Loop is terminated beforehand)
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

