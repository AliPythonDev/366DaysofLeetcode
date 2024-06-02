/* 
Day: 154
Problem Number: 344 (https://leetcode.com/problems/reverse-string)
Date: 02-06-2024
Description:
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
 
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 
Constraints:
* 1 <= s.length <= 10^5
* s[i] is a printable ascii character.

Code:  */
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
    }

private:
    void reverse(vector<char>& s, int left, int right) {
        if (left >= right) return;
        swap(s[left], s[right]);
        reverse(s, left + 1, right - 1);
    }
};
