// Reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
// Guide: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/208241/Explanation-for-the-dummy-like-me.
// Tags: Greedy, Two Pointers, Running Values

#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// The profit is made by buying and selling stocks in Ranges
// Range: Combination of specific Buying-Price and Selling-Price, where "Buying-Price < Selling-Price"
//   - Can have CONTINUOUS increasing / decreasing Prices (Should be iterated until the price is perfect)
// Buying Price: Finding the smallest price in a sequence - Smallest in the continuous decreasing sequence
//   -> Stopping when the prices stop decreasing
// Selling Price: Finding the largest price in a sequence - Largest in the continuous increasing sequence
//   -> Stopping when the prices stop increasing

int max_profit(vector<int>& prices) {
    // Initializing the total prices
    const int total_prices = prices.size();

    // Initializing the profit to be none by default
    int profit = 0;

    // Initializing the first buying-price to be the first once
    //   -> Selling price is set after the buying price anyway
    int buy = 0, sell;

    // While it is possible to buy / sell stocks
    while (buy < total_prices - 1) {
        // Finding the smallest continuously decreasing price -> The most optimal for buying in the range
        while(buy < total_prices - 1 && prices[buy] >= prices[buy + 1]) buy++;

        // Finding the largest continuously increasing price -> The most optimal for selling in the range
        //    - After the buying price
        sell = buy + 1;
        while(sell < total_prices - 1 && prices[sell] <= prices[sell + 1]) sell++;

        // In case the selling price was actually found (Did not go out of bounds)
        if (sell < total_prices) {
            // Buying and Selling -> Adding to the profit
            profit += prices[sell] - prices[buy];

            // Initializing the next Range (Knowing that the price after the Selling-Price is definitely smaller)
            buy = sell + 1;
        }
    }

    // Returning all the resulting profit
    return profit;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [7,1,5,3,6,4]
    // Output: 7
    vector<int> prices1{7, 1, 5, 3, 6, 4};
    cout << max_profit(prices1) << endl;

    // Input: [1,2,3,4,5]
    // Output: 4
    vector<int> prices2{1, 2, 3, 4, 5};
    cout << max_profit(prices2) << endl;

    // Input: [7,6,4,3,1]
    // Output: 0
    vector<int> prices3{7, 6, 4, 3, 1};
    cout << max_profit(prices3) << endl;

    // Input: [1,2]
    // Output: 1
    vector<int> prices4{1, 2};
    cout << max_profit(prices4) << endl;

    return 0;
}
