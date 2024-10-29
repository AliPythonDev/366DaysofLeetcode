/*
Day: 303
Problem Number: 2684 (https://leetcode.com/problems/maximum-number-of-moves-in-a-grid)
Date: 29-10-2024
Description:
You are given a 0-indexed m x n matrix grid consisting of positive integers.
You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
* From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.

Example 1:
Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.

Example 2:
Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
Output: 0
Explanation: Starting from any cell in the first column we cannot perform any moves.

Constraints:
* m == grid.length
* n == grid[i].length
* 2 <= m, n <= 1000
* 4 <= m * n <= 10^5
* 1 <= grid[i][j] <= 10^6

Code:  */
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<int> q, t;
        for (int i = 0; i < m; ++i) {
            q.insert(i);
        }
        for (int j = 0; j < n - 1; ++j) {
            t.clear();
            for (int i : q) {
                for (int k = i - 1; k <= i + 1; ++k) {
                    if (k >= 0 && k < m && grid[i][j] < grid[k][j + 1]) {
                        t.insert(k);
                    }
                }
            }
            if (t.empty()) {
                return j;
            }
            q.swap(t);
        }
        return n - 1;
    }
};
