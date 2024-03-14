/* 
Day: 74
Problem Number: 930 (https://leetcode.com/problems/binary-subarrays-with-sum)
Date: 14-03-2024
Description:
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.
 
Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 
Constraints:
* 1 <= nums.length <= 3 * 10^4
* nums[i] is either 0 or 1.
* 0 <= goal <= nums.length

Code:  */
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt[nums.size() + 1];
        memset(cnt, 0, sizeof cnt);
        cnt[0] = 1;
        int ans = 0, s = 0;
        for (int& v : nums) {
            s += v;
            if (s - goal >= 0) {
                ans += cnt[s - goal];
            }
            ++cnt[s];
        }
        return ans;
    }
};
