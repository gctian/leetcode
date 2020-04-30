/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/find-peak-element
@Language: C++
@Datetime: 17-01-03 09:34
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int size=A.size();
        int left=1,right=size-2;
        while(left<right){
            int mid=left+(right-left)/2;
            if(A[mid]>A[mid-1]&&A[mid]>A[mid+1]) return mid;
            if(A[mid]<A[mid-1]){
                //往左边搜索，一定会存在峰值
                right=mid-1;
            }else if(A[mid]<A[mid+1]){
                left=mid+1;
            }else{
                left=mid;
            }
        }
        if(A[left]<A[right]) return right;
        else return left;
    }
};
