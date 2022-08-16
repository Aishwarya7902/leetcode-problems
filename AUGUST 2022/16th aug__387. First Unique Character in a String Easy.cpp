/*PROBLEM:https://leetcode.com/problems/first-unique-character-in-a-string/
TC: O(n)
sc:O(1)
pseudo code:
Brute force solution, traverse string s 2 times. First time, store counts of every character into the hash table, 
second time, find the first character that appears only once.

Runtime: 83 ms, faster than 25.93% of C++ online submissions for First Unique Character in a String.
Memory Usage: 10.8 MB, less than 15.57% of C++ online submissions for First Unique Character in a String.

THE ONLY PROBLEM WITH THIS APPROACH:if the string is extremely long, we wouldn't want to traverse it twice, so instead only storing just counts of a char, we also store the index, 
and then traverse the hash table.
*/

class Solution {
public:
    
    int firstUniqChar(string s) {
       unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        for(int i=0;i<s.size();i++){
           if(mp[s[i]]==1)return i;
        }
        return -1;
    }
};

/*
OPTIMISED APPROACH
TC: O(N)
SC: O(N)
pseudo code:
Another way to traverse the string only once.
You can use hashmap to store the index of non-duplicated numbers. For duplicates, save the index as INT_MAX. Return the minimum index.


BLOG:https://leetcode.com/problems/first-unique-character-in-a-string/discuss/86338/C%2B%2B-2-solutions
Runtime: 43 ms, faster than 68.85% of C++ online submissions for First Unique Character in a String.
Memory Usage: 10.7 MB, less than 71.90% of C++ online submissions for First Unique Character in a String.

*/

class Solution {
public:
    
    int firstUniqChar(string s) {
       unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end())
                mp[s[i]]=i;
            else
                mp[s[i]]=INT_MAX;
        }
        int ans=INT_MAX;
        for(auto it:mp){
            ans=min(ans,it.second);
        }
        return (ans==INT_MAX)? -1: ans;
    }
};

