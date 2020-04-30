/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix-ii
@Language: C++
@Datetime: 17-02-17 07:45
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int rows=matrix.size();
        if(rows<1) return 0;
        int cols=matrix[0].size();
        if(cols<1) return 0;
        
        int count=0;
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(matrix[i][j]==target) count++;
        //     }
        // }
        // return count;
        
        //从左下角向右上角开始搜索
        int i = rows-1;
        int j = 0;
        while(i>=0 && j<=cols-1){
            if(target==matrix[i][j]){
                count++;
                i--;
                j++;
            }else if(target>matrix[i][j]){
                //同行右边
                j++;
            }else{
                //同列上边
                i--;
            }
        }
        return count;
    }
};
