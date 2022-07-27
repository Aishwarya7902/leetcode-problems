PROBLEM:https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
video soln: https://www.youtube.com/watch?v=sWf7k1x9XR4&t=603s

/*APPROACH 1
tc:o(n)
sc:o(n) (for recursive call stack)
*/

class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
      
       if(!root)
           return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};
