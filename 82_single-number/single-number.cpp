/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/single-number
@Language: C++
@Datetime: 17-01-09 02:39
*/

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int size = A.size();
        if(size==0) return 0;
        int result = A[0];
        for(int i=1;i<size;i++){
            result ^= A[i];
        }
        return result;
    }
};
