/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 16-12-30 07:49
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        if(n==0) return false;
        int i;
        // O(m)
        // for(i=0;i<m-1;i++){
        //     if(matrix[i+1][0]>=target&&matrix[i][0]<=target){
        //         break;
        //     }
        // }
        // O(logm)
        int left=0,right=m-1,mid=0;
        while(left<=right){
            mid=(left+right)/2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] < target) left=mid+1;
            if(matrix[mid][0] > target) right=mid-1;
        }
        //mid仍然=0，说明第一个数大于target
        if(matrix[mid][0]>target && mid==0) return false;
        i=right;
        left=0;
        right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[i][mid] == target) return true;
            if(matrix[i][mid] < target) left=mid+1;
            if(matrix[i][mid] > target) right=mid-1;
        }
        return false;
    }
};
