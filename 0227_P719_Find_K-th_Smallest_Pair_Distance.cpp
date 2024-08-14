/*
Day: 227
Problem Number: 719 (https://leetcode.com/problems/find-k-th-smallest-pair-distance)
Date: 14-08-2024
Description:
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Example 1:
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Example 2:
Input: nums = [1,1,1], k = 2
Output: 0
Example 3:
Input: nums = [1,6,1], k = 3
Output: 5
 
Constraints:
* n == nums.length
* 2 <= n <= 10^4
* 0 <= nums[i] <= 10^6
* 1 <= k <= n * (n - 1) / 2

Code:  */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (count(mid, k, nums) >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int count(int dist, int k, vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i] - dist;
            int j = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            cnt += i - j;
        }
        return cnt;
    }
};
