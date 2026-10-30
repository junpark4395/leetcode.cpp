/**
 * 200. Number of Islands
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/number-of-islands/description/
 */

 /*
 A simple version
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int count = 0;

    auto dfs = [&](this auto& self, int x, int y) -> void {
        visited[y][x] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[ny][nx] == '1' && !visited[ny][nx]) {
                self(nx, ny);
            }
        }
    };
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (grid[y][x] == '1' && !visited[y][x]) {
                dfs(x, y);
                count++;
            }
        }
    }
    return count;
}
 */

#include <algorithm>
#include <iostream>
#include <print>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<bool>>& visited, vector<vector<char>>& grid, int x, int y, int max_x, int max_y) {
        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x >= 0 && new_x < max_x && new_y >= 0 && new_y < max_y && grid[new_y][new_x] == '1' && !visited[new_y][new_x]) {
                dfs(visited, grid, new_x, new_y, max_x, max_y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;

        for (size_t y = 0; y < grid.size(); y++) {
            for (size_t x = 0; x < grid[y].size(); x++) {
                if (grid[y][x] == '1' && !visited[y][x]) {
                    dfs(visited, grid, x, y, n, m);
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Example 1
    {
        vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
        };
        int output = sol.numIslands(grid);
        println("Output: {}, Expected: 1", output);
    }

    // Example 2
    {
        vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
        };
        int output = sol.numIslands(grid);
        println("Output: {}, Expected: 3", output);
    }

    return 0;
}
