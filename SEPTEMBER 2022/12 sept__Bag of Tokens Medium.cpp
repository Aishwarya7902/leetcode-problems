PROBLEM:https: https://leetcode.com/problems/bag-of-tokens/

/*MY INITIAL APPROACH (SOLVED ON MY OWN)
TWO POINTER +GREEDY
VIDEO:https://www.youtube.com/watch?v=JAfE7TBdTeU
//tc:o(nlogn) sorting +o(n)
//sc:o(1)
*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       int n=tokens.size();
        if(n==1){
            if(power<tokens[0])return 0;
        }
       sort(tokens.begin(),tokens.end());
       int i=0,j=n-1,score=0,ans=0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
            }
            else if(score>=1){
                power+=tokens[j];
                j--;
                score--;
            }
            else{
                break;
            }
            ans=max(ans,score);
        }
        return ans;
    }
};
