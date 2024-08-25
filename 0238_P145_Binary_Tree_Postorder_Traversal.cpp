/*
Day: 238
Problem Number: 145 (https://leetcode.com/problems/binary-tree-postorder-traversal)
Date: 25-08-2024
Description:
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
 
Constraints:
* The number of the nodes in the tree is in the range [0, 100].
* -100 <= Node.val <= 100
 
Follow up: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            dfs(root->right);
            ans.push_back(root->val);
        };
        dfs(root);
        return ans;
    }
};
