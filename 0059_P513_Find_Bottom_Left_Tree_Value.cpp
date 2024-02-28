/* 
Day: 59
Problem Number: 513 (https://leetcode.com/problems/find-bottom-left-tree-value)
Date: 28-02-2024 
Description:
Given the root of a binary tree, return the leftmost value in the last row of the tree.
 
Example 1:
Input: root = [2,1,3]
Output: 1

Example 2:
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
 
Constraints:
* The number of nodes in the tree is in the range [1, 104].
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int ans = 0;
        while (!q.empty()) {
            ans = q.front()->val;
            for (int i = q.size(); i; --i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};
