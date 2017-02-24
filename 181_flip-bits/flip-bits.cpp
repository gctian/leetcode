/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: C++
@Datetime: 17-01-03 12:24
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int c=a^b;
        int count=0;
        while(c!=0){
            c=c&(c-1);
            count++;
        }
        return count;
        
    }
};