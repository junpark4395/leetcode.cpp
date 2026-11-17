/**
 * 1944. Number of Visible People in a Queue
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        vector<int> answer(heights.size(), 0);

        for (int i = heights.size() - 1; i >= 0; i--) {
            int cnt = 0;
            while(!s.empty() && s.top() <= heights[i]) {
                cnt++;
                s.pop();
            }

            if (!s.empty()) {
                cnt += 1;
            }

            s.push(heights[i]);

            answer[i] = cnt;
        }

        return answer;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<int> heights = {10, 6, 8, 5, 11, 9};
        vector<int> output = sol.canSeePersonsCount(heights);
        println("Output: {}, Expected: [3, 1, 2, 1, 1, 0]", output);
    }

    // Example 2
    {
        vector<int> heights = {5, 1, 2, 3, 10};
        vector<int> output = sol.canSeePersonsCount(heights);
        println("Output: {}, Expected: [4, 1, 1, 1, 0]", output);
    }

    return 0;
}
