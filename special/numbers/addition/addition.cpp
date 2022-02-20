#include <iostream>
#include <string>

using namespace std;

string perform_addition(string num1, string num2, int base) {
    const int num1_length = num1.size();
    const int num2_length = num2.size();

    int overflow = 0;

    int pos1 = num1_length - 1;
    int pos2 = num2_length - 1;

    string result_num = "";

    int digit1, digit2, result_digit;
    int result;

    while (pos1 >= 0 || pos2 >= 0) {
        digit1 = pos1 >= 0 ? (num1[pos1--] - '0') : 0;
        digit2 = pos2 >= 0 ? (num2[pos2--] - '0') : 0;

        result = digit1 + digit2 + overflow;

        result_digit = result % base;
        overflow = result / base;

        result_num += to_string(result_digit);
    }

    if (overflow > 0) result_num += to_string(overflow);

    reverse(result_num.begin(), result_num.end());

    return result_num;
}

int main() {
    // Input: num1 = "1010", num2 = "1011", base = 2
    // Output: "10101"
    cout << perform_addition("1010", "1011", 2) << endl;

    // Input: num1 = "78", num2 = "59", base = 10
    // Output: "137"
    cout << perform_addition("78", "59", 10) << endl;

    return 0;
}

