PROBLEM: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
video:

/*
MY INITIAL APPROACH (it gave TLE 😥😣)
pseudo code:
1.generate all possible paths from root to leaf
2.for every possible path generate possible permutation....and for every permutation check if it is a palindrome or not....if any of the permutation of a 
path is palindrome cnt++;
3.return cnt;
*/
class Solution {
public:
    bool isPalind(vector<int>&v){
        int i=0,j=v.size()-1;
        while(i<=j){
            if(v[i]!=v[j])return false;
        }
        return true;
    }
//FUNCTION TO GENERATE ALL POSSIBLE PERMUTATIONS
void recurHelp(vector<int>&curr,vector<vector<int>>&ans,vector<int>&ds,int freq[]){
	    if(ds.size()==curr.size()){
	       ans.push_back(ds);
	        return;
	    }
	    for(int i=0;i<curr.size();i++){
	        if(!freq[i]){
	            ds.push_back(curr[i]);
	            freq[i]=1;
	            recurHelp(curr,ans,ds,freq);
	            freq[i]=0;
	            ds.pop_back();
	        }
	    }
	}
    vector<vector<int>> find_permutation(vector<int>&curr)
		{
		    // Code here there
		   vector<vector<int>> ans;
		    vector<int> ds;
		    int freq[curr.size()];
		    for(int i=0;i<curr.size();i++){
		        freq[i]=0;
		    }
		    recurHelp(curr,ans,ds,freq);
		    
		    return ans;
		}
bool isPalindrome(vector<int>curr){
    vector<vector<int>>ans=find_permutation(curr);
    for(int i=0;i<ans.size();i++){
        vector<int>v=ans[i];
        if(isPalind(v)){
            return true;
            break;
        }
    }
    return false;
}
//FUNCTION TO GENERATE ALL POSSIBLE PATHS FROM ROOT TO LEAF
    void helper(TreeNode* root,vector<int>&curr,vector<vector<int>>&ans){
    if(!root)return ;
    curr.push_back(root->val);
    if(!root->left && !root->right){
        ans.push_back(curr);
        curr.clear();
        return;
    }
    helper(root->left,curr,ans);
    helper(root->right,curr,ans);
}
vector<vector<int>> Paths(TreeNode* root)
{
    // Code here
    vector<vector<int>>ans;
    if(!root)return ans;
    vector<int>curr;
    helper(root,curr,ans);
    return ans;
    
}
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt=0;
      vector<vector<int>>PossiblePath=Paths(root);
      for(int i=0;i<PossiblePath.size();i++){
          vector<int>curr=PossiblePath[i];
          if(isPalindrome(curr))cnt++;
      }
        return cnt;
    }
};
