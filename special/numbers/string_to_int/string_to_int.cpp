// Reference and Guide: https://leetcode.com/problems/string-to-integer-atoi/

#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

const int PRE_MAX = INT_MAX / 10;
const int LAST_MAX_DIGIT = INT_MAX % 10;

int string_to_int(string s) {
    int result = 0;
    bool is_negative = false;

    int position = 0;

    while (s[position] == ' ') position++;

    if (s[position] == '-') {
        is_negative = true;
        position++;
    } else if (s[position] == '+') {
        position++;
    }

    int digit;

    while (s[position] >= '0' && s[position] <= '9') {
        digit = s[position] - '0';

        // Overflow checking:
        // Case 1. The current result is going to overflow with the next digit, no matter what is added
        //     - Happens when the pre-last digit is greater than the pre-last digit of INT-MAX
        //     -> The very last digit is always going to cause overflow (Even if it is 0)
        //     => STRICTLY GREATER / STRICTLY OVERFLOWS (ACTUAL TERMINATION CASE)
        // Case 2. The current result could either be greater, equal or less than the INT-MAX
        //     - Happens when all the digits EXCEPT the last one are the same
        //     -> Comparing the current digit of the number to the last digit of INT-MAX
        //     => a) Current-Digit is Greater = Overflow (ACTUAL TERMINATION CASE)
        //        b) Current-Digit is Equal = No Overflow (For now)
        //        c) Current-Digit is Less = No Overflow (For now)
        // The rest - Safe (For the current result / digit / position)
        if (
            result > PRE_MAX ||
            (result == PRE_MAX && digit > LAST_MAX_DIGIT)
        ) {
            return is_negative ? INT_MIN : INT_MAX;
        }

        result = result * 10 + digit;

        position++;
    }

    return is_negative ? result * -1 : result;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    cout << string_to_int("-4555") << endl;

    cout << string_to_int("20000000000000000") << endl;

    return 0;
}
