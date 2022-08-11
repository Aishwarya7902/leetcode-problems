/* INITIAL:
PROBLEM: https://leetcode.com/problems/validate-binary-search-tree/
VIDEO:https://www.youtube.com/watch?v=f-sj7I5oXEI (STRIVER BHAIYA)
TC:O(N)
  SC:O(1)....IT WILL TAKE O(N) AUXILIARY STACK SPACE
  Note we use LONG_MIN and LONG_MAX to handle edge cases like [INT_MAX].
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
  
/*METHOD 2: FASTER
SINCE INORDER TRAVERSAL OF BST WILL BE IN ASCENDING ORDER ...SO WE CAN USE THIS VERY CLEVERLY TO SOLVE THIS PROBLEM
TC: O(N)
SC: O(N)
*/

class Solution {
public:
    vector<int> res; // to store inorder order traversal
    void solve(TreeNode* root) {
        if(root == NULL) return; // Base Condition
        solve(root->left); // Left subtree
        res.push_back(root->val); // Keep pushing elements in in-order manner
        solve(root->right); // Right subtree
    }
    bool isValidBST(TreeNode* root) {   
        solve(root); // fill the vector in in-order manner
        for(int i=1; i<res.size(); i++) {
            if(res[i] <= res[i-1]) // If this occurs, BST condition violates
                return false; // Not a valid BST
        }
        return true; // All fine if u reached here, BST is valid
    }
};
