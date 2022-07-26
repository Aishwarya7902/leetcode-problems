problem:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
blog:https://www.linkedin.com/posts/mayank-singh-1004981a4_lca-in-a-binary-tree-activity-6957524275587092480-HuLG?utm_source=linkedin_share&utm_medium=member_desktop_web
best explaination (STRIVER BHAIYA): https://www.youtube.com/watch?v=_-QHfMDde90
/*
brute force:
tc:O(n)
sc:O(n) auxiliary space for recursion
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(!root) 
             return root;
        if(root->val==p->val || root->val==q->val)
            return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(!left)
            return right;
        if(!right)
            return left;
        return root;
    }
};
