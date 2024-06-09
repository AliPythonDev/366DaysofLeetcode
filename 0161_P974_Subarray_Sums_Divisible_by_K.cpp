/* 
Day: 161
Problem Number: 974 (https://leetcode.com/problems/subarray-sums-divisible-by-k)
Date: 09-06-2024
Description:
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
A subarray is a contiguous part of an array.
 
Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:
Input: nums = [5], k = 9
Output: 0
 
Constraints:
* 1 <= nums.length <= 3 * 10^4
* -10^4 <= nums[i] <= 10^4
* 2 <= k <= 10^4

Code:  */
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {        
    int sum=0;
    int count=0;
    map<int,int>mp;
    mp[0]++;

    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        int rem=sum%k;
        
        if(rem<0)
        {
            rem=k+rem;
        }
        
        if(mp[rem]>0)
            count+=mp[rem];

        mp[rem]++;
    }
    return count; 
    }
};
