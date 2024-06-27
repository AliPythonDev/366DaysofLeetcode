/* 
Day: 179
Problem Number: 1791 (https://leetcode.com/problems/find-center-of-star-graph)
Date: 27-06-2024
Description:
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

Example 1:
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.

Example 2:
Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1

Constraints:
* 3 <= n <= 10^5
* edges.length == n - 1
* edges[i].length == 2
* 1 <= ui, vi <= n
* ui != vi
* The given edges represent a valid star graph.

Code:  */
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        
        vector<int>& firstEdge = edges[0];
        vector<int>& secondEdge = edges[1];
        
        if (firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1]) {
            return firstEdge[0];
        } else {
            return firstEdge[1];
        }
    }
};
