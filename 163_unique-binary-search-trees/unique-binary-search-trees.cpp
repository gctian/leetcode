/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees
@Language: C++
@Datetime: 17-01-05 03:59
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
     
    long long C(int m,int n) {
        //从m中取n个
        long long a=1,b=1;
        for(int i=1;i<=n;i++){
            a*=m--;
            b*=i;
            
        }
        return a/b;
    }
    
    long long C2(int n, int m){
        n = n-m+1;
        long long ans = 1;
        for(int i=1; i<=m; ++i){
            ans *= n++;
            ans /= i;
        }
        return ans;
    }
     
    int numTrees(int n) {
        // write your code here
        return C2(2*n,n) / (n+1);
    }
};