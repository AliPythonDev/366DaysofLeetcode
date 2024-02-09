/* 
Day: 40
Problem Number:  368 (https://leetcode.com/problems/largest-divisible-subset)
Date: 09-02-2024 
Description:
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
* answer[i] % answer[j] == 0, or
* answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
 
Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 
Constraints:
* 1 <= nums.length <= 1000
* 1 <= nums[i] <= 2 * 109
* All the integers in nums are unique.

Code:  */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int f[n];
        int k = 0;
        for (int i = 0; i < n; ++i) {
            f[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
            if (f[k] < f[i]) {
                k = i;
            }
        }
        int m = f[k];
        vector<int> ans;
        for (int i = k; m > 0; --i) {
            if (nums[k] % nums[i] == 0 && f[i] == m) {
                ans.push_back(nums[i]);
                k = i;
                --m;
            }
        }
        return ans;
    }
};
