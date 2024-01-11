/* 
Day: 11
Problem Number: 1026 (https://leetcode.com/problems/maximum-difference-between-node-and-ancestor)
Date: 11-01-2024 
Description:
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Code:  */
/*
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
    int maxAncestorDiff(TreeNode* root, int mini = INT_MAX, int maxi = INT_MIN) {
        // base case i.e., leaves, return the max-min along the path
        if (!root) return (maxi - mini);
        // update mini and maxi
        mini = min(mini, root->val), maxi = max(maxi, root->val);
        // finding the maximum distance we would like to find by going left and right
        return max(maxAncestorDiff(root->left, mini, maxi), maxAncestorDiff(root->right, mini, maxi));
    }
};
