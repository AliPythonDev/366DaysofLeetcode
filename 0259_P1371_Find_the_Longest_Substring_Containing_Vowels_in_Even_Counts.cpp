/*
Day: 259
Problem Number: 1371 (https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts)
Date: 15-09-2024
Description:
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
 
Example 1:
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

Example 2:
Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.

Example 3:
Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 
Constraints:
* 1 <= s.length <= 5 x 10^5
* s contains only lowercase English letters.

Code:  */
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> pos(32, INT_MAX);
        pos[0] = -1;
        string vowels = "aeiou";
        int state = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < 5; ++j)
                if (s[i] == vowels[j])
                    state ^= (1 << j);
            ans = max(ans, i - pos[state]);
            pos[state] = min(pos[state], i);
        }
        return ans;
    }
};
