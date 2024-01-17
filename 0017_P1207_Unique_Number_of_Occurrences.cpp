/* 
Day: 17
Problem Number: 1207 (https://leetcode.com/problems/unique-number-of-occurrences)
Date: 17-01-2024 
Description:
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
 
Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:
Input: arr = [1,2]
Output: false
Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 
Constraints:
* 1 <= arr.length <= 1000
* -1000 <= arr[i] <= 1000
 
Code:  */
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int& x : arr) {
            ++cnt[x];
        }
        unordered_set<int> vis;
        for (auto& [_, v] : cnt) {
            if (vis.count(v)) {
                return false;
            }
            vis.insert(v);
        }
        return true;
    }
};
