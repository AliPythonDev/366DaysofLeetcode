/* 
Day: 152
Problem Number: 260 (https://leetcode.com/problems/single-number-iii)
Date: 31-05-2024
Description:
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
 
Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]

Example 3:
Input: nums = [0,1]
Output: [1,0]
 
Constraints:
* 2 <= nums.length <= 3 * 10^4
* -2^31 <= nums[i] <= 2^31 - 1
* Each integer in nums will appear twice, only two integers will appear once.

Code:  */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(2);
        int index = 0;

        for (int i = 0; i < n; ++i) {
            bool found = false;
            for (int j = 0; j < n; ++j) {
                if (i != j && nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[index++] = nums[i];
                if (index == 2) {
                    break;
                }
            }
        }

        return result;
    }
};
