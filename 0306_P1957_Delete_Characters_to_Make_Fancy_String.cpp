/*
Day: 306
Problem Number: 1957 (https://leetcode.com/problems/delete-characters-to-make-fancy-string)
Date: 01-11-2024
Description:
A fancy string is a string where no three consecutive characters are equal.
Given a string s, delete the minimum possible number of characters from s to make it fancy.
Return the final string after the deletion. It can be shown that the answer will always be unique.
 
Example 1:
Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".

Example 2:
Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".

Example 3:
Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
 
Constraints:
* 1 <= s.length <= 10^5
* s consists only of lowercase English letters.

Code:  */
class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for (char& c : s) {
            int n = ans.size();
            if (n < 2 || ans[n - 1] != c || ans[n - 2] != c) {
                ans += c;
            }
        }
        return ans;
    }
};
