/* 
Day: 197
Problem Number: 2196 (https://leetcode.com/problems/create-binary-tree-from-descriptions)
Date: 15-07-2024
Description:
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,
* If isLefti == 1, then childi is the left child of parenti.
* If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.
The test cases will be generated such that the binary tree is valid.

Example 1:
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.

Example 2:
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.

Constraints:
* 1 <= descriptions.length <= 10^4
* descriptions[i].length == 3
* 1 <= parenti, childi <= 10^5
* 0 <= isLefti <= 1
* The binary tree described by descriptions is valid.

Code:  */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> vis;
        for (auto& d : descriptions) {
            int p = d[0], c = d[1], left = d[2];
            if (!m.count(p)) m[p] = new TreeNode(p);
            if (!m.count(c)) m[c] = new TreeNode(c);
            if (left)
                m[p]->left = m[c];
            else
                m[p]->right = m[c];
            vis.insert(c);
        }
        for (auto& [v, node] : m) {
            if (!vis.count(v)) return node;
        }
        return nullptr;
    }
};
