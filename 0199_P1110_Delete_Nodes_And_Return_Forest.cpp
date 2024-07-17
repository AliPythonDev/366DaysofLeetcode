/* 
Day: 199
Problem Number: 1110 (https://leetcode.com/problems/delete-nodes-and-return-forest)
Date: 17-07-2024
Description:
Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
Return the roots of the trees in the remaining forest. You may return the result in any order.

Example 1:
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:
Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]

Constraints:
* The number of nodes in the given tree is at most 1000.
* Each node has a distinct value between 1 and 1000.
* to_delete.length <= 1000
* to_delete contains distinct values between 1 and 1000.

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
private:
    bool set[1001] = {};
    void dfs(TreeNode* &root, bool flag, vector<TreeNode*>& res){
        if (root == nullptr) return;
        dfs(root->left, set[root->val], res);
        dfs(root->right, set[root->val], res);
        if (!set[root->val] && flag) res.push_back(root);
        if (set[root->val]) root = nullptr;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        for (int num : to_delete)
            set[num] = true;
        dfs(root, true, res);
        return res;
    }
};
