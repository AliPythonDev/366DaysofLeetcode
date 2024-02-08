/* 
Day: 39
Problem Number:  279 (https://leetcode.com/problems/perfect-squares)
Date: 08-02-2024 
Description:
Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
 
Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 
Constraints:
* 1 <= n <= 104

Code:  */
class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        int f[m + 1][n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= i * i) {
                    f[i][j] = min(f[i][j], f[i][j - i * i] + 1);
                }
            }
        }
        return f[m][n];
    }
};
