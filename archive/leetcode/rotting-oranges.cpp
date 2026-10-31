/**
 * 994. Rotting Oranges
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/rotting-oranges/description/
 */

/*
A Simple version
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshes = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) freshes++;
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int minutes = 0;

        while (!q.empty() && freshes > 0) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [y, x] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (nx >= 0 && ny >= 0 && nx < cols && ny < rows && grid[ny][nx] == 1) {
                        grid[ny][nx] = 2;
                        freshes--;
                        q.push({ny, nx});
                    }
                }
            }
            minutes++;
        }

        return freshes == 0 ? minutes : -1;
    }
};
*/

#include <algorithm>
#include <iostream>
#include <print>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int min = 0;
        int freshes = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    freshes++;
            }
        }

        while (true) {
            vector<vector<bool>> m(rows, vector<bool>(cols, false));

            bool has_found = false;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 1 && !m[i][j]) {
                        for (int k = 0; k < 4; k++) {
                            int x = j + dx[k];
                            int y = i + dy[k];

                            if (x >= 0 && y >= 0 && x < cols && y < rows && grid[y][x] == 2) {
                                has_found = true;
                                m[i][j] = true;
                                break;
                            }
                        }
                    }
                }
            }

            if (!has_found) {
                if (freshes > 0)
                    min = -1;

                break;
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (m[i][j]) {
                        grid[i][j] = 2;
                        freshes--;
                    }
                }
            }

            min++;
        }

        return min;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
        int output = sol.orangesRotting(grid);
        println("Output: {}, Expected: 4", output);
    }

    // Example 2
    {
        vector<vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
        int output = sol.orangesRotting(grid);
        println("Output: {}, Expected: -1", output);
    }

    // Example 3
    {
        vector<vector<int>> grid = {{0, 2}};
        int output = sol.orangesRotting(grid);
        println("Output: {}, Expected: 0", output);
    }

    return 0;
}
