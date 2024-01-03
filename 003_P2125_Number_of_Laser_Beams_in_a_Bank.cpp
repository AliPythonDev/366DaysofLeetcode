/* 
Day: 3
Problem Number: 2125 (https://leetcode.com/problems/number-of-laser-beams-in-a-bank/)
Date: 03-01-2024 
Description:
Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.
There is one laser beam between any two security devices if both conditions are met:
* The two devices are located on two different rows: r1 and r2, where r1 < r2.
* For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.
Return the total number of laser beams in the bank.

Code:  */
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prevDeviceCount = 0;
        int result    = 0;
        for(int i = 0; i<n; i++) {
            int currDeviceCount = 0;
            for(char &ch : bank[i]) {
                if(ch == '1') {
                    currDeviceCount++;
                }
            }  
            result += (prevDeviceCount * currDeviceCount);
            
            prevDeviceCount = currDeviceCount == 0 ? prevDeviceCount : currDeviceCount;     
        }  
        return result;
    }
};
