/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/spiral-matrix
@Language: C++
@Datetime: 17-02-21 08:48
*/

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> res;
        if(matrix.size() == 0)  return res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        //计算出一共有几个环
        //4刚好2圈，（4+1）/2而不是4/2+1
        int circles = (min(rows,cols)+1)/2;
        
        //记录当前环的高度和宽度，只要有一个为1，就说明只剩下一行或一列
        int curW = cols;
        int curH = rows;
        for(int i=0;i<circles;i++,curW-=2,curH-=2){
            //打印当前环第一行,行固定
            for(int j=i;j<i+curW;j++){
                res.push_back(matrix[i][j]);
            }
            //打印最后一列，列固定:cols-i
            for(int row=i+1;row<i+curH;row++){
                res.push_back(matrix[row][i+curW-1]);
            }
            //如果只要一行或一列，则上面已经打印完了，所以直接退出
            if(curW==1 || curH==1) break;
            
            //否则继续打印最后一行 i+curH-1
            for(int col=i+curW-2;col>=i;col--){
                res.push_back(matrix[i+curH-1][col]);
            }
            //打印第一列:列固定i
            for(int row=i+curH-2;row>=i+1;row--){
                res.push_back(matrix[row][i]);
            }
        }
        return res;
    }
};