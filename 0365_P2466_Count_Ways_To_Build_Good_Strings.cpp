/*
Day: 365
Problem Number: 2466 (https://leetcode.com/problems/count-ways-to-build-good-strings)
Date: 30-12-2024
Description:
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
* Append the character '0' zero times.
* Append the character '1' one times.
This can be performed any number of times.
A good string is a string constructed by the above process having a length between low and high (inclusive).
Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.
 
Example 1:
Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.

Example 2:
Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
 
Constraints:
* 1 <= low <= high <= 10^5
* 1 <= zero, one <= low

Code:  */
class Solution {
public:
    int dp[100005];
    int MOD = 1e9 + 7;
    int func(int low, int high, int zero, int one, int size){
        if(size > high){
            return 0;
        }

        if(dp[size] != -1){
            return dp[size];
        }

        int temp = size >= low ? 1 : 0;
        long long zero_cnt = func(low, high, zero, one, size + zero);
        long long one_cnt = func(low, high, zero, one, size + one);

        return dp[size] = (zero_cnt + one_cnt + temp) % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));

        return func(low, high, zero, one, 0);
    }
};
