/* 
Day: 116
Problem Number: 2370 (https://leetcode.com/problems/longest-ideal-subsequence)
Date: 25-04-2024
Description:
You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:
* t is a subsequence of the string s.
* The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

Example 1:
Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.

Example 2:
Input: s = "abcd", k = 3
Output: 4
Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.

Constraints:
* 1 <= s.length <= 10^5
* 0 <= k <= 25
* s consists of lowercase English letters.

Code:  */
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int ans = 1;
        vector<int> dp(n, 1);
        unordered_map<char, int> d;
        d[s[0]] = 0;
        for (int i = 1; i < n; ++i) {
            char a = s[i];
            for (char b = 'a'; b <= 'z'; ++b) {
                if (abs(a - b) > k) continue;
                if (d.count(b)) dp[i] = max(dp[i], dp[d[b]] + 1);
            }
            d[a] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
