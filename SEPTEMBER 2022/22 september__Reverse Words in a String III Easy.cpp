PROBLEM: https://leetcode.com/problems/reverse-words-in-a-string-iii/
/*my initial apprach
peseudo code:
1.take two pointer i,j and start traversing ...till u encounter a white space...move j only in this case
2.as soon as u encounter a white space ....then the index just before it will be the last character of the previous word
3.set k=j+2 ...as the index one after j is a white space so we set k=j+2
4.now reverse the substring between i and j pointers
5.follow above steps untill u have reversed every word of string
tc: O(n*m)
here n is the length of string and m is the length of largest word in the string
sc: O(1) as we did not take any extra space

video:

*/
class Solution {
public:
  void Reverse(string &s,int i,int j){
    while(i<=j){
      char temp=s[i];
      s[i]=s[j];
      s[j]=temp;
      i++;
      j--;
    }
  }
    string reverseWords(string s) {
     int n=s.size();
      int i=0,j=0,k;
      while(i<n){
        while(s[j+1]!=' '  && j+1<n){
          j++;
        }
        k=j+2;
        Reverse(s,i,j);
        i=k;
        j=k;
      }
      return s;
    }
};

/*
method 2
self explanatory
blog:https://leetcode.com/problems/reverse-words-in-a-string-iii/discuss/842597/4-wayseasy-understandingc%2B%2Bfaster

*/

class Solution {
public:
  
    string reverseWords(string s) {
     int n=s.size();
      string result="",word;
      for(int i=0;i<n;i++){
        if(s[i]!=' '){
          word+=s[i];
        }
        else{
          reverse(word.begin(),word.end());
          result+=word;
          result+=" ";
          word.clear();
        }
      }
      reverse(word.begin(),word.end());
      result+=word;
      return result;
    }
};

