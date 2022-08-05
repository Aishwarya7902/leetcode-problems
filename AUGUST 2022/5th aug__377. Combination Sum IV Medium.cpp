/*
solution:  (great explaination)
https://www.linkedin.com/posts/mayank-singh-1004981a4_combination-sum-4-activity-6961153921243336704--qsI?utm_source=linkedin_share&utm_medium=member_desktop_web
problem: https://leetcode.com/problems/combination-sum-iv/
tc:
sc:


*/

class Solution {
public:
    int dp[1001];
    int helper(vector<int>& nums, int target){
        if(target==0)
            return 1;
        if(dp[target]!=-1)return dp[target];
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(target>=nums[i]){
                res+=helper(nums,target-nums[i]);
            }
        }
     return   dp[target]=res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(nums,target);
    }
};
