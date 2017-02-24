/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: C++
@Datetime: 17-02-13 17:00
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        if(rows==0 || cols==0) return 0;
        vector<vector<int> > a(rows,vector<int>(cols,0));
        
        for(int i=0;i<rows;i++){
            if(obstacleGrid[i][0]==1) break;
            a[i][0]=1;
        }
        for(int i=0;i<cols;i++){
            if(obstacleGrid[0][i]==1) break;
            a[0][i]=1;
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(obstacleGrid[i][j]==1){
                    a[i][j]=0;
                }else{
                    a[i][j]=a[i-1][j]+a[i][j-1];
                }
            }
        }
        return a[rows-1][cols-1];
    }
};