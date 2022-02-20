#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Approach:
//   1. Reversing the entire string to have positions reversed
//   2. Reversing the individual words to have them un-reversed / original
//   3. Moving the words in a way to have no unnecessary whitespace

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

string reverse_string_words_order(string str) {
    const int length = str.size();

    // Stage 1. Reversing the entire string to have the words change their places

    reverse_string(str, 0, length - 1);

    // Stage 2. Un-Reversing the individual words and moving them to the beginning

    int start_pointer = 0, end_pointer; // Pointers to the start and end of a specific word
    int copy_pointer = 0; // Pointer for copying the individual words after un-reversing

    while (start_pointer < length) {
        // Step 1. Finding the start of a new word
        while (start_pointer < length && str[start_pointer] == ' ') start_pointer++;

        // Edge-Case: Terminating if a new word is NOT found
        if (start_pointer >= length) break;

        // Step 2. Finding the end of the new word
        end_pointer = start_pointer;
        while (end_pointer < length && str[end_pointer] != ' ') end_pointer++;

        // Step 3. Un-Reversing the word
        reverse_string(str, start_pointer, end_pointer - 1);

        // Step 4. Adding necessary whitespace and copying the word into the beginning
        if (copy_pointer > 0) str[copy_pointer++] = ' ';
        while (start_pointer < end_pointer) str[copy_pointer++] = str[start_pointer++];
    }

    // Stage 3. Removing all the remaining unnecessary characters

    int leftovers = length - copy_pointer;

    if (leftovers > 0) {
        string::iterator last_position = str.end();
        advance(last_position, -1 * leftovers);

        str.erase(last_position, str.end());
    }

    // Result: Returning the string

    return str;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    string str = "   the   sky  is blue   ";

    cout << reverse_string_words_order(str) << endl;

    return 0;
}

