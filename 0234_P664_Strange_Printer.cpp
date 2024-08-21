/*
Day: 234
Problem Number: 664 (https://leetcode.com/problems/strange-printer)
Date: 21-08-2024
Description:
There is a strange printer with the following two special properties:
* The printer can only print a sequence of the same character each time.
* At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.
 
Example 1:
Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

Example 2:
Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 
Constraints:
* 1 <= s.length <= 100
* s consists of lowercase English letters.

Code:  */
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0x3f, sizeof(f));
        for (int i = n - 1; ~i; --i) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i][j - 1];
                } else {
                    for (int k = i; k < j; ++k) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};
