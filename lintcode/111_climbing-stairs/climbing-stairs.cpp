/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: C++
@Datetime: 17-02-13 16:20
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        int num[n+1];
        num[0] = 1;
        num[1] = 1;
        for(int i=2;i<n+1;i++){
            num[i]=num[i-1]+num[i-2];
        }
        return num[n];
        
    }
};
