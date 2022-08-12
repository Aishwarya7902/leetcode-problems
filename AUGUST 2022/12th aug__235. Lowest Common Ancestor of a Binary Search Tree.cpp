PROBLEM:https:leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/*THIS CAN BE SOLVED IN THE SAME WAY AS WE SOLVED
236. Lowest Common Ancestor of a Binary Tree :https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
TC: o(N)
SC: auxiliary stack space of O(n)
*/
  
  class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
      if(root->val==p->val || root->val==q->val){
          return root;
      }  
      TreeNode* left=lowestCommonAncestor(root->left,p,q);
      TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(!left)
            return right;
        if(!right)return left;
        
         
    return root;
    }
};

/*OPTIMAL SOLUTION:
TC: O(height)
SC: O(1) if we don't consider the auxiliary stack space.
VIDEO: https://www.youtube.com/watch?v=cX_kPV_foZc
PSEUDO CODE:
SINCE IT IS A BST IT MEANS EVERYTHING ON THE LEFT OF ROOT SHOULD BE SMALLER THAN ROOT AND EVERTHING ON THE RIGHT OF ROOT SHOULD BE GREATER THAN ROOT
1.agr root ki val p.val and q.val dono se choti hai ..it means lca kahin na kahin right side me lie karega ..hence call recursion over right
2.agr root ki val p.val and q.val dono se badi hai ..it means lca kahin na kahin left side me lie karega ..hence call recursion over left

3.if none of the above two conditions are true it means...surely either ....root lies in mid of p and q in this case root will be the lca (feel karo❤)
..hence we return root.
.....or  root's value will be equal to either of p or q..in this case also ...return root.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
      int curr=root->val;
        if(curr<p->val && curr<q->val)
            return lowestCommonAncestor(root->right,p,q);
        else if(curr>p->val && curr>q->val)
            return lowestCommonAncestor(root->left,p,q);
        
         
    return root;
    }
};
