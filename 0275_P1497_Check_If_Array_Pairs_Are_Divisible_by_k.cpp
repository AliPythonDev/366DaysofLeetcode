/*
Day: 275
Problem Number: 1497 (https://leetcode.com/problems/design-a-stack-with-increment-operation)
Date: 01-10-2024
Description:
Given an array of integers arr of even length n and an integer k.
We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
Return true If you can find a way to do that or false otherwise.
 
Example 1:
Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).

Example 2:
Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).

Example 3:
Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
 
Constraints:
* arr.length == n
* 1 <= n <= 10^5
* n is even.
* -10^9 <= arr[i] <= 10^9
* 1 <= k <= 10^5

Code:  */
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k);
        for (int& x : arr) {
            ++cnt[((x % k) + k) % k];
        }
        for (int i = 1; i < k; ++i) {
            if (cnt[i] != cnt[k - i]) {
                return false;
            }
        }
        return cnt[0] % 2 == 0;
    }
};
