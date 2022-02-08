// Reference: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
// Guide: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/discuss/1747029/Python-Explanation-with-pictures-min-heap
// Tags: Greedy, Sequence, Priority-Queue, Prefix-Sum and Suffix-Sum

// Complexity: O(NlogN), where N is the Size of the Third
//    1) O(2Nlog2N) - Possibly adding each item from the 1st and 2nd Thirds to the Max-Heap
//          + Checking / Computing Sums for Min-Prefix-Sums
//    2) O(2Nlog2N) - Possibly adding each item from the 3rd and 2nd Thirds to the Min-Heap
//          + Checking / Computing Sums for Max-Suffix-Sums
//    3) O(N+1) - Finding the smallest difference between

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// TODO: Detailed documentation + Diagrams

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// For an array of values which can be divided into 3 parts / Thirds such as [x, x, y, y, z, z]
//    Size of the Third: N = 2
//    Size of a Prefix-Sums / Suffix-Sums: N + 1 = 3
// 1) Building Prefix-Sums with the Minimum possible sums using values from the 1st and 2nd Thirds
//    Candidates: [MIN(N, [x, x]), MIN(N, [x, x, y]), MIN(N, [x, x, y, y])] -> N + 1
// 2) Building Suffix-Sums with the Maximum possible sums using values from the 1st and 2nd Thirds
//    Candidates: [MAX(N, [y, y, z, z]), MIN(N, [y, z, z]), MIN(N, [z, z])] -> N + 1
// 3) Finding the smallest difference result from the corresponding Pairs - HAVE NO OVERLAP
//        i) [x, x] has no overlap with [y, y, z, z]
//        ii) [x, x, y1] has no overlap with [y2, z, z]
//     - No matter which items were chosen for which Halves
//     -> Choosing MIN for the First-Half and choosing MAX for the Second-Half
// Important: CANNOT SORT THE HALVES AS (1st and 2nd) and (2nd and 3rd) - Losing order and cannot rely on sequences

// Pattern: When maintaining a running Subset of values using a Heap
//   1) Using Max-Heap for a subset of K Smallest -> Pointing to the Largest-Smallest => Checking if it can be replaced
//   2) Using Min-Heap for a subset of K Largest -> Pointing to the Smallest-Largest => Checking if it can be replaced

long long min_difference(vector<int>& nums) {
    // Step 0. Initializing sizes of Thirds / Prefix and Suffix Sums / etc.

    const int total_nums = nums.size();
    const int n = total_nums / 3; // Size of a Third

    // Number of sums of Prefixes and Suffixes is greater than a Third by 1 -> Includes cases where
    //     1) No values in the 2nd-Third are included into the 1st-Third => +1
    //     2) No values in the 2nd-Third are included into the 3rd-Third => +1
    //     3) Middle-Third is sub-divided into the Left and Right Thirds (Same for both) => -1
    const int sums_size = n + 1;

    // Step 1. Building Prefix-Sums / Left-Sums -> Minimum / Should include the smallest

    // All Minimum Prefix-Sums for the Left-Half (From 1st and 2nd Thirds)
    //    First: Only the 1st-Third
    //    Intermediate: 1st-Third + Partially 2nd-Third
    //    Last: 1st-Third + 2nd-Third
    vector<long long> prefix_sums(sums_size);
    int prefix_sums_head = 0;

    // Keeping the current MINIMAL Prefix-Sum for each position - Starting from just the Sum of 1st-Third
    //    -> Keeping a Max-Heap to check whether a subsequent item can replace the current Largest item (Smaller than)
    long long prefix_sum = 0;
    priority_queue<int, vector<int>, less<int>> prefix_max_heap;

    // 1st-Third: Initializing the Prefix-Sum and Populating the Max-Heap with the items of the Prefix-Sum
    for (int i = 0; i < n; i++) {
        prefix_sum += nums[i];
        prefix_max_heap.push(nums[i]);
    }

    // The first Prefix-Sum: Just the sum of the 1st-Third - NOT including any items from teh Second-Third
    prefix_sums[prefix_sums_head++] = prefix_sum;

    // 2nd-Third: For each item in the Third
    for (int i = n; i < n * 2; i++) {
        // a) Adding to the subset of the smallest items (Size of the Third) - If less than the current Largest-Smallest
        //      -> Recalculating the current minimum Prefix-Sum
        if (nums[i] < prefix_max_heap.top()) {
            prefix_sum -= prefix_max_heap.top();
            prefix_max_heap.pop();

            prefix_sum += nums[i];
            prefix_max_heap.push(nums[i]);
        }

        // b) Setting the smallest Prefix-Sum for the current position
        //      - Includes N smallest items so far in the Left-Half
        //      -> With the POSSIBLE inclusion of the current Second-Third item
        prefix_sums[prefix_sums_head++] = prefix_sum;
    }

    // Step 2. Building Suffix-Sums / Right-Sums -> Maximum / Should include the greatest

    // Same logic as for prefix but in reverse
    //    a) The first Maximum Suffix-Sum is just for the Third-Third
    //    b) Adding items from the Second-Third to maximize the Suffix-Sum in the reverse order to respect positions

    vector<long long> suffix_sums(sums_size);
    int suffix_sums_head = sums_size - 1;

    long long suffix_sum = 0;
    priority_queue<int, vector<int>, greater<int>> suffix_min_pq;

    for (int i = n * 3 - 1; i >= n * 2; i--) {
        suffix_sum += nums[i];
        suffix_min_pq.push(nums[i]);
    }

    suffix_sums[suffix_sums_head--] = suffix_sum;

    for (int i = n * 2 - 1; i >= n; i--) {
        if (nums[i] > suffix_min_pq.top()) {
            suffix_sum -= suffix_min_pq.top();
            suffix_min_pq.pop();

            suffix_sum += nums[i];
            suffix_min_pq.push(nums[i]);
        }

        suffix_sums[suffix_sums_head--] = suffix_sum;
    }

    // Step 3. Calculating the smallest combination of Prefix-Min-Sum to Suffix-Max-Sum
    //   - Finding differences between the corresponding pairs (NO OVERLAP / SAFE)
    //   -> Returning the smallest / minimum difference

    long long min_diff = INT64_MAX;

    for (int i = 0; i < sums_size; i++) {
        min_diff = min(min_diff, prefix_sums[i] - suffix_sums[i]);
    }

    return min_diff;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: nums = [7,9,5,8,1,3]
    // Output: 1
    vector<int> nums{7, 9, 5, 8, 1, 3};
    cout << min_difference(nums) << endl;

    return 0;
}
