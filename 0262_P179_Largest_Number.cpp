/*
Day: 262
Problem Number: 179 (https://leetcode.com/problems/largest-number)
Date: 18-09-2024
Description:
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.
 
Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"
 
Constraints:
* 1 <= nums.length <= 100
* 0 <= nums[i] <= 10^9

Code:  */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for (int v : nums) vs.push_back(to_string(v));
        sort(vs.begin(), vs.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        if (vs[0] == "0") return "0";
        string ans;
        for (string v : vs) ans += v;
        return ans;
    }
};
