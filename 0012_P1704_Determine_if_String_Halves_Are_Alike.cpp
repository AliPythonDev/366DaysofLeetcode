/* 
Day: 12
Problem Number: 1704 (https://leetcode.com/problems/determine-if-string-halves-are-alike)
Date: 12-01-2024 
Description:
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
Return true if a and b are alike. Otherwise, return false.

Code:  */
class Solution {
private: 
    bool isVowel(char &c){
        return c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';        
    }
public:
    bool halvesAreAlike(string s) {
        int vowelDiff = 0, mid=size(s)/2;
        for(int i=0;i<mid;i++) vowelDiff += isVowel(s[i]) - isVowel(s[mid+i]);// vowels difference b/w 1st & 2nd half
        return vowelDiff == 0;
    }
};
