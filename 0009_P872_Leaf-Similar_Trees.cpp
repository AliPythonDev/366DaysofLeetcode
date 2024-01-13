/* 
Day: 9
Problem Number: 872 (https://leetcode.com/problems/leaf-similar-trees)
Date: 09-01-2024 
Description:
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string t1,t2;
        //DFS for tree1
        DFS(root1,t1);
        //DFS for tree2
        DFS(root2,t2);
        //If both are same return true
        return t1==t2;
    }
    void DFS(TreeNode* root, string& s){
        if(root == NULL) return ;
        if(root->left==NULL && root->right == NULL) s+=to_string(root->val)+'#';
        DFS(root->left,s);
        DFS(root->right,s);
    }
};
