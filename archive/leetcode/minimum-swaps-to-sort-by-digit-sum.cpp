/**
 * 3551. Minimum Swaps to Sort by Digit Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/description/
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <print>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {

        vector<tuple<int, int>> v;
        for (size_t i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            int digit_sum = 0;
            for (char c : s) {
                digit_sum += c - '0';
            }

            v.push_back({nums[i], digit_sum});
        }

        ranges::sort(v, [](const tuple<int, int>& a, const tuple<int, int>& b){
            if (get<1>(a) != get<1>(b)) {
                return get<1>(a) < get<1>(b);
            } else {
                return get<0>(a) < get<0>(b);
            }
        });

        unordered_map<int, int> m;
        for (size_t i = 0; i < v.size(); i++) {
            m[get<0>(v[i])] = i;
        }

        int total_swap_cnt = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            int target_val = get<0>(v[i]);

            while (nums[i] != target_val) {
                ranges::swap(nums[i], nums[m[nums[i]]]);
                total_swap_cnt++;
            }
        }

        return total_swap_cnt;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {37, 100};
        int output = sol.minSwaps(nums);
        println("Output: {}, Expected: 1", output);
    }

    // Example 2
    {
        vector<int> nums = {22, 14, 33, 7};
        int output = sol.minSwaps(nums);
        println("Output: {}, Expected: 0", output);
    }

    // Example 3
    {
        vector<int> nums = {18, 43, 34, 16};
        int output = sol.minSwaps(nums);
        println("Output: {}, Expected: 2", output);
    }

    {
        vector<int> nums = {1, 2, 3, 0};
        int output = sol.minSwaps(nums);
        println("Output: {}, Expected: 3", output);
    }

    return 0;
}
