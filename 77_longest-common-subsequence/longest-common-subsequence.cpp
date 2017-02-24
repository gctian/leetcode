/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/longest-common-subsequence
@Language: C++
@Datetime: 17-02-13 08:11
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if(A.size()==0 || B.size()==0) return 0;
        int m = A.size();
        int n = B.size();
        vector<vector<int> > dp(m,vector<int>(n,0));
        //初始化第一列
        int i=0;
        for(;i<m;i++){
            if(A[i] == B[0]){
                dp[i][0]=1;
                break;
            }
        }
        for(int j=i+1;j<m;j++){
            dp[j][0]=1;
        }
        for(i=0;i<n;i++){
            if(A[0] == B[i]){
                dp[0][i]=1;
                break;
            }
        }
        for(int j=i+1;j<n;j++){
            dp[0][j]=1;
        }
        for(i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                if(A[i] == B[j]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};
