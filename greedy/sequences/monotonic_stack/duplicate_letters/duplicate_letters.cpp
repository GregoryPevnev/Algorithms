// Reference: https://leetcode.com/problems/remove-duplicate-letters/

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

string remove_duplicate_letters(string str) {
    const int str_length = str.size();

    unordered_map<char, int> counts; // Map (Character -> Count)
    unordered_map<char, bool> visited; // Set (Character -> Whether visited or not)

    for (char const &ch : str) {
        counts[ch]++;
        visited[ch] = false;
    }

    stack<char> chars;

    for (int i = 0; i < str_length; i++) {
        if (visited[str[i]]) {
            counts[str[i]]--;

            continue;
        }

        while (!chars.empty() && counts[chars.top()] > 1 && chars.top() >= str[i]) {
            counts[chars.top()]--;
            visited[chars.top()] = false;

            chars.pop();
        }

        chars.push(str[i]);
        visited[str[i]] = true;
    }

    string result;

    while (!chars.empty()) {
        result.append(string(1, chars.top()));

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