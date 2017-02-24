/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: C++
@Datetime: 17-01-05 16:32
*/

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n==0) return 1%b;//返回1%b而不是1，特殊情况1%1
        if(n==1) return a%b;
        long long temp = fastPower(a,b,n/2);
        if(n%2==0){
            return (temp*temp) % b; 
        }else{
            // return  int(result * result * (a%b)) % b;
            return ((temp*temp)%b*(a%b))%b;
        }
    }
};