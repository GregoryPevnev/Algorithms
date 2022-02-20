#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Utility: Reversing contents of a string between specific positions
void reverse_string(string& s, int start_pos = -1, int end_pos = -1) {
    int start = start_pos == -1 ? 0 : start_pos;
    int end = end_pos == -1 ? s.size() - 1 : end_pos;

    char tmp;

    while (start < end) {
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;

        start++;
        end--;
    }
}

string reverse_string_words(string str) {
    const int length = str.size();

    // Initialing the Two-Pointer for performing swaps on words individually
    int start = 0;
    int end = 1;

    // Temporary character for performing swaps
    char tmp;

    // Reversing the words one by one
    while (end < length) {
        // Step 1. Finding the end of the current word
        while (end < length && str[end] != ' ') end++;

        // Step 2. Reversing the word within the string specified by the starting and ending positions
        reverse_string(str, start, --end);

        // Step 3. Repositioning the pointers
        start = end + 2; // Skipping the current character and the space ahead
        end = start + 1; // Setting the end to the character afterwards
    }

    return str;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    string str = "Let's take a contest";

    cout << reverse_string_words(str) << endl;

    return 0;
}