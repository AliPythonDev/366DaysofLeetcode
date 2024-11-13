/*
Day: 318
Problem Number: 2563 (https://leetcode.com/problems/count-the-number-of-fair-pairs)
Date: 13-11-2024
Description:
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
A pair (i, j) is fair if:
* 0 <= i < j < n, and
* lower <= nums[i] + nums[j] <= upper
 
Example 1:
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

Example 2:
Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
 
Constraints:
* 1 <= nums.length <= 10^5
* nums.length == n
* -10^9 <= nums[i] <= 10^9
* -10^9 <= lower <= upper <= 10^9

Code:  */
class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        long long ans = 0;
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() - 1; i++) {
            auto up = upper_bound(v.begin() + i + 1, v.end(), upper - v[i]);
            auto low = lower_bound(v.begin() + i + 1, v.end(), lower - v[i]);
            ans += (up - low);
        }
        return ans;
    }
};
