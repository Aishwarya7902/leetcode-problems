/*VIDEO EXPLAINATION:   https://www.youtube.com/watch?v=zr_AoTxzn0Y
PROBLEM:https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/


//tc:O(logn)
//sc:O(1)
class Solution {
public:
    int LastIndex(vector<int>& nums, int target){
        int low=0;
        int hi=nums.size()-1;
        int res=-1;
        while(low<=hi){
            int mid=low+(hi-low)/2;
            if(nums[mid]==target)
            {
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return res;
    }
    int FirstIndex(vector<int>& nums, int target){
        int low=0;
        int hi=nums.size()-1;
        int res=-1;
        while(low<=hi){
            int mid=low+(hi-low)/2;
            if(nums[mid]==target)
            {
                res=mid;
                hi=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int>ans(2);
      int first=FirstIndex(nums,target);
      int last=LastIndex(nums,target);
        ans[0]=first;
        ans[1]=last;
        return ans;
    }
};
