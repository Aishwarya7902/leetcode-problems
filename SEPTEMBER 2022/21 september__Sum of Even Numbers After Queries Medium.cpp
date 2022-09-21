PROBLEM:https://leetcode.com/problems/sum-of-even-numbers-after-queries/
/*
initial approach (gave tle 🙄)
pseudo code:
1.traverse in queries array....now at this index....there are two values first is val and second is ind....now what we have to do is....go to the ind index of
nums and add val to it.....now the nums array is updated....now traverse the nums and take a sum variable with u....if at any index in nums value is 
divisible by 2 add it to sum ...after u traverse the whole nums array....u will get sum....store it in an ans vector
2.return ans
tc: O(m*n)
m=size of queries
n=size of nums
sc: size of nums
*/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
      int m=queries.size();
      for(int i=0;i<m;i++){
        int val=queries[i][0];
        int ind=queries[i][1];
        nums[ind]+=val;
        int sum=0;
        for(int x:nums){
          if(x%2==0){
            sum+=x;
          }
        }
        ans.push_back(sum);
      }
      return ans;
    }
};

/*
OPTIMISATION
VIDEO: https://www.youtube.com/watch?v=WLdFNdRnXl8
pseudo code:
1.maintain a sum variable
2.traverse nums if value at that index is divisible by 2 store it in sum
3.now traverse query
4.go the ind index and if it is divisible by 2 remove from sum...now add val to nums[ind] .....after adding val if nums[ind] is divisible by two ...
add it to sum...now add sum to ans vector
tc: O(m) + O(n)
sc: O(1)
*/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      int sum=0;
        for(int x:nums){
          if(x%2==0){
            sum+=x;
          }
        }
        vector<int>ans;
      int m=queries.size();
      for(int i=0;i<m;i++){
        int val=queries[i][0];
        int ind=queries[i][1];
        if(nums[ind]%2==0){
          sum-=nums[ind];
        }
        nums[ind]+=val;
        
        if(nums[ind]%2==0){
          sum+=nums[ind];
        }
        ans.push_back(sum);
      }
      return ans;
    }
};
