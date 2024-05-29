/* 
Day: 150
Problem Number: 1404 (https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one)
Date: 29-05-2024
Description:
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
* If the current number is even, you have to divide it by 2.
* If the current number is odd, you have to add 1 to it.
It is guaranteed that you can always reach one for all test cases.
 
Example 1:
Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  

Example 2:
Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  

Example 3:
Input: s = "1"
Output: 0
 
Constraints:
* 1 <= s.length <= 500
* s consists of characters '0' or '1'
* s[0] == '1'

Code:  */
class Solution {
public:
    int numSteps(string s) {
        int l = s.length() - 1;
        int carry = 0;
        int count = 0;
        
        while (l > 0) {
            // even number with carry = 0, result even
            if (s[l] - '0' + carry == 0) {
                carry = 0;
                count++;
            // odd number with carry = 1, result even
            } else if (s[l] - '0' + carry == 2) {
                carry = 1;
                count++;
            // even number with carry = 1, result odd
            // odd number with carry = 0, result odd
            } else {
                carry = 1;
                count += 2;
            }
            l--;
        }
        
        // last digit 1 needs to add a carried over digit 1, which gives 10.
        // So need one more divide to make it 1 (one more step)
        if (carry == 1) {
            count++;
        }
        
        return count;
    }
};
