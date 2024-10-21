/*
Day: 295
Problem Number: 1593 (https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings)
Date: 21-10-2024
Description:
Given a string s, return the maximum number of unique substrings that the given string can be split into.
You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
A substring is a contiguous sequence of characters within a string.
 
Example 1:
Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.

Example 2:
Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].

Example 3:
Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.
 
Constraints:
* 1 <= s.length <= 16
* s contains only lower case English letters.

Code:  */
class Solution {
public:
    unordered_set<string> vis;
    string s;
    int ans = 1;

    int maxUniqueSplit(string s) {
        this->s = s;
        dfs(0, 0);
        return ans;
    }

    void dfs(int i, int t) {
        if (i >= s.size()) {
            ans = max(ans, t);
            return;
        }
        for (int j = i + 1; j <= s.size(); ++j) {
            string x = s.substr(i, j - i);
            if (!vis.count(x)) {
                vis.insert(x);
                dfs(j, t + 1);
                vis.erase(x);
            }
        }
    }
};
