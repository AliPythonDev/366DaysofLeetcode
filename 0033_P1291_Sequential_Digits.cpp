/* 
Day: 33
Problem Number: 1291 (https://leetcode.com/problems/sequential-digits)
Date: 02-02-2024 
Description:
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123, 234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234, 2345, 3456, 4567, 5678, 6789, 12345]
 
Constraints:
* 10 <= low <= high <= 10^9

Code:  */
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i < 9; ++i) {
            int x = i;
            for (int j = i + 1; j < 10; ++j) {
                x = x * 10 + j;
                if (x >= low && x <= high) {
                    ans.push_back(x);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
