/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/spiral-matrix-ii
@Language: C++
@Datetime: 17-02-22 08:10
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        vector<vector<int> > res(n,vector<int>(n,0));
        if(n<1) return res;
        int circles = (n+1)/2;
        int num = 1;//记录循环的数字
        int w=n;
        for(int i=0;i<circles;i++,w-=2){
            
            //添加第一行
            for(int j=i;j<i+w;j++){
                res[i][j]=num++;
            }
            //添加最后一列 n-i-1
            for(int row=i+1;row<i+w;row++){
                res[row][i+w-1] = num++;
            }
            //添加最后一行 n-1-i
            for(int col=i+w-2;col>=i;col--){
                res[i+w-1][col]=num++;
            }
            //添加第一列 i
            for(int row=i+w-2;row>=i+1;row--){
                res[row][i] =  num++;
            }
        }
        return res;
    }
};