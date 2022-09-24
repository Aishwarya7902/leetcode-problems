PROBLEM: https://leetcode.com/problems/path-sum-ii/

/* 
MY APPROACH
to dekho is question ko solve karne se pahle niche given question ko solve kar ke aao fir ye question bilkul aasani se ho jayega
MOST IMPORTANT THING IS DRY KARNA....BHAI DRY JARUR KARO HAR QUESTION ME SABKUCH CLEAR HO JATA HAI YAR✌✌✌✌🙌

prerequisite problem: https://leetcode.com/problems/path-sum/
video explanation: https://www.youtube.com/watch?v=Hg82DzMemMI

**************************************************************

now lets come back to original question
pseudo code:
1.make a 2d ans vector
2.make a curr vector
3.if root is null simply return
4.
tc:
sc:
video:
blog:
*/
class Solution {
private:
  void helper(TreeNode* root,int &sum ,int targetSum,vector<int>&curr,vector<vector<int>>&ans)
  {
    if(root==NULL)return;
    sum+=root->val;
    curr.push_back(root->val);
    if(sum==targetSum && !root->left && !root->right){
      ans.push_back(curr);
      
      
    }
    helper(root->left,sum,targetSum,curr,ans);
    helper(root->right,sum,targetSum,curr,ans);
    sum-=root->val;
    curr.pop_back();
  }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
      int sum=0;
      helper(root,sum,targetSum,curr,ans);
      return ans;
    }
};
