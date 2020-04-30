/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-arrays
@Language: C++
@Datetime: 16-12-25 11:57
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @resulturn: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        //初始化vector，长度为asize+bsize，默认值为0 
        // vector<int> result(A.size()+B.size(), 0);
        vector<int> result;
        int i=0,j=0,k=0;
        
        //因为都是有序的，最后一个元素是最大的，比较最后元素谁大就放在新数组最后
        while(i<A.size()&&j<B.size()){
            if(A[i]<=B[j]){
                result.push_back(A[i++]);
                // result[k++]=A[i++];
            }else{
                result.push_back(B[j++]);
                // result[k++]=B[j++];
            }
        }
        //B已走到最后
        while(i < A.size()){
            result.push_back(A[i++]);
            // result[k++]=A[i++];
        }
        while(j < B.size()){
            result.push_back(B[j++]);
            // result[k++]=B[j++];
        }
        return result;
    }
};