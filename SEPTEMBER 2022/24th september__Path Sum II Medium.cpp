PROBLEM: https://leetcode.com/problems/path-sum-ii/

/* 
MY APPROACH
to dekho is question ko solve karne se pahle niche given question ko solve kar ke aao fir ye question bilkul aasani se ho jayega
MOST IMPORTANT THING IS DRY RUN KARNA....BHAI DRY RUN JARUR KARO HAR QUESTION ME SABKUCH CLEAR HO JATA HAI YAR✌✌✌✌🙌

prerequisite problem: https://leetcode.com/problems/path-sum/
video explanation: https://www.youtube.com/watch?v=Hg82DzMemMI

**************************************************************

now lets come back to original question
pseudo code:
1.make a 2d ans vector
2.make a curr vector
3.if root is null simply return
4.add root val to sum
5.if(sum==targetSum) and if it is a leaf node then add curr vector to ans vector
6.call left
7.call right
8.now backtrack .ie remove root->val from sum as well as remove it from curr vector
9.return ans
tc: O(n)
sc: O(1)
video:  https://www.youtube.com/watch?v=f0T9sNWkBZA
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
