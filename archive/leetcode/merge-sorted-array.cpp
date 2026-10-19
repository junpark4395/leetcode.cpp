/**
 * 88. Merge Sorted Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-sorted-array/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start_idx = m;
        for (size_t i = 0; i < nums2.size(); i++) {
            nums1[m+i] = nums2[i];
        }

        ranges::sort(nums1);
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums1 = {1, 2, 3, 0, 0, 0};
        vector<int> nums2 = {2, 5, 6};
        sol.merge(nums1, 3, nums2, 3);
        println("Output: {}, Expected: {}", nums1, vector<int>{1, 2, 2, 3, 5, 6});
    }

    // Example 2
    {
        vector<int> nums1 = {1};
        vector<int> nums2 = {};
        sol.merge(nums1, 1, nums2, 0);
        println("Output: {}, Expected: {}", nums1, vector<int>{1});
    }

    // Example 3
    {
        vector<int> nums1 = {0};
        vector<int> nums2 = {1};
        sol.merge(nums1, 0, nums2, 1);
        println("Output: {}, Expected: {}", nums1, vector<int>{1});
    }

    return 0;
}
