/*
Day: 361
Problem Number: 494 (https://leetcode.com/problems/target-sum)
Date: 26-12-2024
Description:
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
* For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
 
Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1
 
Constraints:
* 1 <= nums.length <= 20
* 0 <= nums[i] <= 1000
* 0 <= sum(nums[i]) <= 1000
* -1000 <= target <= 1000

Code:  */
class Solution {
public:
    void computeSums(const vector<int>& nums, int start, int end,  vector<long long>& sums) {
        sums.push_back(0);
        for (int i = start; i < end; ++i) {
            int num = nums[i];
            int n = sums.size();
            for (int j = 0; j < n; ++j) {
                sums.push_back(sums[j] + num);
                sums[j] -= num;
            }
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int mid = n / 2;
        vector<long long> sums1;
        vector<long long> sums2;
        computeSums(nums, 0, mid, sums1);
        computeSums(nums, mid, n, sums2);
        unordered_map<long long, long long> countMap;
        for (auto sum : sums2) {
            countMap[sum]++;
        }
        long long total = 0;
        for (auto sum : sums1) {
            long long complement = (long long)target - sum;
            if (countMap.find(complement) != countMap.end()) {
                total += countMap[complement];
            }
        }

        return total;
    }
};
