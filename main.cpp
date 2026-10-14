/**
 * 3727. Maximum Alternating Sum of Squares
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/?envType=daily-question&envId=2026-10-13
 */

#include <algorithm>
#include <cmath>
#include <print>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ranges::sort(nums, greater<int>{}, [](int x) { return abs(x); });

        int l = 0;
        int r = nums.size() - 1;
        long long total = 0;

        while (l < r) {
            total += 1LL * nums[l] * nums[l];
            total -= 1LL * nums[r] * nums[r];

            l++;
            r--;
        }

        if (l == r) {
            total += 1LL * nums[l] * nums[l];
        }

        return total;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {1, 2, 3};
        long long output = sol.maxAlternatingSum(nums);
        println("Example 1: Output = {}", output);
    }

    // Example 2
    {
        vector<int> nums = {1, -1, 2, -2, 3, -3};
        long long output = sol.maxAlternatingSum(nums);
        println("Example 2: Output = {}", output);
    }

    return 0;
}
