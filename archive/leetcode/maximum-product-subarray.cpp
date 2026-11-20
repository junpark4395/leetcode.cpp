/**
 * 152. Maximum Product Subarray
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-product-subarray/description/
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
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();
        int dp[20001][2] = {};
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int answer = nums[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = min(min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]), nums[i]);
            dp[i][1] = max(max(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]), nums[i]);

            answer = max(answer, dp[i][1]);
        }

        return answer;
    }
};

int main() {
    Solution sol;

    {
        vector<int> nums = {-2 ,3, -4};
        int output = sol.maxProduct(nums);
        println("Output: {}, Expected: 24", output);
    }

    // Example 1
    {
        vector<int> nums = {2, 3, -2, 4};
        int output = sol.maxProduct(nums);
        println("Output: {}, Expected: 6", output);
    }

    // Example 2
    {
        vector<int> nums = {-2, 0, -1};
        int output = sol.maxProduct(nums);
        println("Output: {}, Expected: 0", output);
    }

    return 0;
}
