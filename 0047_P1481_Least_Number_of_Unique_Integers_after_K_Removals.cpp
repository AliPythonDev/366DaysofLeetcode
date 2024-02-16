/* 
Day: 47
Problem Number: 1481 (https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals)
Date: 16-02-2024 
Description:
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

Example 1:
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.

Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 
Constraints:
* 1 <= arr.length <= 10^5
* 1 <= arr[i] <= 10^9
* 0 <= k <= arr.length

Code:  */
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (int& x : arr) {
            ++cnt[x];
        }
        vector<int> nums;
        for (auto& [_, c] : cnt) {
            nums.push_back(c);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0, m = nums.size(); i < m; ++i) {
            k -= nums[i];
            if (k < 0) {
                return m - i;
            }
        }
        return 0;
    }
};
