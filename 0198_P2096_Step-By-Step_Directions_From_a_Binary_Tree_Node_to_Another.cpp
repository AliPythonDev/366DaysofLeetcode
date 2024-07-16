/* 
Day: 198
Problem Number: 2096 (https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another)
Date: 16-07-2024
Description:
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
* 'L' means to go from a node to its left child node.
* 'R' means to go from a node to its right child node.
* 'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

Example 1:
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.

Example 2:
Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.

Constraints:
* The number of nodes in the tree is n.
* 2 <= n <= 10^5
* 1 <= Node.val <= n
* All the values in the tree are unique.
* 1 <= startValue, destValue <= n
* startValue != destValue

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* node = lca(root, startValue, destValue);
        string pathToStart, pathToDest;
        dfs(node, startValue, pathToStart);
        dfs(node, destValue, pathToDest);
        return string(pathToStart.size(), 'U') + pathToDest;
    }

private:
    TreeNode* lca(TreeNode* node, int p, int q) {
        if (node == nullptr || node->val == p || node->val == q) {
            return node;
        }
        TreeNode* left = lca(node->left, p, q);
        TreeNode* right = lca(node->right, p, q);
        if (left != nullptr && right != nullptr) {
            return node;
        }
        return left != nullptr ? left : right;
    }

    bool dfs(TreeNode* node, int x, string& path) {
        if (node == nullptr) {
            return false;
        }
        if (node->val == x) {
            return true;
        }
        path.push_back('L');
        if (dfs(node->left, x, path)) {
            return true;
        }
        path.back() = 'R';
        if (dfs(node->right, x, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
};
