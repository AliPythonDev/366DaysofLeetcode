/*
Day: 357
Problem Number: 2940 (https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet)
Date: 22-12-2024
Description:
You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.
If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].
You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.
Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.
 
Example 1:
Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
Output: [2,5,-1,5,2]
Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2]. 
In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5]. 
In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
In the fifth query, Alice and Bob are already in the same building.  
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

Example 2:
Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
Output: [7,6,-1,4,6]
Explanation: In the first query, Alice can directly move to Bob's building since heights[0] < heights[7].
In the second query, Alice and Bob can move to building 6 since heights[3] < heights[6] and heights[5] < heights[6].
In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
In the fourth query, Alice and Bob can move to building 4 since heights[3] < heights[4] and heights[0] < heights[4].
In the fifth query, Alice can directly move to Bob's building since heights[1] < heights[6].
For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.
 
Constraints:
* 1 <= heights.length <= 5 * 10^4
* 1 <= heights[i] <= 10^9
* 1 <= queries.length <= 5 * 10^4
* queries[i] = [ai, bi]
* 0 <= ai, bi <= heights.length - 1

Code:  */
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
       vector<vector<int>> que;
        int ind = 0;
        for (auto x : queries) {
           vector<int> tmp = {max(heights[x[0]], heights[x[1]])};
            tmp.push_back(x[0]);
            tmp.push_back(x[1]);
            tmp.push_back(ind);
            que.push_back(tmp);
            ind++;
        }
        
       sort(que.begin(), que.end());
        reverse(que.begin(), que.end());

     vector<pair<int, int>> arr;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            arr.push_back({heights[i], i});
        }
    sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());

       set<int> st;
        int inf = 1000000000;
        st.insert(inf);

        int sz = queries.size();
      vector<int> ans(sz, -1);
        ind = 0;

        for (int i = 0; i < sz; i++) {
          while (ind < n && arr[ind].first > que[i][0]) {
                st.insert(arr[ind].second);
                ind++;
            }

          int mx = max(que[i][1], que[i][2]);
            int value = *st.upper_bound(mx);
            if (value == inf) value = -1;

        int a = que[i][1];
            int b = que[i][2];
            if ((a < b && heights[a] < heights[b]) || (a > b && heights[a] > heights[b])) value = max(a, b);
            if (que[i][1] == que[i][2]) value = que[i][1];
            ans[que[i][3]] = value;
        }

        return ans;
    }
};
