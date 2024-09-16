/*
Day: 260
Problem Number: 539 (https://leetcode.com/problems/minimum-time-difference)
Date: 16-09-2024
Description:
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 
Example 1:
Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:
Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 
Constraints:
* 2 <= timePoints.length <= 2 * 10^4
* timePoints[i] is in the format "HH:MM".

Code:  */
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) {
            return 0;
        }
        int n = timePoints.size();
        vector<int> nums(n + 1);
        for (int i = 0; i < n; ++i) {
            int hours = stoi(timePoints[i].substr(0, 2));
            int minutes = stoi(timePoints[i].substr(3, 2));
            nums[i] = hours * 60 + minutes;
        }
        sort(nums.begin(), nums.begin() + n);
        nums[n] = nums[0] + 1440;
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
