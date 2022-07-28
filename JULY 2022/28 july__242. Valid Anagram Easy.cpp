PROBLEM:https://leetcode.com/problems/valid-anagram/

/* MY INITIAL APPROACH
1.since anagram means words ko jumble karne pe jo aaye....bachpan me to khela hi hoga ...jumble the word
2.if size of both strings is diff tab to pakka dono anagram ni hai ...coz jumble karne pe size badal thodi na jayega
3.now store both the frequency of each char in map .....for both strings differently
4.if size of these maps are diff then return false...coz size kam hai matlab isme jitne characters hain utne dusre string me ni hai.
5.check if frequency of each character in both maps is eqaual or not
dekho idea simple hai 
lets say we have s="rat" and t="tar"  ....now rat ko jumble karne pe tar aa jayega hence anagram hai .....jumble karne har ek character ki frequency utni hi hogi
jitni jumble karne se pahle thi.


tc:O(n*n)
sc:O(n)
*/

#include<map>
class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size()!=t.size())
          return false;
      unordered_map<char,int>ms;
      unordered_map<char,int>mt;
        for(auto x:s){
            ms[x]++;
        }
        for(auto x:t){
            mt[x]++;
        }
        if(ms.size()!=mt.size())
            return false;
        for(auto it:ms){
            if(mt.find(it.first)==mt.end())
                return false;
            if(mt[it.first]!=it.second)
                return false;
        }
     return true;   
    }
};
