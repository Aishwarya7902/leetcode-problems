PROBLEM: https://leetcode.com/problems/rotate-image/
VIDEO:

/*
INITIAL APPROACH : solved this question via observation
here we can have 2 observations 
FIRST ONE IS:
1st row is changing to -> (n-1) th  column
2nd row is changing to -> (n-2) th column
3rd row is changing to -> (n-3)rd column
.
.
.
similarly 
nth row changes to -> 0th column


SECOND OBSERVATION:
(0,0) -> (0,2)
(0,1) -> (1,2)           FILLING THE 0th COLUMN
(0,2) -> (2,2)
**********************
(1,0) -> (0,1)
(1,1) -> (1,1)           FILLING THE 1st COLUMN
(1,2) -> (2,1)
*********************
(2,0) -> (0,0)
(2,1) -> (1,0)           FILLING THE 2nd COLUMN
(2,2) -> (2,0)

*********************
FROM ABOVE TWO OBSERVATIONS WE CAN DEFINE A FORMULA FOR IT
but lets first make a 2d array named temp
formula:
run two for loops from i=0 to i<n and an inner loop starting from j=0 to j<n
for every i and  and j
temp[j][N-i-1]=matrix[i][j]

TC : O(N X M)
SC:  O(N X M)
BUT GIVEN IN QUESTION THAT N=M
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     int n=matrix.size();
       int temp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[j][n-i-1]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=temp[i][j];
            }
        }
    }
};
