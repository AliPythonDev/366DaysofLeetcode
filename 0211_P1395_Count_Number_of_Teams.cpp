/*
Day: 211
Problem Number: 1395 (https://leetcode.com/problems/count-number-of-teams)
Date: 29-07-2024
Description:
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
You have to form a team of 3 soldiers amongst them under the following rules:
* Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
* A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

Example 1:
Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 

Example 2:
Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.

Example 3:
Input: rating = [1,2,3,4]
Output: 4

Constraints:
* n == rating.length
* 3 <= n <= 1000
* 1 <= rating[i] <= 10^5
* All the integers in rating are unique.

Code:  */
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = 0;
            for (int j = 0; j < i; ++j) {
                if (rating[j] < rating[i]) {
                    ++l;
                }
            }
            for (int j = i + 1; j < n; ++j) {
                if (rating[j] > rating[i]) {
                    ++r;
                }
            }
            ans += l * r;
            ans += (i - l) * (n - i - 1 - r);
        }
        return ans;
    }
};
