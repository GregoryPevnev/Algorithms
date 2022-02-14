// Reference: https://leetcode.com/problems/largest-number/
// General common solution which is much simpler

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Determines how a pair of two number should be ordered by comparing their combinations / concatenations
//   Numbers: Num1 and Num2 -> Combined / Concatenated
//   Combinations: "[Num1][Num2]" and "[Num2][Num1]" -> Compared
struct str_num_cmp {
    inline bool operator()(const string& num1, const string& num2) {
        const string c1 = num1 + num2; // Concatenated number with number 1 BEFORE number 2 -> Concatenated-number 1
        const string c2 = num2 + num1; // Concatenated number with number 2 BEFORE number 1 -> Concatenated-number 2

        // If Concatenated-number 1 is GREATER than Concatenated-number 2
        // Then number 1 should be ordered BEFORE number 2 -> TRUE (NO SWAPPING IS NEEDED)
        // Otherwise number 1 should be ordered AFTER number 2 -> FALSE (SWAPPING IS NEEDED)

        if (c1 > c2) return true;
        return false;
    }
};

string build_largest_number(vector<int>& nums) {
    // Step 1. Converting all numbers to strings in order to compare characters
    //   -> Character '9' is greater than character '1' due to their ASCII codes
    //   => ASCII codes of integers are ordered accordingly
    vector<string> num_strings;
    for (int const &num: nums) num_strings.push_back(to_string(num));

    // Step 2. Sorting number-strings based on their combinations
    //   a) "[Num1][Num2]" is larger than "[Num2][Num1]" -> Num1 should be BEFORE Num2
    //   a) "[Num2][Num1]" is larger than "[Num1][Num2]" -> Num2 should be BEFORE Num1
    sort(num_strings.begin(), num_strings.end(), str_num_cmp());

    // Step 3. Building a resulting string - Concatenating all the strings together
    string result = "";
    for(string const &num_string: num_strings) result.append(num_string);

    // Step 4. Getting rid of trailing zeroes
    int start;
    for(start = 0; start < result.size(); start++) {
        if (result[start] != '0') {
            return result.substr(start);
        }
    }

    // Edge-Case. If the string is empty -> Returning "0"
    return "0";
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: nums = [10, 2]
    // Output: "210"
    vector<int> nums1{10, 2};
    cout << build_largest_number(nums1) << endl;

    // Input: nums = [3, 30, 34, 5, 9]
    // Output: "9534330"
    vector<int> nums2{3, 30, 34, 5, 9};
    cout << build_largest_number(nums2) << endl;

    // Input: [432, 43243]
    // Output: "43243432"
    vector<int> nums3{432, 43243};
    cout << build_largest_number(nums3) << endl;

    // Input: [0, 0, ...]
    // Output: "0"
    vector<int> nums4{
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };
    cout << build_largest_number(nums4) << endl;
}

