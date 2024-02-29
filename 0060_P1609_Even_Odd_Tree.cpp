/* 
Day: 60
Problem Number: 1609 (https://leetcode.com/problems/even-odd-tree)
Date: 29-02-2024 
Description:
A binary tree is named Even-Odd if it meets the following conditions:
* The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
* For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
* For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

Example 1:
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.

Example 2:
Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.

Example 3:
Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values in the level 1 should be even integers.
 
Constraints:
* The number of nodes in the tree is in the range [1, 10^5].
* 1 <= Node.val <= 10^6

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
    bool isEvenOddTree(TreeNode* root) {
        int is_even = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int num = q.size();
            int prev_val = is_even == 1 ? 0 : INT_MAX;
                
            while (num) {
                TreeNode* cur_node = q.front();
                q.pop();
                num--;
                
                if (is_even == 1) {
                    if (cur_node->val % 2 == 0 || cur_node->val <= prev_val) {
                        return false;
                    }
                }
                else {
                    if (cur_node->val %2 == 1 || cur_node->val >= prev_val) {
                        return false;
                    }
                }
                
                prev_val = cur_node->val;
                
                if (cur_node->left) {
                    q.push(cur_node->left);
                }
                
                if (cur_node->right) {
                    q.push(cur_node->right);
                }
                
            }
            
            is_even = -is_even;
        }
        
        return true;
    }
};
