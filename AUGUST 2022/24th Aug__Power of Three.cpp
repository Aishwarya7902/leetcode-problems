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


/*Approach 3
base conversion
tc:
sc:
PSEUDO CODE:
1.any power of 10,in base 10,starts with 1 and rest digits are zero
eg. 10,100,1000
2.1.any power of 2,in base 2,starts with 1 and rest digits are zero
eg. 2=10 , 4=100 ,8=1000.
3.similary any power of 3,in base 3,starts with 1 and rest digits are zero
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1)  //edge case
            return false;
        string nbase3="";
        while(n){
            nbase3+=to_string(n%3);
            n/=3;
        }
        int i=0;
        while(i<nbase3.size()-1){
            if(nbase3[i]!='0')return false;
            i++;
        }
         //check if starting digit is 1
        return nbase3[i]=='1';
    }
};

/*approach 4
INTEGER LIMITATION
tc:O(1)
sc:O(1)
video:https://www.youtube.com/watch?v=UncqP2F4t_0
PSEUDO CODE:The positive divisors of 319 are exactly the powers of 3 from 30 to 319. That's all powers of 3 in the possible range here (signed 32-bit integer).
So just check whether the number is positive and whether it divides 319.
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
   return  n>0 && int(pow(3,19))%n==0 ;
    }
};



