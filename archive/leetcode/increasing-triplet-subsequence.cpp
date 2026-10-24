/**
 * 334. Increasing Triplet Subsequence
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/increasing-triplet-subsequence/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] <= first) {
                first = nums[i];
            } else if (nums[i] <= second) {
                second = nums[i];
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        bool output = sol.increasingTriplet(nums);
        println("Output: {}, Expected: true", output);
    }

    // Example 2
    {
        vector<int> nums = {5, 4, 3, 2, 1};
        bool output = sol.increasingTriplet(nums);
        println("Output: {}, Expected: false", output);
    }

    // Example 3
    {
        vector<int> nums = {2, 1, 5, 0, 4, 6};
        bool output = sol.increasingTriplet(nums);
        println("Output: {}, Expected: true", output);
    }

    return 0;
}
