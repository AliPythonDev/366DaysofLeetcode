/*
Day: 232
Problem Number: 650 (https://leetcode.com/problems/2-keys-keyboard)
Date: 19-08-2024
Description:
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:
* Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
* Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.
 
Example 1:
Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Example 2:
Input: n = 1
Output: 0
 
Constraints:
* 1 <= n <= 1000

Code:  */
class Solution {
public:
    vector<int> f;

    int minSteps(int n) {
        f.assign(n + 1, -1);
        return dfs(n);
    }

    int dfs(int n) {
        if (n == 1) return 0;
        if (f[n] != -1) return f[n];
        int ans = n;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                ans = min(ans, dfs(n / i) + i);
            }
        }
        f[n] = ans;
        return ans;
    }
};
