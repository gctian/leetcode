/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: C++
@Datetime: 16-12-30 03:08
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if(x==0) return 0;
        long low=0,high=x/2+1;
        while(low<=high){
            long mid = (low+high) / 2;
            if(mid*mid==x) return mid;
            if(mid*mid>x) high=mid-1;
            if(mid*mid<x) low=mid+1;
        }
        return high;
        
    }
};