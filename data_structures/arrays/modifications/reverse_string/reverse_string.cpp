#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Ordinary String-Reversal Algorithm with optional positions

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

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    string str = "abc";

    reverse_string(str);

    cout << str << endl;

    return 0;
}
