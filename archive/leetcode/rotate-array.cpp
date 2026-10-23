/**
 * 189. Rotate Array
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/rotate-array/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // k가 배열 길이보다 큰 경우 방지

        // 1. 전체 뒤집기: [1,2,3,4,5,6,7] -> [7,6,5,4,3,2,1]
        ranges::reverse(nums);

        // 2. 앞쪽 k개 뒤집기: [7,6,5] -> [5,6,7]
        ranges::reverse(nums.begin(), nums.begin() + k);

        // 3. 뒤쪽 나머지 뒤집기: [4,3,2,1] -> [1,2,3,4]
        ranges::reverse(nums.begin() + k, nums.end());
    }
};
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int itr = 0;
        int start_idx = 0;
        int prev_val = nums[0];
        int swap_cnt = 0;
        k %= n;

        while (swap_cnt < n) {
            if (swap_cnt != 0 && itr == start_idx) {
                start_idx = ++itr;
                prev_val = nums[itr];
            }

            int next_idx = (itr + k) % n;
            int temp = nums[next_idx];

            nums[next_idx] = prev_val;
            swap_cnt++;

            prev_val = temp;
            itr = next_idx;
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;
        sol.rotate(nums, k);
        println("Output: {}, Expected: [5, 6, 7, 1, 2, 3, 4]", nums);
    }

    // Example 2
    {
        vector<int> nums = {-1, -100, 3, 99};
        int k = 2;
        sol.rotate(nums, k);
        println("Output: {}, Expected: [3, 99, -1, -100]", nums);
    }

    return 0;
}
