// Reference: https://leetcode.com/problems/relative-sort-array/
// Tags: Greedy, Set, Numerical, Counting-Sort
// Complexity:
//  Time: O(N) - Using Counting-Sort as a Subroutine
//  Space: O(1) - Just the frequencies (Static size of the Array)

#include <iostream>
#include <vector>

// Range: Bounded and limited
#define MIN_VALUE 0
#define MAX_VALUE 1000

using namespace std;

void relative_sort(vector<int>& array1, vector<int>& array2) {
    // Step 1. Counting the frequencies of each number in the first array

    vector<int> freq(MAX_VALUE + 1, 0);
    for (int const &num : array1) freq[num]++;

    // Step 2. Re-Populating the first array using the frequencies - Relies on the Counting-Sort

    // a) Ordering the items in the second array prior to the actual sorting
    //   - Giving them the priority and flushing all occurrences

    int copy_pointer = 0;

    int num_freq;

    for (int const &num : array2) {
        num_freq = freq[num];

        while (num_freq--) {
            array1[copy_pointer++] = num;
        }

        // Important: Preventing numbers in array 2 from being copied multiple times
        freq[num] = 0;
    }

    // b) Filling out the remaining numbers in ascending order, like in a regular Counting-Sort

    for (int num = MIN_VALUE; num <= MAX_VALUE; num++) {
        num_freq = freq[num];

        while (num_freq--) {
            array1[copy_pointer++] = num;
        }
    }
}

void print_array(vector<int>& array) {
    cout << "[";
    for (int const &item : array) cout << " " << item << " ";
    cout << "]" << endl;
}

int main() {
    // Input: array1 = [2,3,1,3,2,4,6,7,9,2,19], array2 = [2,1,4,3,9,6]
    // Output: [2,2,2,1,4,3,3,9,6,7,19]

    vector<int> array1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};

    vector<int> array2{2, 1, 4, 3, 9, 6};

    relative_sort(array1, array2);

    print_array(array1);

    return 0;
}
