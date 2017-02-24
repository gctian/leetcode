/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: C++
@Datetime: 17-01-03 13:08
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long sum=0;
        // while(n>0){
        //     sum+= n/5;
        //     n/=5;
        // }
        long long temp=5;
        while(temp<=n){
            sum+=n/temp;
            temp*=5;
        }
        return sum;
    }
};
