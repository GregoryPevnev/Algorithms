// Reference: https://leetcode.com/problems/remove-duplicate-letters/

#include <iostream>
#include <unordered_map>
#include <stack>

#define ALPHABET_SIZE 26

using namespace std;

// Optimizations:
//    1. Maps: Using Arrays for Tables / Mapping -> Constant Time and Space (MUCH MORE EFFICIENT)
//         => Should always be used when the range of values is bounded
//    2. Sets: The most efficient way to implement sets is via Bit-Map -> Constant-Time access and extremely small size
//         => Should always be used when the range of values can be stored in 4-8 bytes (UNSIGNED int / long)
//    3. Character: Using values directly by subtracting initial-character of the range (When available)
//          a) Digits-Only -> Subtracting '0'
//          b) Lowercase-Only -> Subtracting 'a'
//          c) Uppercase-Only -> Subtracting 'A'
//         => Should always be used when the range of characters is given

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

string remove_duplicate_letters(string str) {
    const int str_length = str.size();

    int characters_count[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) characters_count[i] = 0;

    unsigned int visited_bitmap = 0; // 32-bits -> Enough to provide for

    for (int i = 0; i < str_length; i++) characters_count[str[i] - 'a']++;

    // NOT CHARACTERS (Simply a value between 0 and 25) -> 1 byte is enough
    stack<char> chars;
    char char_value;

    for (int i = 0; i < str_length; i++) {
        char_value = str[i] - 'a';

        if ((visited_bitmap & (1 << char_value))) {
            characters_count[char_value]--;

            continue;
        }

        while (!chars.empty() && characters_count[chars.top()] > 1 && chars.top() >= char_value) {
            characters_count[chars.top()]--;
            visited_bitmap ^= (1 << chars.top());

            chars.pop();
        }

        chars.push(char_value);
        visited_bitmap |= (1 << char_value);
    }

    string result;

    while (!chars.empty()) {
        result.append(string(1, chars.top() + 'a'));

        chars.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: "bcabc"
    // Output: "abc"
    cout << remove_duplicate_letters("bcabc") << endl;

    // Input: "cbacdcbc"
    // Output: "acdb"
    cout << remove_duplicate_letters("cbacdcbc") << endl;

    // Input: "abacb"
    // Output: "abc"
    cout << remove_duplicate_letters("abacb") << endl;

    // Input: "bbcaac"
    // Output: "bac"
    cout << remove_duplicate_letters("bbcaac") << endl;

    return 0;
}