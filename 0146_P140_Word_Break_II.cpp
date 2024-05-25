/* 
Day: 146
Problem Number: 140 (https://leetcode.com/problems/word-break-ii)
Date: 25-05-2024
Description:
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
 
Example 1:
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

Example 2:
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 
Constraints:
* 1 <= s.length <= 20
* 1 <= wordDict.length <= 1000
* 1 <= wordDict[i].length <= 10
* s and wordDict[i] consist of only lowercase English letters.
* All the strings of wordDict are unique.
* Input is generated in a way that the length of the answer doesn't exceed 10^5.

Code:  */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, 0, dict);
    }

private:
    vector<string> wordBreakHelper(const string& s, int start, const unordered_set<string>& dict) {
        vector<string> validSubstr;
        
        if (start == s.length())
            validSubstr.push_back("");
        for (int end = start + 1; end <= s.length(); ++end) {
            string prefix = s.substr(start, end - start);
            if (dict.find(prefix) != dict.end()) {
                vector<string> suffixes = wordBreakHelper(s, end, dict);
                for (const string& suffix : suffixes) {
                    validSubstr.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }
        return validSubstr;
    }
};
