/* 
Day: 14
Problem Number: 1657 (https://leetcode.com/problems/determine-if-two-strings-are-close)
Date: 14-01-2024 
Description:
Two strings are considered close if you can attain one from the other using the following operations:
* Operation 1: Swap any two existing characters.
    * For example, abcde -> aecdb
* Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
    * For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.
Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
 
Code:  */
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int cnt1[26]{};
        int cnt2[26]{};
        for (char& c : word1) {
            ++cnt1[c - 'a'];
        }
        for (char& c : word2) {
            ++cnt2[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if ((cnt1[i] == 0) != (cnt2[i] == 0)) {
                return false;
            }
        }
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        return equal(cnt1, cnt1 + 26, cnt2);
    }
};
