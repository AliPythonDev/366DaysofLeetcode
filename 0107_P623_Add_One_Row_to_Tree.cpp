/* 
Day: 107
Problem Number: 623 (https://leetcode.com/problems/add-one-row-to-tree)
Date: 16-04-2024
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.
Note that the root node is at depth 1.
The adding rule is:
* Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
* cur's original left subtree should be the left subtree of the new left subtree root.
* cur's original right subtree should be the right subtree of the new right subtree root.
* If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.

Example 1:
Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]

Example 2:
Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]

Constraints:
* The number of nodes in the tree is in the range [1, 10^4].
* The depth of the tree is in the range [1, 10^4].
* -100 <= Node.val <= 100
* -10^5 <= val <= 10^5
* 1 <= depth <= the depth of tree + 1

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
    int val;
    int depth;

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        this->val = val;
        this->depth = depth;
        dfs(root, 1);
        return root;
    }

    void dfs(TreeNode* root, int d) {
        if (!root) return;
        if (d == depth - 1) {
            auto l = new TreeNode(val, root->left, nullptr);
            auto r = new TreeNode(val, nullptr, root->right);
            root->left = l;
            root->right = r;
            return;
        }
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
};
