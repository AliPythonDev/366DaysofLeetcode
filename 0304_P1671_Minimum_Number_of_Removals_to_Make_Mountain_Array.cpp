/*
Day: 304
Problem Number: 1671 (https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array)
Date: 30-10-2024
Description:
You may recall that an array arr is a mountain array if and only if:
* arr.length >= 3
* There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
    * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums , return the minimum number of elements to remove to make nums​​​ a mountain array.
 
Example 1:
Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.

Example 2:
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
 
Constraints:
* 3 <= nums.length <= 1000
* 1 <= nums[i] <= 10^9
* It is guaranteed that you can make a mountain array out of nums.

Code:  */
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1), LDS(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int maxMountainLength = 0;

        for (int i = 1; i < n - 1; ++i) {
            if (LIS[i] > 1 && LDS[i] > 1) {
                maxMountainLength = max(maxMountainLength, LIS[i] + LDS[i] - 1);
            }
        }

        return n - maxMountainLength;
    }
};
