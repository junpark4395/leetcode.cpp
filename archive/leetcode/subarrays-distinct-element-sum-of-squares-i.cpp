/**
 * 2913. Subarrays Distinct Element Sum of Squares I
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/
 */

#include <vector>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum_counts = 0;

        for (int i = 0; i < n; i++) {
            bool seen[101] = {false};
            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    distinct++;
                }
                sum_counts += distinct * distinct;
            }
        }

        return sum_counts;
    }
};