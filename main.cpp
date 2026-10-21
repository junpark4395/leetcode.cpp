/**
 * 80. Remove Duplicates from Sorted Array II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
/*
a better solution instead of using the map
if (k < 2 || num != nums[k - 2])
    nums[k++] = num;
*/
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> seen;
        int k = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (seen[num] < 2) {
                seen[num]++;
                nums[k++] = num;
            }
        }

        return k;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {1, 1, 1, 2, 2, 3};
        int k = sol.removeDuplicates(nums);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        println("Output: {}, Expected: 5", k);
        println("  prefix: {}, Expected prefix: [1, 1, 2, 2, 3]", prefix);
    }

    // Example 2
    {
        vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        int k = sol.removeDuplicates(nums);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        println("Output: {}, Expected: 7", k);
        println("  prefix: {}, Expected prefix: [0, 0, 1, 1, 2, 3, 3]", prefix);
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
        vector<int> nums = {2, 2, 2, 2};
        int k = sol.removeDuplicates(nums);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        println("Output: {}, Expected: 2", k);
        println("  prefix: {}, Expected prefix: [2, 2]", prefix);
    }

    return 0;
}
