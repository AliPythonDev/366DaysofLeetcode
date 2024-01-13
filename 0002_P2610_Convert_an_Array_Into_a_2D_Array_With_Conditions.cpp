/*
Day: 2
Problem Number: 2610 (https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/)
Date: 02-01-2024 
Description:
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
* The 2D array should contain only the elements of the array nums.
* Each row in the 2D array contains distinct integers.
* The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.
Note that the 2D array can have a different number of elements on each row.

Code:    */
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Count the frequency of each number in the input vector
        unordered_map<int, int> frequencyMap;
        for (auto num : nums) {
            frequencyMap[num]++;
        }

        // Find the maximum frequency
        int maxFrequency = INT_MIN;
        for (auto entry : frequencyMap) {
            maxFrequency = max(entry.second, maxFrequency);
        }

        // Initialize the result matrix with empty vectors
        vector<int> emptyVector;
        vector<vector<int>> resultMatrix(maxFrequency, emptyVector);

        // Populate the result matrix with numbers based on their frequency
        for (auto &entry : frequencyMap) {
            for (int k = 0; k < entry.second; k++) {
                resultMatrix[k].push_back(entry.first);
            }
        }

        return resultMatrix;
    }
};
