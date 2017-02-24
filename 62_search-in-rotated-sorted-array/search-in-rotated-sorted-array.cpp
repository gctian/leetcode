/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array
@Language: C++
@Datetime: 17-01-03 08:12
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int size=A.size();
        if(size==0) return -1;
        int left=0,right=size-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(A[mid]==target) return mid;
            //left-mid 处于第一个递增区间
            if(A[mid]>A[left]){
                if(A[mid]>target&&target>=A[left]) right=mid-1;
                else left=mid+1;
            }else{
                //mid处于第二个递增区间
                if(A[mid]<target&&target<=A[right]) left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};