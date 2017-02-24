/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/triangle
@Language: C++
@Datetime: 17-02-14 03:36
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int rows=triangle.size();
        if(rows<1) return 0;
        int cols=triangle[rows-1].size();
        if(cols==0) return 0;
        
        
        for(int i=rows-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j] = min(triangle[i][j]+triangle[i+1][j],triangle[i][j]+triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
        
    }
};
