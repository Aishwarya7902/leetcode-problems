/* INITIAL:
PROBLEM: https://leetcode.com/problems/validate-binary-search-tree/
VIDEO:https://www.youtube.com/watch?v=f-sj7I5oXEI (STRIVER BHAIYA)
TC:O(N)
  SC:O(1)....IT WILL TAKE O(N) AUXILIARY STACK SPACE
  
  */
#include<bits/stdc++.h>
class Solution {
public:
    bool helper(TreeNode* root,long low,long high){
        if(!root)return true;
         if(root->val<=low || root->val>=high)return false;
        return helper(root->left,low,root->val) && helper(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
    return helper(root,LONG_MIN,LONG_MAX);
    }
};
  
