/**
 * 56. Merge Intervals
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/merge-intervals/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

/*
A Simple version

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals);

        vector<vector<int>> answer;

        for (const auto& interval : intervals) {
            if (answer.empty() || answer.back()[1] < interval[0]) {
                answer.push_back(interval);
            }
            else {
                answer.back()[1] = max(answer.back()[1], interval[1]);
            }
        }

        return answer;
    }
};
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // actually ranges:;sort(intervals) is working for this
        ranges::sort(intervals, [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> answer;
        int start = intervals[0][0];
        int finish = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= finish) {
                if (intervals[i][1] >= finish) {
                    finish = intervals[i][1];
                }

            } else {
                answer.push_back({start, finish});
                start = intervals[i][0];
                finish = intervals[i][1];
            }
        }

        answer.push_back({start, finish});
        return answer;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        vector<vector<int>> output = sol.merge(intervals);
        println("Output: {}, Expected: [[1, 6], [8, 10], [15, 18]]", output);
    }

    // Example 2
    {
        vector<vector<int>> intervals = {{1, 4}, {4, 5}};
        vector<vector<int>> output = sol.merge(intervals);
        println("Output: {}, Expected: [[1, 5]]", output);
    }

    {
        vector<vector<int>> intervals = {{1, 4}, {2, 3}, {5, 6}};
        vector<vector<int>> output = sol.merge(intervals);
        println("Output: {}, Expected: [[1, 4]]", output);
    }

    return 0;
}
