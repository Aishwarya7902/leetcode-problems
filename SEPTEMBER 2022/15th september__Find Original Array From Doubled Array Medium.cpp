PROBLEM: https://leetcode.com/problems/find-original-array-from-doubled-array/
VIDEO: https://www.youtube.com/watch?v=5dKFjNEgIjA&t=300s
TC: O(nlogn)
SC: O(n)
  
  
  class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        if(changed.size()%2)return ans;
        
      
      unordered_map<int,int>mp;
      for(auto x:changed){
        mp[x]++;
      }
      sort(changed.begin(),changed.end());
      for(auto x:changed){
        if(mp[x]==0)
          continue;
        if(mp[2*x]==0)
          return {};
        if(mp[x] && mp[2*x])
          
        {
          ans.push_back(x);
          mp[x]--;
          mp[2*x]--;
        }
      }
      return ans;
    }
};
