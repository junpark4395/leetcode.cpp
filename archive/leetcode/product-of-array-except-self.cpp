/**
 * 238. Product of Array Except Self
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/product-of-array-except-self/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> answer(n);

        for (int l = 1; l < n; l++) {
            int r = n - l - 1;
            left[l] = left[l - 1] * nums[l - 1];
            right[r] = right[r + 1] * nums[r + 1];
        }

        for (int i = 0; i < n; i++) {
            answer[i] = left[i] * right[i];
        }

        return answer;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {1, 2, 3, 4};
        vector<int> output = sol.productExceptSelf(nums);
        println("Output: {}, Expected: [24, 12, 8, 6]", output);
    }

    // Example 2
    {
        vector<int> nums = {-1, 1, 0, -3, 3};
        vector<int> output = sol.productExceptSelf(nums);
        println("Output: {}, Expected: [0, 0, 9, 0, 0]", output);
    }

    return 0;
}
