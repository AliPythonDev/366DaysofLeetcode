/*
Day: 231
Problem Number: 264 (https://leetcode.com/problems/ugly-number-ii)
Date: 18-08-2024
Description:
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.
 
Example 1:
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 
Constraints:
* 1 <= n <= 1690

Code:  */
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1l);
        unordered_set<long> vis{{1l}};
        long ans = 1;
        vector<int> f = {2, 3, 5};
        while (n--) {
            ans = q.top();
            q.pop();
            for (int& v : f) {
                long nxt = ans * v;
                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        return (int) ans;
    }
};
