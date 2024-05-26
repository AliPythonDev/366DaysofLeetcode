/* 
Day: 147
Problem Number: 141 (https://leetcode.com/problems/student-attendance-record-ii)
Date: 26-05-2024
Description:
An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
* 'A': Absent.
* 'L': Late.
* 'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:
* The student was absent ('A') for strictly fewer than 2 days total.
* The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 10^9 + 7.
 
Example 1:
Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).

Example 2:
Input: n = 1
Output: 3

Example 3:
Input: n = 10101
Output: 183236316
 
Constraints:
* 1 <= n <= 10^5

Constraints:
* 1 <= s.length <= 20
* 1 <= wordDict.length <= 1000
* 1 <= wordDict[i].length <= 10
* s and wordDict[i] consist of only lowercase English letters.
* All the strings of wordDict are unique.
* Input is generated in a way that the length of the answer doesn't exceed 10^5.

Code:  */
int f[100010][2][3];
const int mod = 1e9 + 7;

class Solution {
public:
    int checkRecord(int n) {
        this->n = n;
        memset(f, -1, sizeof(f));
        return dfs(0, 0, 0);
    }

    int dfs(int i, int j, int k) {
        if (i >= n) {
            return 1;
        }
        if (f[i][j][k] != -1) {
            return f[i][j][k];
        }
        int ans = dfs(i + 1, j, 0);
        if (j == 0) {
            ans = (ans + dfs(i + 1, j + 1, 0)) % mod;
        }
        if (k < 2) {
            ans = (ans + dfs(i + 1, j, k + 1)) % mod;
        }
        return f[i][j][k] = ans;
    }

private:
    int n;
};
