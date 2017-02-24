/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: C++
@Datetime: 16-12-30 03:49
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.size()==0) return 0;
        int low=0,high=A.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(A[mid]==target) return mid;
            if(A[mid]<target) low = mid+1;
            if(A[mid]>target) high=mid-1;
        }
        // return low;
        return high+1;
    }
};