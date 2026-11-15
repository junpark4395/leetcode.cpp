/**
 * 22. Generate Parentheses
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/generate-parentheses/description/
 */

#include <algorithm>
#include <print>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void backtrack(int n, int open, int close, string& s, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            backtrack(n, open + 1, close, s, result);
            s.pop_back();
        }

        if (close < n && close < open) {
            s.push_back(')');
            backtrack(n, open, close + 1, s, result);
            s.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        s.reserve(2 * n);

        backtrack(n, 0, 0, s, result);

        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        int n = 3;
        vector<string> output = sol.generateParenthesis(n);
        println("Output: {}", output);
        println("Expected: [\"((()))\", \"(()())\", \"(())()\", \"()(())\", \"()()()\"]");
    }

    // Example 2
    {
        int n = 1;
        vector<string> output = sol.generateParenthesis(n);
        println("Output: {}", output);
        println("Expected: [\"()\"]");
    }

    return 0;
}
