/**
 * 27. Remove Element
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-element/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // simple version
    int removeElement2(vector<int>& nums, int val) {
        int w = 0;
        for (int x : nums)
            if (x != val) nums[w++] = x;
        return w;
    }

    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size() - 1;
        int k = nums.size();

        while (l < r) {
            while (nums[r] == val && r > 0) {
                r--;
                k--;
            }

            while (nums[l] != val && l < nums.size() - 1) {
                l++;
            }

            if (l > r)
                break;

            if (nums[l] == val) {
                nums[l] = nums[r];
                nums[r] = val;
            }
        }

        if (l == r && nums[l] == val){
            k--;
        }

        return k;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {3, 2, 2, 3};
        int k = sol.removeElement(nums, 3);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        ranges::sort(prefix);
        println("Output: {}, Expected: 2", k);
        println("  prefix: {}, Expected prefix: [2, 2]", prefix);
    }

    // Example 2
    {
        vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
        int k = sol.removeElement(nums, 2);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        ranges::sort(prefix);
        println("Output: {}, Expected: 5", k);
        println("  prefix: {}, Expected prefix: [0, 0, 1, 3, 4]", prefix);
    }

    // Edge case 1: single element equal to val
    {
        vector<int> nums = {2};
        int k = sol.removeElement(nums, 2);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        ranges::sort(prefix);
        println("Output: {}, Expected: 0", k);
        println("  prefix: {}, Expected prefix: []", prefix);
    }

    // Edge case 2: single element not equal to val
    {
        vector<int> nums = {2};
        int k = sol.removeElement(nums, 3);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        ranges::sort(prefix);
        println("Output: {}, Expected: 1", k);
        println("  prefix: {}, Expected prefix: [2]", prefix);
    }

    // Edge case 3: all elements equal to val
    {
        vector<int> nums = {3, 3};
        int k = sol.removeElement(nums, 3);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        ranges::sort(prefix);
        println("Output: {}, Expected: 0", k);
        println("  prefix: {}, Expected prefix: []", prefix);
    }

    // Edge case 4: empty array
    {
        vector<int> nums = {};
        int k = sol.removeElement(nums, 1);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        ranges::sort(prefix);
        println("Output: {}, Expected: 0", k);
        println("  prefix: {}, Expected prefix: []", prefix);
    }

    // Edge case 5: val not present
    {
        vector<int> nums = {1, 2};
        int k = sol.removeElement(nums, 3);
        vector<int> prefix(nums.begin(), nums.begin() + k);
        ranges::sort(prefix);
        println("Output: {}, Expected: 2", k);
        println("  prefix: {}, Expected prefix: [1, 2]", prefix);
    }

    return 0;
}
