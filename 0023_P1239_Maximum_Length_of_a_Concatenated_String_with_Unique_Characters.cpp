/* 
Day: 23
Problem Number: 1239 (https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters)
Date: 23-01-2024 
Description:
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
 
Constraints:
* 1 <= arr.length <= 16
* 1 <= arr[i].length <= 26

Code:  */
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        vector<int> masks = {0};
        for (auto& s : arr) {
            int mask = 0;
            for (auto& c : s) {
                int i = c - 'a';
                if (mask >> i & 1) {
                    mask = 0;
                    break;
                }
                mask |= 1 << i;
            }
            if (mask == 0) {
                continue;
            }
            int n = masks.size();
            for (int i = 0; i < n; ++i) {
                int m = masks[i];
                if ((m & mask) == 0) {
                    masks.push_back(m | mask);
                    ans = max(ans, __builtin_popcount(m | mask));
                }
            }
        }
        return ans;
    }
};
