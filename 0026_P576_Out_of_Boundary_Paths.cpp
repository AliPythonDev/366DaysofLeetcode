/* 
Day: 26
Problem Number: 576 (https://leetcode.com/problems/out-of-boundary-paths)
Date: 26-01-2024 
Description:
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

Example 1:
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 
Constraints:
* 1 <= m, n <= 50
* 0 <= maxMove <= 50
* 0 <= startRow < m
* 0 <= startColumn < n

Code:  */
class Solution {
public:
    int m;
    int n;
    const int mod = 1e9 + 7;
    int f[51][51][51];
    int dirs[5] = {-1, 0, 1, 0, -1};

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(f, 0xff, sizeof(f));
        this->m = m;
        this->n = n;
        return dfs(startRow, startColumn, maxMove);
    }

    int dfs(int i, int j, int k) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (f[i][j][k] != -1) return f[i][j][k];
        if (k == 0) return 0;
        int res = 0;
        for (int t = 0; t < 4; ++t) {
            int x = i + dirs[t], y = j + dirs[t + 1];
            res += dfs(x, y, k - 1);
            res %= mod;
        }
        f[i][j][k] = res;
        return res;
    }
};
