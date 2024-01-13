/* 
Day: 7
Problem Number: 446 (https://leetcode.com/problems/arithmetic-slices-ii-subsequence)
Date: 07-01-2024 
Description:
Given an integer array nums, return the number of all the arithmetic subsequences of nums.
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
* For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
* For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
* For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.

Code:  */
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& a) {
		long long ans = 0, n = a.size();
		vector<unordered_map<long, long>> dp(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				long long diff = (long long)a[i] - (long long)a[j];

				dp[i][diff]++;
				if (dp[j].count(diff)) {
					dp[i][diff] += dp[j][diff];
					ans += dp[j][diff];
				}
			}
		}
		return ans;
	}
};
