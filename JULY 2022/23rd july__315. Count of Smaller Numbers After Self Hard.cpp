/*
PROBLEM:https://leetcode.com/problems/count-of-smaller-numbers-after-self/
brute force: (GOT TLE 😐)
TC:O(N*N)
SC:O(1)
pseudo code:
1.create a vector
2.take ith elmennt and set cnt=0..now traverse elements from i+1th element...if it is smaller cnt++ ....after inner for loop push cnt in vector ...basically it denotes
no of elements which are smaller than ith element....repeat this step for other elements of the vector...return ans.

*/
vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for (int j=i+1;j<nums.size();j++){
                if(nums[i]>nums[j])
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
