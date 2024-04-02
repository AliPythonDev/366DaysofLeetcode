/* 
Day: 93
Problem Number: 205 (https://leetcode.com/problems/isomorphic-strings)
Date: 02-04-2024
Description:
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:
* 1 <= s.length <= 5 * 10^4
* t.length == s.length
* s and t consist of any valid ascii character.

Code:  */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int d1[256]{};
        int d2[256]{};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char a = s[i], b = t[i];
            if (d1[a] != d2[b]) {
                return false;
            }
            d1[a] = d2[b] = i + 1;
        }
        return true;
    }
};
