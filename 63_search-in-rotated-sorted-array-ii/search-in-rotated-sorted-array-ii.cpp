/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 17-01-03 08:31
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int size=A.size();
        if(size==0) return false;
        int left=0,right=size-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(A[mid]==target) return true;
            //left-mid 处于第一个递增区间
            if(A[mid]>A[left]){
                if(A[mid]>target&&target>=A[left]) right=mid-1;
                else left=mid+1;
            }else if(A[mid]>A[left]){
                //mid处于第二个递增区间
                if(A[mid]<target&&target<=A[right]) left=mid+1;
                else right=mid-1;
            }else{
                left++;//顺序查找
            }
        }
        return false;
    }
};