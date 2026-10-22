/**
 * 169. Majority Element
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/majority-element/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ranges::sort(nums);
        return nums[nums.size() / 2];
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {3, 2, 3};
        int output = sol.majorityElement(nums);
        println("Output: {}, Expected: 3", output);
    }

    // Example 2
    {
        vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
        int output = sol.majorityElement(nums);
        println("Output: {}, Expected: 2", output);
    }

    return 0;
}
