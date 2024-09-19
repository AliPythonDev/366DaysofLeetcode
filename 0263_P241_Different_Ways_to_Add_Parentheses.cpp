/*
Day: 263
Problem Number: 241 (https://leetcode.com/problems/different-ways-to-add-parentheses)
Date: 19-09-2024
Description:
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
 
Example 1:
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 
Constraints:
* 1 <= expression.length <= 20
* expression consists of digits and the operator '+', '-', and '*'.
* All the integer values in the input expression are in the range [0, 99].

Code:  */
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }

    vector<int> dfs(string exp) {
        if (memo.count(exp)) return memo[exp];
        if (exp.size() < 3) return {stoi(exp)};
        vector<int> ans;
        int n = exp.size();
        for (int i = 0; i < n; ++i) {
            char c = exp[i];
            if (c == '-' || c == '+' || c == '*') {
                vector<int> left = dfs(exp.substr(0, i));
                vector<int> right = dfs(exp.substr(i + 1, n - i - 1));
                for (int& a : left) {
                    for (int& b : right) {
                        if (c == '-')
                            ans.push_back(a - b);
                        else if (c == '+')
                            ans.push_back(a + b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }
        memo[exp] = ans;
        return ans;
    }

private:
    unordered_map<string, vector<int>> memo;
};
