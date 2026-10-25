/**
 * 198. House Robber
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/house-robber/description/
 */

 /*
A Simple version
int prev2 = 0; // i - 2
int prev1 = 0; // i - 1
for (int num : nums) {
    int cur = max(prev1, prev2 + num);
    prev2 = prev1;
    prev1 = cur;
}
return prev1;
*/

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

int cache[101];

class Solution {
public:
    int rob(vector<int>& nums) {
        cache[0] = nums[0];
        if (nums.size() > 1) {
            cache[1] = max(nums[0], nums[1]);
        }

        for (size_t i = 2; i < nums.size(); i++) {
            cache[i] = max(cache[i-1], cache[i-2] + nums[i]);
        }

        return cache[nums.size() - 1];
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {1, 2, 3, 1};
        int output = sol.rob(nums);
        println("Output: {}, Expected: 4", output);
    }

    // Example 2
    {
        vector<int> nums = {2, 7, 9, 3, 1};
        int output = sol.rob(nums);
        println("Output: {}, Expected: 12", output);
    }

    return 0;
}
