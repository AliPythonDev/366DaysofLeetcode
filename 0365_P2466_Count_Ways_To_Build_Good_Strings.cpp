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
    const int mod = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> f(high + 1, -1);
        function<int(int)> dfs = [&](int i) -> int {
            if (i > high) return 0;
            if (f[i] != -1) return f[i];
            long ans = i >= low && i <= high;
            ans += dfs(i + zero) + dfs(i + one);
            ans %= mod;
            f[i] = ans;
            return ans;
        };
        return dfs(0);
    }
};
