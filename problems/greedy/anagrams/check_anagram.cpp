// Reference: https://leetcode.com/problems/permutation-in-string/

#include <iostream>
#include <string>
#include <vector>

#define ALPHABET_SIZE 26

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

bool check_anagram(string original, string target) {
    // Step 0. Initializing lengths

    const int original_length = original.size();
    const int target_length = target.size();

    // Step 1. Counting character frequencies of the target string

    vector<int> target_frequencies(ALPHABET_SIZE, 0);
    for (char const &ch : target) target_frequencies[ch - 'a']++;

    // Step 2. Initializing character frequencies of the running sub-string (None / 0s)

    vector<int> substring_frequencies(ALPHABET_SIZE, 0);

    // Step 3. Running Sliding window on the original string

    for (int i = 0; i < original_length; i++) {
        // a) Checking for a matching anagram in the current substring by comparing the frequencies of the characters
        //     -> An anagram is found (SUCCESS)

        if (substring_frequencies == target_frequencies) return true;

        // b) Adding the new character in the window to the character-frequencies map

        substring_frequencies[original[i] - 'a']++;

        // c) Removing the old character that fell out of the window from the character-frequencies map
        //     - Only if the current sub-string is of the same size as the target string

        if (i >= target_length) substring_frequencies[original[i - target_length] - 'a']--;
    }

    // Extra: Checking for a matching anagram in the final / last substring - The loop Terminates before the last check
    //     -> An anagram is found (SUCCESS)

    if (substring_frequencies == target_frequencies) return true;

    // Otherwise no anagrams were found (Would have terminated by now)

    return false;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: original = "eidbaooo", target = "ab"
    // Output: true
    cout << check_anagram("eidbaooo", "ab") << endl;

    // Input: original = "eidboaoo", target = "ab"
    // Output: false
    cout << check_anagram("eidboaoo", "ab") << endl;

    return 0;
}
