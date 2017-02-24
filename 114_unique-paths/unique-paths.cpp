/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: C++
@Datetime: 17-02-13 16:27
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<vector<int> > a(m+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            a[1][i]=1;
        }
        for(int i=1;i<=m;i++){
            a[i][1] = 1;
        }
        for(int i=2;i<m+1;i++){
            for(int j=2;j<n+1;j++){
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
        return a[m][n];
    }
};
