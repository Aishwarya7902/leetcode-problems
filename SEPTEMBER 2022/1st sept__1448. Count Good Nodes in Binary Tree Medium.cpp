PROBLEM:https://leetcode.com/problems/count-good-nodes-in-binary-tree/

TC:O(N)
SC:O(1)
  
  class Solution {
public:
    void helper(TreeNode* root,int &ans,int value){
        if(!root)return;
        if(root->val>=value)
        {
            ans++;
            value=root->val;
        }
        if(root->left)
            helper(root->left,ans,value);
        if(root->right)
            helper(root->right,ans,value);
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        helper(root,ans,INT_MIN);
        return ans;
    }
};
