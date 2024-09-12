/*
Day: 256
Problem Number: 1684 (https://leetcode.com/problems/count-the-number-of-consistent-strings)
Date: 12-09-2024
Description:
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.
 
Example 1:
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:
Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 
Constraints:
* 1 <= words.length <= 10^4
* 1 <= allowed.length <= 26
* 1 <= words[i].length <= 10
* The characters in allowed are distinct.
* words[i] and allowed contain only lowercase English letters.

Code:  */
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26] = {0};
        for (char c : allowed) {
            arr[c - 'a'] = 1;
        }
        
        int count = 0;
        for (string word : words) {
            int flag = 1;
            for (char c : word) {
                if (arr[c - 'a'] == 0) {
                    flag = 0;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};
