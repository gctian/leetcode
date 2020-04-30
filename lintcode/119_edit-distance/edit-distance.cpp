/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/edit-distance
@Language: C++
@Datetime: 17-02-15 11:48
*/

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int n=word1.size();
        int m=word2.size();
        if(n<1) return m;
        if(m<1) return n;
        //vector大小是(n+1,m+1),说明前面有一个空字符。dp[i][j]表示前i个字符变成str2的前j个字符需要的次数
        //即str1[0...i-1] -> str2[0...j-1] 最后返回dp[n][m]
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        //初始行
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int temp1=dp[i-1][j]+1;
                int temp2=dp[i][j-1]+1;
                if(word1[i-1]!=word2[j-1]){
                    dp[i][j]=min(min(temp1,temp2),dp[i-1][j-1]+1);
                }else{
                    dp[i][j]=min(min(temp1,temp2),dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
