/*
Day: 327
Problem Number: 1072 (https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows)
Date: 22-11-2024
Description:
You are given an m x n binary matrix matrix.
You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
Return the maximum number of rows that have all values equal after some number of flips.
 
Example 1:
Input: matrix = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.

Example 2:
Input: matrix = [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.

Example 3:
Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.
 
Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 300
* matrix[i][j] is either 0 or 1.

Code:  */
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        unordered_map<string, int> patFreq;
        
        for (const auto& row : mat) {
            string pattern;
            if (row[0] == 0) {
                for (int bit : row) pattern += to_string(bit);
            } else {
                for (int bit : row) pattern += to_string(bit ^ 1);
            }
            patFreq[pattern]++;
        }
        
        int maxFreq = 0;
        for (const auto& pair : patFreq) {
            maxFreq = max(maxFreq, pair.second);
        }
        return maxFreq;
    }
};
