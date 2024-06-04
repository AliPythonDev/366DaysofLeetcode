/* 
Day: 156
Problem Number: 409 (https://leetcode.com/problems/longest-palindrome)
Date: 04-06-2024
Description:
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.
 
Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 
Constraints:
* 1 <= s.length <= 2000
* s consists of lowercase and/or uppercase English letters only.

Code:  */
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hm;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (hm.find(c) != hm.end()) {
                hm[c]++;
            } else {
                hm[c] = 1;
            }
        }

        int ans = 0;
        bool isFirstOdd = false;

        for (auto& pair : hm) {
            if (pair.second % 2 == 0) {
                ans += pair.second;
            } else {
                ans += pair.second;
                if (!isFirstOdd) {
                    isFirstOdd = true;
                } else {
                    ans -= 1;
                }
            }
        }

        return ans;
    }
};
