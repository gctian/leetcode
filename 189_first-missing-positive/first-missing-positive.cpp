/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/first-missing-positive
@Language: C++
@Datetime: 16-12-29 03:28
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int size = A.size();
        if(size==0) return 1;
        sort(A.begin(),A.end());
        int i;
        for(i=0;i<size;i++){
            if(A[i]>0){
                break;
            }
        }
        if(A[i]>1) return 1;
    
        int j;
        for(j=i;j<size-1;j++){
            if(A[j+1]-A[j]>1){
                break;
            }
        }
        return A[j]+1;
    }
};