/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/distinct-subsequences
@Language: C++
@Datetime: 17-02-15 13:13
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int n =S.size();
        int m=T.size();
        if(m<1) return 1;//全部删除S字符
        if(n<m) return 0;
        //dp[i][j]表示str1[0...i-1]前i个字符的子序列中str2[0...j-1]的前j个字符出现的次数
        //返回dp[n][m];
        //首先一定dp[i][j]>=dp[i-1][j],=的时候是多的一个字符在str2[0..j]中从未出现过
        //如果最后多的字符在str2中出现过或者在str1[0..i-1]中出现过，仍然是dp[i][j]==dp[i-1][j].因为它出现和不出现是一样的。假如删掉之前重复的字符，那相对位置就发生变化了。
        //如果str1[i-1]==str2[j-1]则 dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S[i-1]==T[j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
