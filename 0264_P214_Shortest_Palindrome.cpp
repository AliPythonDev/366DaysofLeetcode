/*
Day: 264
Problem Number: 214 (https://leetcode.com/problems/shortest-palindrome)
Date: 20-09-2024
Description:
You are given a string s. You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.
 
Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:
Input: s = "abcd"
Output: "dcbabcd"
 
Constraints:
* 0 <= s.length <= 5 * 10^4
* s consists of lowercase English letters only.

Code:  */
typedef unsigned long long ull;

class Solution {
public:
    string shortestPalindrome(string s) {
        int base = 131;
        ull mul = 1;
        ull prefix = 0;
        ull suffix = 0;
        int idx = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            int t = s[i] - 'a' + 1;
            prefix = prefix * base + t;
            suffix = suffix + mul * t;
            mul *= base;
            if (prefix == suffix) idx = i + 1;
        }
        if (idx == n) return s;
        string x = s.substr(idx, n - idx);
        reverse(x.begin(), x.end());
        return x + s;
    }
};
