PROBLEM: https://leetcode.com/problems/power-of-three/ 

/*APPROACH 1
USING LOOPS
TC: O(N)
SC: O(1)
VIDEO:  https://www.youtube.com/watch?v=GNb8vSyw-WE
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>=3){
            if(n%3!=0)return false;
            n/=3;
        }
        return n==1;
    }
};

