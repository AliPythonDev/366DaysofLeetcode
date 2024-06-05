/* 
Day: 157
Problem Number: 1002 (https://leetcode.com/problems/find-common-characters)
Date: 05-06-2024
Description:
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
 
Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 
Constraints:
* 1 <= words.length <= 100
* 1 <= words[i].length <= 100
* words[i] consists of lowercase English letters.

Code:  */
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX);

        for (const string& word : words) {
            vector<int> charCount(26, 0);
            for (char c : word) {
                charCount[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], charCount[i]);
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (minFreq[i] > 0) {
                result.push_back(string(1, i + 'a'));
                minFreq[i]--;
            }
        }

        return result;
    }
};
