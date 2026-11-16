/**
 * 207. Course Schedule
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/course-schedule/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <queue>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjs(numCourses);
        vector<int> state(numCourses, 0);

        for (size_t i = 0; i < prerequisites.size(); i++) {
            int target = prerequisites[i][0];
            int required = prerequisites[i][1];

            adjs[required].push_back(target);
        }

        bool possible = true;

        auto dfs = [&](this auto&& self, int v) -> bool {
            if (state[v] == 2)
                return true;

            if (state[v] == 1)
                return false;

            state[v] = 1;

            for (size_t i = 0; i < adjs[v].size(); i++) {
                int next = adjs[v][i];
                if (!self(next)) {
                    return false;
                }
            }

            state[v] = 2;
            return true;
        };

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    {
        int numCourses = 5;
        vector<vector<int>> prerequisites = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
        bool output = sol.canFinish(numCourses, prerequisites);
        println("Output: {}, Expected: true", output);
    }

    {
        int numCourses = 3;
        vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {0, 2}};
        bool output = sol.canFinish(numCourses, prerequisites);
        println("Output: {}, Expected: false", output);
    }

    {
        int numCourses = 4;
        vector<vector<int>> prerequisites = {{1, 0}, {3, 2}};
        bool output = sol.canFinish(numCourses, prerequisites);
        println("Output: {}, Expected: true", output);
    }

    // Example 2
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
        bool output = sol.canFinish(numCourses, prerequisites);
        println("Output: {}, Expected: false", output);
    }

    // Example 1
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0}};
        bool output = sol.canFinish(numCourses, prerequisites);
        println("Output: {}, Expected: true", output);
    }

    return 0;
}
