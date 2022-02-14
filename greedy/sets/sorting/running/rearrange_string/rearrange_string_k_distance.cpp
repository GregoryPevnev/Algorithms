// Reference: https://leetcode.com/problems/reorganize-string/
// Guide: https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleHard/358.html

#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define ALPHABET_SIZE 26

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// String can be safely rearranged if we are constantly interposing the most frequent characters
//    High-Frequency: Need to be interposed with as many characters as possible (The most dangerous)
//    Low-Frequency: Needed for interposing or can just be left until the end (Single occurrence)
// Important: Only interposing one character at a time - Otherwise breaks when there are the same frequencies
//  Ex 1. "AABBCC" -> "ABABCC" (Interposed by 2) => FAILURE
//  Ex 2. "AABBCC" -> "ABCACB" (Interposed by 1) => SUCCESS

// Character-Frequency: Representing a Character (1) and its Frequency (2)
typedef pair<string, int> char_freq;

// Comparing Character-Frequencies -> Having the Character with the HIGHEST FREQUENCY on TOP of the Heap / PQ
//   -> Additionally comparing letters for stable-ordering (Same order no matter what)
struct char_freq_cmp {
    bool operator()(const char_freq& char_freq1, const char_freq& char_freq2) {
        if (char_freq1.second == char_freq2.second) return char_freq1.first > char_freq2.first;

        return char_freq1.second < char_freq2.second;
    }
};

// MAX-HEAP: Character-Frequencies -> Top points to the character with the highest frequency
typedef priority_queue<char_freq, vector<char_freq>, char_freq_cmp> char_freq_pq;

// Utility: Building a Character-Frequency structure
char_freq make_char_freq(int char_code, int freq) {
    return char_freq(string(1, (char) (char_code + 'a')), freq);
}

string rearrange_string_k_distance(string str, int distance) {
    // Step 1. Counting frequencies

    vector<int> character_frequencies(ALPHABET_SIZE, 0);
    for (char const &ch : str) character_frequencies[ch - 'a']++;

    // Step 2. Arranging Character-Frequencies in a Max-Heap -> Top is pointing at characters with highest frequencies

    char_freq_pq pq;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (character_frequencies[i] > 0) {
            pq.push(make_char_freq(i, character_frequencies[i]));
        }
    }

    // Step 3. Taking K characters with the highest frequencies and interposing them

    vector<char_freq> interval(distance);
    int interval_counter;
    string result = "";

    while(pq.top().second > 1 && pq.size() >= distance) {
        interval_counter = 0;

        while (!pq.empty() && interval_counter < distance) {
            result.append(pq.top().first);

            interval[interval_counter++] = pq.top();

            pq.pop();
        }

        while (interval_counter-- > 0) {
            if (--interval[interval_counter].second > 0) {
                pq.push(interval[interval_counter]);
            }
        }
    }

    // Step 4. Checking if there are still a character left with remaining occurrences -> IMPOSSIBLE

    if (!pq.empty() && pq.top().second > 1) return ""; // Cannot build a string with repeating characters

    // Step 5. Arranging the remaining characters with a single occurrence in any order (Does not matter)
    //    -> Returning the rearranged string

    while(!pq.empty()) {
        result.append(pq.top().first);

        pq.pop();
    }

    return result;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: str = "aabbcc", k = 3
    // Output: "abcabc"
     cout << rearrange_string_k_distance("aabbcc", 3) << endl;

    // Input: str = "aaabc", k = 3
    // Output: ""
     cout << rearrange_string_k_distance("aaabc", 3) << endl;

    // Input: str = "aaadbbcc", k = 2
    // Output: "abacabcd" or "abcabcda"
     cout << rearrange_string_k_distance("aaadbbcc", 2) << endl;

    return 0;
}
