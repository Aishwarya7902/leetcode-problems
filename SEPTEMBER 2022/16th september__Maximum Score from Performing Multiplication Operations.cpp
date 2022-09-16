PROBLEM:  https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
LEARNING
********************************************************************************************************************************************
1. ye samjh aaya ki greedy kyu ni lagegi
At first glance, the solution seems to be greedy, but if you try to greedily take the largest value from the beginning or the end,
this will not be optimal.
  
 2. ye samjh aaya ki dp kyu lagegi
 You should try all scenarios but this will be costy.
 Memoizing the pre-visited states while trying all the possible scenarios will reduce the complexity, and hence dp is a perfect choice here.
   
 ***********************************************************************************************************************************************

/* 
RECURSIVE  (gave tle 🙄)
VIDEO:   https://www.youtube.com/watch?v=9WoHnlDit3A&t=2s
blog: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/1078881/C%2B%2B-DP-(SIMPLEST-TO-UNDERSTAND)-greater-Recursive-to-Memorisation-greater-Complete-EXPLANATION
tc:  O(2^n)
sc:
*/


#include<bits/stdc++.h>
class Solution {
public:
  int helper(vector<int>& nums, vector<int>&multipliers,int i,int j,int k ){
    int n=nums.size();
      int m=multipliers.size();
      //base case
      if(k==m)return 0;
    //induction +hypothesis
      
    int curr1=nums[i]*multipliers[k];
        
    int curr2=nums[j]*multipliers[k];
       return max(curr1+helper(nums,multipliers,i+1,j,k+1),curr2+helper(nums,multipliers,i,j-1,k+1));
         
  }
  
    int maximumScore(vector<int>& nums, vector<int>&multipliers) {
      
       return helper(nums,multipliers,0,nums.size()-1,0);
    }
};
