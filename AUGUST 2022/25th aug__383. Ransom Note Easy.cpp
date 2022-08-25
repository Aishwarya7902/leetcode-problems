PROBLEM:https://leetcode.com/problems/ransom-note/
/*
MY SILLY MISTAKE: I UNDERSTOOD THE QUESTION WRONG...MAINE SOCHA KI CHECK KARNA HAI KI ransomNote ..maganzine ka substring hai ki ni..agr ransomNote ..magazine ka substring hai 
to return true..else return false.........BUT BUT BUT I WAS TOTALY WRONG...what we had to in this question is to that we have to check if ransomNote can be made out of
magazine or not......to iska matlab ye hua ki ...... count of each word in ransomNote niklenge...and we will check ki us character ke corresponding magazine me uska count 
either same or greater hai ki ni ...agr han to after traversing the map corresponding to ransomNote ..we can return true...after coming out of loop if we have not returned
ture ye..then return false

tc:o(size of bigger of magazine...coz it is big or equal to ransomNote)
sc:o(size of bigger of magazine...coz it is big or equal to ransomNote)
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char,int>small;
      unordered_map<char,int>big;
        for(auto x:ransomNote){
            small[x]++;
        }
         for(auto x:magazine){
            big[x]++;
        }
        for(auto it:small){
            if(big.find(it.first)==big.end())return false;
            if(big[it.first]<small[it.first])return false;
        }
     return true;
        
    }
};

/*approach 2:
tc: time is O(m + n) where m and n are the length of both strings 
...time is O(m+n) because we are iterating over both the string one time only

sc: O(size of magazine)
video:
blog: https://leetcode.com/problems/ransom-note/discuss/2477028/C%2B%2Boror-2-approach-oror-Hashmap-andand-vector-oror-Optimise-space-and-TC
pseudo code:
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      
      unordered_map<char,int>mp;
        for(auto x:magazine){
            mp[x]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(mp[ransomNote[i]]==0)return false;
            mp[ransomNote[i]]--;//this means ki humne us character ko use kar liya to uske count ko ek kam kar do
        }
     return true;
        
    }
};

/*approach 3
time is O(m + n) where m and n are the length of both strings 
....time is O(m+n) because we are iterating over both the string one time only
sc: O(1) since size is 26 therefore can be assumed to be constant
*/
class Solution {
public:
    bool canConstruct(string r, string m) {
      vector<int>mp(26,0);
        for(auto x: m){
            mp[x-'a']++;
        }
        for(int i=0;i<r.size();i++){
            if(mp[r[i]-'a']==0)return false;
            mp[r[i]-'a']--;
        }
        return true;
    }
};



