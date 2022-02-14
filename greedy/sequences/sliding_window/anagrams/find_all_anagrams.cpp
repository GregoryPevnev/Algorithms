// Reference: https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <string>
#include <vector>

#define ALPHABET_SIZE 26

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Refer to the simple solution for a better explanation

vector<int> find_anagrams(string original, string target) {
    const int original_length = original.size();
    const int target_length = target.size();

    vector<int> target_frequencies(ALPHABET_SIZE, 0);
    for (char const &ch : target) target_frequencies[ch - 'a']++;

    vector<int> substring_frequencies(ALPHABET_SIZE, 0);

    int matching_length = 0;

    char current_char_code, prev_char_code;

    vector<int> matching_substrings;

    for (int i = 0; i < original_length; i++) {
        // Checking for a matching anagram in the current substring

        if (matching_length == target_length) {
            matching_substrings.push_back(i - target_length);
        }

        // Phase 1. INC

        current_char_code = original[i] - 'a';

        if (++substring_frequencies[current_char_code] <= target_frequencies[current_char_code]) matching_length++;

        // Phase 2. DEC (Optional)

        if (i < target_length) continue; // Only checking if the current substring is full

        prev_char_code = original[i - target_length] - 'a';

        if (--substring_frequencies[prev_char_code] < target_frequencies[prev_char_code]) matching_length--;
    }

    // Checking for a matching anagram in the final / last substring
    if (matching_length == target_length) {
        matching_substrings.push_back(original_length - target_length);
    }

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
