PROBLEM:https://leetcode.com/problems/valid-anagram/

/* MY INITIAL APPROACH
1.since anagram means words ko jumble karne pe jo aaye....bachpan me to khela hi hoga ...jumble the word
2.if size of both strings is diff tab to pakka dono anagram ni hai ...coz jumble karne pe size badal thodi na jayega..HENCE COUNT OF CHARACTERS MUST BE SAME
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

/*A BETTER APPROACH
tc:O(n)
sc:O(n)
PSEUDO CODE:
This idea uses a hash table to record the times of appearances of each letter in the two strings s and t. For each letter in s, it increases the counter by 1
while for each letter in t, it decreases the counter by 1. Finally, all the counters will be 0 if they two are anagrams of each other.

*/

#include<map>
class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size()!=t.size())
          return false;
      unordered_map<char,int>ms;
      
        for(auto x:s){
            ms[x]++;
        }
        
        for(auto i:t){
            ms[i]--;
        }
        
        for(auto it:ms){
           if(it.second)return false; 
        }
           
        
        
     return true;   
    }
};

/*APPROACH 3 (MOST OPTIMISED)
TC:O(N)
SC:O(1)
PSEUDO CODE:
Since the problem statement says that "the string contains only lowercase alphabets", we can simply use an array to simulate the unordered_map and speed up the code.
*/

#include<map>
class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size()!=t.size())
          return false;
      int count[26]={0};
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(auto x:count){
            if(x)
                return false;
        }
        return true;
    }
};


/*APPROACH 4 (NOT A GD ONE.....ITS A BRUTE FORCE
TC:O(nlogn)
sc:O(1)
pseudo code:
sort both the strings ...return true if they are equal
*/


#include<map>
class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size()!=t.size())
          return false;
      sort(s.begin(),s.end());
      sort(t.begin(),t.end());
        return s==t;
    }
};

*/





