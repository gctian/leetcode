/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/interleaving-string
@Language: C++
@Datetime: 17-02-15 15:04
*/

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int n = s1.size();
        int m = s2.size();
        if(n==0 && s2==s3) return true;
        if(m==0 && s1==s3) return true;
        if(n+m != s3.size()) return false;
        
        //dp[i][j]表示取s1前i个字符和s2前j个字符能否组成s3前i+j个字符
        //返回dp[n][m]
        //s3最后一个字符一定是s1或者s2的最后一个字符或者和s1,s2最后一个都相等
        vector<vector<bool> > dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;//假设s3前面有一个空字符
        //初始化行
        for(int i=1;i<=m;i++){
            //s2的前i个字符能否组成s3的前i个字符
            dp[0][i]=dp[0][i-1]&&s2[i-1]==s3[i-1];
        }
        //初始化列
        for(int i=1;i<=n;i++){
            //s1的前i个字符能否组成s3的前i个字符
            dp[i][0]=dp[i-1][0]&&s1[i-1]==s3[i-1];
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //s3最后一个字符和s1最后一个字符相等
                if(s3[i+j-1] == s1[i-1]){
                    //用||是因为有可能和s1,s2最后一个字符都相等，这种情况只要有一个为真就可以。
                    dp[i][j] = dp[i-1][j] || dp[i][j];
                }//s3最后一个字符和s1最后一个字符相等
                if(s3[i+j-1] == s2[j-1]){
                    dp[i][j] = dp[i][j-1] || dp[i][j];
                }
            }
        }
        return dp[n][m];
    }
};