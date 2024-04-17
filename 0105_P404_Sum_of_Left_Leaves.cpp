/* 
Day: 105
Problem Number: 404 (https://leetcode.com/problems/sum-of-left-leaves)
Date: 14-04-2024
Description:
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0

Constraints:
* The number of nodes in the tree is in the range [1, 1000].
* -1000 <= Node.val <= 1000

Code:  */
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr)
      return 0;

    int ans = 0;

    if (root->left) {
      if (root->left->left == nullptr && root->left->right == nullptr)
        ans += root->left->val;
      else
        ans += sumOfLeftLeaves(root->left);
    }
    ans += sumOfLeftLeaves(root->right);

    return ans;
  }
};
