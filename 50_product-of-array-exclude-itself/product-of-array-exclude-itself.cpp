/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: C++
@Datetime: 16-12-25 09:59
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> ret;
        int size = nums.size();
        if(size==0) return ret;
        long long result;
        for(int i=0;i<size;i++){
            result = 1;
            for(int j=0;j<size;j++){
                if(j!=i){
                    result*=nums[j];
                }
            }
            ret.push_back(result);
        }
        
        return ret;
    }
};