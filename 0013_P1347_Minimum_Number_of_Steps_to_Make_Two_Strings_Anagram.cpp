/* 
Day: 13
Problem Number: 1347 (https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram)
Date: 13-01-2024 
Description:
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.
Return the minimum number of steps to make t an anagram of s.
An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
 
Code:  */
class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26]{};
        for (char& c : s) ++cnt[c - 'a'];
        int ans = 0;
        for (char& c : t) {
            ans += --cnt[c - 'a'] < 0;
        }
        return ans;
    }
};
