/* 
Day: 15
Problem Number: 2225 (https://leetcode.com/problems/find-players-with-zero-or-one-losses)
Date: 15-01-2024 
Description:
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.
Return a list answer of size 2 where:
* answer[0] is a list of all players that have not lost any matches.
* answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.
Note:
* You should only consider the players that have played at least one match.
* The testcases will be generated such that no two matches will have the same outcome.
 
Code:  */
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> cnt;
        for (auto& m : matches) {
            int a = m[0], b = m[1];
            if (!cnt.count(a)) cnt[a] = 0;
            ++cnt[b];
        }
        vector<vector<int>> ans(2);
        for (auto& [u, v] : cnt) {
            if (v < 2) ans[v].push_back(u);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
