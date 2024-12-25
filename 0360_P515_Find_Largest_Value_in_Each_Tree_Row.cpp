/*
Day: 360
Problem Number: 515 (https://leetcode.com/problems/find-largest-value-in-each-tree-row)
Date: 25-12-2024
Description:
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]
 
Constraints:
* The number of nodes in the tree will be in the range [0, 10^4].
* -2^31 <= Node.val <= 2^31 - 1

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int L = q.size();
            int M = INT_MIN;
            
            for (int i = 0; i < L; i++) {
                TreeNode* x = q.front();
                q.pop();
                
                M = max(M, x->val);
                
                if (x->left != nullptr) {
                    q.push(x->left);
                }
                if (x->right != nullptr) {
                    q.push(x->right);
                }
            }
            
            ans.push_back(M);
        }
        
        return ans;
    }
};
