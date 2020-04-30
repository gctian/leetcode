/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/print-numbers-by-recursion
@Language: C++
@Datetime: 17-02-20 07:59
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> res;
        if(n==0) return res;
        
        num(n,0,res);
        return res;
    }
    
    void num(int n,int base,vector<int> &res){
        if(n==0){
            if(base>0)
                res.push_back(base);
            return;
        }
        
        for(int i=0;i<=9;i++){
            num(n-1,base*10+i,res);
        }
    }
};