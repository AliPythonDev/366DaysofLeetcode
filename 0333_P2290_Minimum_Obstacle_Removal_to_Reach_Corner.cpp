/*
Day: 333
Problem Number: 2290 (https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner)
Date: 28-11-2024
Description:
You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
* 0 represents an empty cell,
* 1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.
Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

Example 1:
Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
Output: 2
Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.

Example 2:
Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
Output: 0
Explanation: We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.

Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 10^5
* 2 <= m * n <= 10^5
* grid[i][j] is either 0 or 1.
* grid[0][0] == grid[m - 1][n - 1] == 0

Code:  */
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        deque<tuple<int, int, int>> q{{0, 0, 0}};
        bool vis[m][n];
        memset(vis, 0, sizeof vis);
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (1) {
            auto [i, j, k] = q.front();
            q.pop_front();
            if (i == m - 1 && j == n - 1) {
                return k;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (int h = 0; h < 4; ++h) {
                int x = i + dirs[h], y = j + dirs[h + 1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 0) {
                        q.push_front({x, y, k});
                    } else {
                        q.push_back({x, y, k + 1});
                    }
                }
            }
        }
    }
};
