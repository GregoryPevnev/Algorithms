// Reference: https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <string>
#include <vector>

#define ALPHABET_SIZE 26

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Anagram Checking: Comparing the number of character-frequencies on the strings of the same size
//    - If all the characters have the EXACT same frequencies then they are anagrams of each other

// Approach: Keeping a counter map of character frequencies for the current running substring
//        1) Checking whether the current substring has the same frequencies as the target string -> Anagram found
//        2) Adding the new character to the frequency counters of the substring (Always)
//        3) Removing the previous character from the frequency counters of the substring (If the substring is FULL)
//   => Sliding window (Manipulating for the next and the previous values for the window)
//        New Character: Adding to the frequencies counter
//        Prior Character: Removing from the frequencies counter

vector<int> find_anagrams(string original, string target) {
    // Step 0. Initializing lengths

    const int original_length = original.size();
    const int target_length = target.size();

    // Step 1. Counting character frequencies of the target string

    vector<int> target_frequencies(ALPHABET_SIZE, 0);
    for (char const &ch : target) target_frequencies[ch - 'a']++;

    // Step 2. Initializing character frequencies of the running sub-string (None / 0s) + Matching Substrings (None)

    vector<int> substring_frequencies(ALPHABET_SIZE, 0);

    vector<int> matching_substrings;

    // Step 3. Running Sliding window on the original string

    for (int i = 0; i < original_length; i++) {
        // a) Checking for a matching anagram in the current substring by comparing the frequencies of the characters

        if (substring_frequencies == target_frequencies) {
            matching_substrings.push_back(i - target_length);
        }

        // b) Adding the new character in the window to the character-frequencies map

        substring_frequencies[original[i] - 'a']++;

        // c) Removing the old character that fell out of the window from the character-frequencies map
        //     - Only if the current sub-string is of the same size as the target string

        if (i >= target_length) {
            substring_frequencies[original[i - target_length] - 'a']--;
        }
    }

    // Extra: Checking for a matching anagram in the final / last substring - The loop Terminates before the last check

    if (substring_frequencies == target_frequencies) {
        matching_substrings.push_back(original_length - target_length);
    }

    // Result: Returning all the matching substring indexes

    return matching_substrings;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

void print_occurrences(const vector<int>& occurrences) {
    cout << "[ ";
    for (int const &idx : occurrences) cout << idx << " ";
    cout << "]" << endl;
}

int main() {
    // Input: original = "cbaebabacd", target = "abc"
    // Output: [0,6]
    const vector<int> occurrences1 = find_anagrams("cbaebabacd", "abc");
    print_occurrences(occurrences1);

    // Input: original = "abab", target = "ab"
    // Output: [0,1,2]
    const vector<int> occurrences2 = find_anagrams("abab", "ab");
    print_occurrences(occurrences2);

    return 0;
}
