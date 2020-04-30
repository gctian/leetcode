/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/fibonacci
@Language: C++
@Datetime: 17-02-16 11:50
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        // int num[n];
        // num[0]=0;
        // num[1]=1;
        // if(n>=2){
        //     for(int i=2;i<n;i++)
        //         num[i]=num[i-1]+num[i-2];
        // }
        // return num[n-1];
        int a=0;
        int b=1;
        for(int i=3;i<=n;i++){
            int c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};
