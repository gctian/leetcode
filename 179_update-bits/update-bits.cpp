/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/update-bits
@Language: C++
@Datetime: 17-01-04 16:40
*/

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int mask;
        if(j<31){
            //i->j位都是0其余是1
            mask = ~((1<<(j+1))-(1<<i));
        }else{
            //i->最高位都变成0剩余都是1
            mask = (1 << i) - 1;
        }
        return (mask&n) + (m<<i);
    }
};