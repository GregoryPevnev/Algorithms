#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long> sorted_squares(vector<long>& nums) {
    const int total_nums = nums.size();

    int min_pointer = 0;
    int max_pointer = total_nums - 1;

    vector<long> squares(total_nums);
    int squares_pointer = total_nums - 1;

    while (min_pointer <= max_pointer) {
        if (abs(nums[min_pointer]) > abs(nums[max_pointer])) {
            squares[squares_pointer--] = (int) pow(nums[min_pointer++], 2);
        } else {
            squares[squares_pointer--] = (int) pow(nums[max_pointer--], 2);
        }
    }

    return squares;
}

void print_squares(vector<long>& nums) {
    cout << "[";
    for (int const &num : nums) {
        cout << " " << num << " ";
    }
    cout << "]" << endl;
}

int main() {
    // Input: nums = [-4,-1,0,3,10]
    // Output: [0,1,9,16,100]
    vector<long> nums1{-4, -1, 0, 3, 10};
    vector<long> squares1 = sorted_squares(nums1);
    print_squares(squares1);

    // Input: nums = [-7,-3,2,3,11]
    // Output: [4,9,9,49,121]
    vector<long> nums2{-7, -3, 2, 3, 11};
    vector<long> squares2 = sorted_squares(nums2);
    print_squares(squares2);

    return 0;
}
