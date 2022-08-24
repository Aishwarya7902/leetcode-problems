PROBLEM: https://leetcode.com/problems/power-of-three/ 

/*APPROACH 1
LOOP ITERATION
TC: O(log3(N))
SC: O(1)
VIDEO:  https://www.youtube.com/watch?v=GNb8vSyw-WE
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1)  //edge case
            return false;
        while(n%3==0){
           
            n/=3;
        }
        return n==1;
    }
};

/*approach 2
recursive:
tc: O(log3(N))
sc:O(log3(N))
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=1)  //edge case
            return n==1;
        return (n%3==0) && isPowerOfThree(n/3);
    }
};

