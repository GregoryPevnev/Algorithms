#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Important: Keeping a running subset which gets built during the runtime (Saving space by only keeping a single one)
//      -> Adding a new element before proceeding to generate further subsets + Removing when going back
//      => Copying and adding to the set of all the results

void build_subsets_for(vector<int>& nums, int idx, vector<int>& current_subset, vector<vector<int>>& result_subsets) {
    // The current subset was built completely -> Adding to all the results
    if (idx >= nums.size()) {
        // Important: Copying to allow the running-subset to continue being used
        vector<int> subset(current_subset);

        result_subsets.push_back(subset);

        return;
    }

    // Case 1. Including the current number into the running subset

    // a) Adding the current number
    current_subset.push_back(nums[idx]);

    // b) Building all the further subsets
    build_subsets_for(nums, idx + 1, current_subset, result_subsets);

    // c) Removing the current number - Prevents from being used when going back
    current_subset.pop_back();

    // Case 2. NOT including the current number into the running subset

    build_subsets_for(nums, idx + 1, current_subset, result_subsets);
}

vector<vector<int>> build_subsets(vector<int>& nums) {
    vector<vector<int>> result_subsets;
    vector<int> current_subset;

    build_subsets_for(nums, 0, current_subset, result_subsets);

    return result_subsets;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

void print_subsets(vector<vector<int>>& subsets) {
    cout << "[ ";
    for (vector<int> const &subset : subsets) {
        cout << "[";
        for (int const &num : subset) {
            cout << " " << num << " ";
        }
        cout << "] ";
    }
    cout << "]";
}

int main() {
    // Input: nums = [1,2,3]
    // Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

    vector<int> nums{1, 2, 3};

    vector<vector<int>> subsets = build_subsets(nums);

    print_subsets(subsets);

    return 0;
}
