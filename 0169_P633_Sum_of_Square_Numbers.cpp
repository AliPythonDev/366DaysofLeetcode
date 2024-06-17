/* 
Day: 169
Problem Number: 633 (https://leetcode.com/problems/sum-of-square-numbers)
Date: 17-06-2024
Description:
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
 
Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false
 
Constraints:
* 0 <= c <= 2^31 - 1

Code:  */
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) return true;

        for (long long i = 0; i * i <= c; i++) {
            long long cc = c - i * i;
            long long cc_sqrt = sqrt(cc);
            if (cc_sqrt * cc_sqrt == cc) {
                return true;
            }
        }

        return false;
    }
};
