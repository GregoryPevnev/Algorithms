// Reference: https://leetcode.com/problems/largest-number/
// Custom solution which is interesting but is hard to implement

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

struct str_num_cmp {
private:
    bool is_long_greater(const string& long_num, const string& short_num, bool default_result) {
        const int long_length = long_num.size();
        const int short_length = short_num.size();

        int long_i = 0, short_i = 0;

        while (long_i < long_length) {
            if (long_num[long_i] != short_num[short_i]) return long_num[long_i] > short_num[short_i];

            long_i++;
            short_i = (short_i + 1) % short_length;
        }

        long_i = 0;
        while(short_i < short_length) {
            if (long_num[long_i] != short_num[short_i]) return long_num[long_i] > short_num[short_i];

            long_i++;
            short_i++;
        }

        return default_result;
    }
public:
    inline bool operator()(const string& num1, const string& num2) {
        if (num1.size() == num2.size()) return greater<string>()(num1, num2);
        if (num1.size() >= num2.size()) return is_long_greater(num1, num2, true);
        return !is_long_greater(num2, num1, false);
    }
};

string build_largest_number(vector<int>& nums) {
    vector<string> num_strings;

    for (int const &num: nums) num_strings.push_back(to_string(num));

    sort(num_strings.begin(), num_strings.end(), str_num_cmp());

    string result = "";
    for(string const &num_string: num_strings) result.append(num_string);

    int start;
    for(start = 0; start < result.size(); start++) {
        if (result[start] != '0') {
            return result.substr(start);
        }
    }

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

