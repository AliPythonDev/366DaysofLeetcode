/* 
Day: 76
Problem Number: 525 (https://leetcode.com/problems/contiguous-array)
Date: 16-03-2024
Description:
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
 
Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 
Constraints:
* 1 <= nums.length <= 10^5
* nums[i] is either 0 or 1.

Code:  */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int s = 0, ans = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i] == 1 ? 1 : -1;
            if (mp.count(s))
                ans = max(ans, i - mp[s]);
            else
                mp[s] = i;
        }
        return ans;
    }
};
