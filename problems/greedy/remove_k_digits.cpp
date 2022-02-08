// Reference: https://leetcode.com/problems/remove-k-digits/

#include <iostream>
#include <stack>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Fact 1: The smallest integer with digits [x, y, z, ...] is the one where they form an increasing order (ASCENDING)
//    Proof: The smallest integer that can be formed from "91753" is "13579"
//    Outcome: 1. The smallest integer that can be formed from digits [x, y, z, ...] is the one that has NO PEAKS
//             2. An integer can be minimized by removing a certain number of PEAKS
// Fact 2: Leading digits have more priority that trailing digits
//    Proof: When only 1 digit can be removed to minimize number "15487", it's the best to remove "5" (The first peak)
//    Outcome: Peaks should be removed from the beginning - Means that iteration should be done from the beginning
//    Additional: When removing a certain number of leading digits, there could be leading "0" (Can be discarded)
// Solution: The best way to minimize an integer with K deletions is by
//    1. Removing K PEAKS from the BEGINNING (Higher priority)
//    2. If the number of PEAKS is less than K, then the remaining digits should be removed from the end
//        - Since the absence of PEAKS means that all the digits form an INCREASING / ASCENDING order
//        -> Removing "K-[Number-of-peaks]" digits from the end means removing the largest digits
// Complexity:
//    Time: O(n) - Each digit is only inspected once (Iterating over the entire integer)
//    Space: O(n) - Each digit is stored in the stack at worst (Before getting popped in the end)

string remove_k_digits(const string& num, int k) {
    // Step 0. Initializing a DS for keeping track of the latest digits
    // DS: Monotonic stack of the latest digits -> Should be forming an increasing / ascending order of digits
    //   -> Stops being monotonic when digits can no longer be removed (K was already removed)
    //   => Eventually contains [N-K] most optimal digits for the smallest number in the reverse order
    //      (When all optimizations are complete, the properties of the stack do not matter)
    stack<char> digits;

    // Step 2. Iterating over each digit in the original integer and removing K PEAKS (If possible / If present)
    for (char const &digit : num) {
        // Optimizing the integer by getting rid of items in the running Monotonic-Stack of Digits when
        //  1) It is possible to keep removing digits (K > 0)
        //  2) The latest digit is a PEAK due to being
        //      a) Larger than the prior item in the Monotonic-Stack of digits)
        //      b) Larger than the current item
        //  -> Removing the PEAK and decrementing the number of digits that can be removed
        while (k > 0 && !digits.empty() && digits.top() > digit) {
            k--;

            digits.pop();
        }

        // Pushing the current digit to the Stack, which implies either
        //  1) It is still possible to keep removing digits from the integer -> The stack is still Monotonic
        //  2) All possible digits were already removed -> The stack has no properties (Just digits in reverse order)
        digits.push(digit);
    }

    // Step 3. Removing K` remaining largest digits (If there was less than K PEAKS in the original integer)
    // If it is still possible to remove K` digits from the integer, then the largest one should be removed
    //    -> Removing K` digits from the end of the Stack (They are in increasing / ascending order)
    //    - Due to the fact if K>=0 then the Stack is STILL Monotonic (Has the largest digits on the front)
    while (k > 0) {
        k--;

        digits.pop();
    }

    // Step 4. Building a resulting string from the Stack -> Reversing to get the correct order of digits
    string result;
    while(!digits.empty()) {
        // IMPORTANT: "to_string" does NOT work with "char" (Treats it like an integer)
        result.append(string(1, digits.top()));

        digits.pop();
    }
    reverse(result.begin(), result.end());

    // Step 5. Getting rid of Leading-Zeroes
    for (int i = 0; i < result.size(); i++) {
        if (result[i] != '0') {
            return result.substr(i);
        }
    }

    // Edge-Case. If the entire number is just Zeroes then a "0" should be returned
    return "0";
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: num = "1432219", k = 3
    // Output: "1219"
    cout << remove_k_digits("1432219", 3) << endl;

    // Input: num = "10200", k = 1
    // Output: "200"
    cout << remove_k_digits("10200", 1) << endl;

    // Input: num = "10", k = 2
    // Output: "0"
    cout << remove_k_digits("10", 2) << endl;

    return 0;
}
