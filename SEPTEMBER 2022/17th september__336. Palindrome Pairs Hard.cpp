PROBLEM:https://leetcode.com/problems/palindrome-pairs/
/*
MY INITIAL INTUTION (BUT GIVES TLE 😢🙄)
1.run outer loop i from 0 till n-1
2.run outer loop j from 0 till n-1
3. if(s[i]+s[j]) is a palindrome then push i,j in ans vector

WHY THIS GAVE TLE 🤔🤔🤔🤔🤔🤔🤔🤔...LET'S FIND IT OUT
coz :
tc: O(n^3)
sc: O(1) except the vector asked in return
*/

class Solution {
public:
  bool isPalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<=j){
      if(s[i]!=s[j]){
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
    vector<vector<int>> palindromePairs(vector<string>& words) {
     vector<vector<int>>ans;
      int n=words.size();
      for(int i=0;i<n;i++){
        
        for(int j=0;j<n;j++){
          if(i==j)continue;
          string s=words[i];
          s+=words[j];
          if(isPalindrome(s)){
            
            ans.push_back({i,j});
          }
        }
      }
      return ans;
    }
};
