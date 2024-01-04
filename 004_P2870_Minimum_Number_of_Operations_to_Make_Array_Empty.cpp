/* 
Day: 4
Problem Number: 2870 (https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/)
Date: 04-01-2024 
Description:
You are given a 0-indexed array nums consisting of positive integers.
There are two types of operations that you can apply on the array any number of times:
Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

Code  */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        int ans = 0;
        for (auto [_, c]: counter) {
            if (c == 1) {
                return -1;
            }
            ans += ceil((double)(c) / 3);
        }
        return ans;
    }
};
