/* 
Day: 8
Problem Number: 938 (https://leetcode.com/problems/range-sum-of-bst)
Date: 08-01-2024 
Description:
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

Code:  */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return 0 ;
        
        if(root->val >= low  &&  root->val <= high){
            return root->val + rangeSumBST(root->left ,low ,high) +rangeSumBST(root->right ,low ,high) ;
        }
        
        else if(root->val > low){
            return rangeSumBST(root->left ,low ,high) ;
        }
        else{
            return rangeSumBST(root->right ,low ,high) ;
        }
    }
};
