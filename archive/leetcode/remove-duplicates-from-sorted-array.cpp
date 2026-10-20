/**
 * 26. Remove Duplicates from Sorted Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int seen = -101;
        int k = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (seen != num) {
                seen = num;

                nums[k] = num;
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {1, 1, 2};
        int k = sol.removeDuplicates(nums);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        println("Output: {}, Expected: 2", k);
        println("  prefix: {}, Expected prefix: [1, 2]", prefix);
    }

    // Example 2
    {
        vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int k = sol.removeDuplicates(nums);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        println("Output: {}, Expected: 5", k);
        println("  prefix: {}, Expected prefix: [0, 1, 2, 3, 4]", prefix);
    }

    // Edge case 1: single element
    {
        vector<int> nums = {1};
        int k = sol.removeDuplicates(nums);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        println("Output: {}, Expected: 1", k);
        println("  prefix: {}, Expected prefix: [1]", prefix);
    }

    // Edge case 2: all elements equal
    {
        vector<int> nums = {2, 2, 2};
        int k = sol.removeDuplicates(nums);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        println("Output: {}, Expected: 1", k);
        println("  prefix: {}, Expected prefix: [2]", prefix);
    }

    return 0;
}
