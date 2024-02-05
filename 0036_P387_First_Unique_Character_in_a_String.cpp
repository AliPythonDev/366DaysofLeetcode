/* 
Day: 36
Problem Number:  387 (https://leetcode.com/problems/first-unique-character-in-a-string)
Date: 05-02-2024 
Description:
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
 
Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
 
Constraints:
* 1 <= s.length <= 105
* s consists of only lowercase English letters.

Code:  */
class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
