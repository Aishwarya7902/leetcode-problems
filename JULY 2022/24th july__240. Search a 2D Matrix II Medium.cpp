/* approach 1__BRUTE FORCE
tc:o(m*n)
sc:o(1)
pseudo code:
1.traverse in every cell of matrix using two for loops ....if u find target...return true
2.if u have traversed whole matrix and never found target..return false
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[0].size();j++){
               if(matrix[i][j]==target)
                   return true;
           }
       } 
        return false;
    }

/*approach 2__ACCEPTED BUT QUITE SLOW
tc:O(n*logm) //here n=no of rows and m=no of columns
sc:O(1)
pseudo code:
1.traverse in every row and apply binary search in that row
*/

 bool BinarySearch(vector<vector<int>>& matrix,int i, int target){
        int low=0;
        int hi=matrix[i].size()-1;
        while(low<=hi){
            int mid=low+(hi-low)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            if(matrix[i][mid]<target){
                low=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       for(int i=0;i<matrix.size();i++){
          if(BinarySearch(matrix,i,target))
              return true;
       } 
        return false;
    }



/*MOST OPTIMAL APPROACH
tc:O(m+n) coz at max we will reach left most starting from top right element
sc:O(1)
pseudo code ....see striver bhaiya's approach
VIDEO LINK:  https://youtu.be/ZYpYur0znng
*/


bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
            return false;
        int n=matrix.size();
        int m=matrix[0].size();
       int i=0,j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]<target)
                i++;
            else
                j--;
        }
        return false;
    }
