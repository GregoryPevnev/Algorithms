// Reference: https://leetcode.com/problems/4sum/discuss/8609/My-solution-generalized-for-kSums-in-JAVA

#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Important: Only LOW is actually used - HIGH is just for reusability / extendability (Both COULD be moved)

// Note: Could be using Pairs - Would have to re-map each pair into a vector (Bad for performance)
vector<vector<int>> find_two_sums_for(vector<int>& nums, int low, int high, int target_sum) {
    vector<vector<int>> pairs; // Pairs of numbers that produce the correct sum
    int current_sum; // Sum of the current pair of numbers

    while(low < high) {
        current_sum = nums[low] + nums[high];

        // Case 1. Overflow -> Choosing a lower High-Number
        if (current_sum > target_sum) { high--; continue; }

        // Case 2. Underflow -> Choosing a higher Low-Number
        if (current_sum < target_sum) { low++; continue; }

        // Case 3. A pair that produces the exact sum is found

        // Step 1) Adding to the list of all pairs -> Going to the next Low and High numbers
        pairs.push_back(vector<int>{nums[low++], nums[high--]});

        // Step 2) Skipping duplicates to avoid creating duplicate pairs
        while(low < high && nums[low] == nums[low - 1]) low++;
        while(low < high && nums[high] == nums[high + 1]) high--;

        // SUPER-IMPORTANT: Moving BOTH pointers because the Target-Sum can ONLY be reached combining these TWO numbers
        //   If "Low + High = Target-Sum"
        //   Then "Low + Next-High != Target-Sum" (If "Next-High != High")
        //   Then "Next-Low + High != Target-Sum" (If "Next-Low != Low")
        //  => Skipping duplicates (To only return unique pairs)
    }

    return pairs;
}

vector<vector<int>> find_k_sums_for(vector<int>& nums, int low, int high, int target_sum, int k) {
    if (k == 2) return find_two_sums_for(nums, low, high, target_sum);

    vector<vector<int>> all_sums;

    // Iterating until exactly K-1 elements remain ahead (Enough for the next K-Sums step to take in)
    for (int i = low; i <= high - (k - 1); i++) {
        if (i > low && nums[i] == nums[i - 1]) continue; // Skipping duplicates

        vector<vector<int>> sums = find_k_sums_for(nums, i + 1, high, target_sum - nums[i], k - 1);

        for (vector<vector<int>>::iterator it = sums.begin(); it != sums.end(); it++) {
            it->push_back(nums[i]);

            all_sums.push_back(*it);
        }
    }

    return all_sums;
}

vector<vector<int>> find_k_sums(vector<int>& nums, int target_sum, int k) {
    sort(nums.begin(), nums.end());

    return find_k_sums_for(nums, 0, nums.size() - 1, target_sum, k);
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

void print_sums(vector<vector<int>> sums) {
    int counter;

    for (vector<vector<int>>::iterator sum_it = sums.begin(); sum_it != sums.end(); sum_it++) {
        cout << "[";

        counter = 0;

        for(vector<int>::iterator it = sum_it->begin(); it != sum_it->end(); it++) {
            if(counter++ != 0) cout << ", ";

            cout << * it;
        }

        cout << "]" << endl;
    }
}

int main() {
    // Input: nums = [1,0,-1,0,-2,2], sum = 0, k = 4
    // Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

    vector<int> v1{1, 0, -1, 0, -2, 2};
    print_sums(find_k_sums(v1, 0, 4));
}
