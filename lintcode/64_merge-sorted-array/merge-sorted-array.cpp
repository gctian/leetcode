/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/merge-sorted-array
@Language: C++
@Datetime: 16-12-25 12:08
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int i=m-1,j=n-1,k=m+n-1;
        //从最后开始比较,从前面要移位
        while(i>=0&&j>=0){
            if(A[i]<=B[j]){
                A[k--]=B[j--];
            }else{
                A[k--]=A[i--];
            }
        }
        while(i>=0){
            A[k--]=A[i--];
        }
        while(j>=0){
            A[k--]=B[j--];
        }
    }
};