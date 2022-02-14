// Reference: https://leetcode.com/problems/reorganize-string/

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
        if (char_freq1.second == char_freq2.second) return char_freq1.first < char_freq2.first;

        return char_freq1.second < char_freq2.second;
    }
};

// MAX-HEAP: Character-Frequencies -> Top points to the character with the highest frequency
typedef priority_queue<char_freq, vector<char_freq>, char_freq_cmp> char_freq_pq;

// Utility: Building a Character-Frequency structure
char_freq make_char_freq(int char_code, int freq) {
    return char_freq(string(1, (char) (char_code + 'a')), freq);
}

string rearrange_string(string str) {
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

    // Step 3. Taking 2 characters with the highest frequencies and interposing them

    char_freq ch1, ch2;
    string result = "";

    while(pq.top().second > 1 && pq.size() > 1) {
        // a) Taking the TOP 2 characters with the highest-frequencies
        ch1 = pq.top(); pq.pop(); // Highest Frequency
        ch2 = pq.top(); pq.pop(); // Same Frequency / Lower Frequency

        // b) Interposing into the string (Largest one first - Could be on ahead)
        result.append(ch1.first);
        result.append(ch2.first);

        // c) Putting back (If there are occurrences left for the character)
        if (--ch1.second > 0) pq.push(ch1);
        if (--ch2.second > 0) pq.push(ch2);
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
    // Input: "abbabbaaab"
    // Output: "ababababab"
    cout << rearrange_string("abbabbaaab") << endl;

    // Input: "aabbcc"
    // Output: "abacbc"
    cout << rearrange_string("abacbc") << endl;

    return 0;
}
