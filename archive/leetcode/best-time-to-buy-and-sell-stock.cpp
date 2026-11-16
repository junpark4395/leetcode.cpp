/**
 * 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;

        for (size_t i = 0; i < prices.size(); i++) {
            int price = prices[i];

            if (minPrice > price) {
                minPrice = price;
                continue;
            }

            profit = max(profit, price - minPrice);
        }

        return profit;
    }
};

int main() {
    Solution sol;

    {
        vector<int> prices = {2, 1, 2, 0, 1};
        int output = sol.maxProfit(prices);
        println("Output: {}, Expected: 1", output);
    }

    {
        vector<int> prices = {2, 4, 1};
        int output = sol.maxProfit(prices);
        println("Output: {}, Expected: 2", output);
    }

    // Example 1
    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        int output = sol.maxProfit(prices);
        println("Output: {}, Expected: 5", output);
    }

    // Example 2
    {
        vector<int> prices = {7, 6, 4, 3, 1};
        int output = sol.maxProfit(prices);
        println("Output: {}, Expected: 0", output);
    }

    return 0;
}
