/* 
Day: 87
Problem Number: 713 (https://leetcode.com/problems/subarray-product-less-than-k)
Date: 27-03-2024
Description:
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0

Constraints:
* 1 <= nums.length <= 3 * 10^4
* 1 <= nums[i] <= 1000
* 0 <= k <= 10^6

Code:  */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0, j = 0, s = 1; i < nums.size(); ++i) {
            s *= nums[i];
            while (j <= i && s >= k) s /= nums[j++];
            ans += i - j + 1;
        }
        return ans;
    }
};
