/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/jump-game
@Language: C++
@Datetime: 17-01-13 16:16
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        //贪心法
        int tempMax = A[0];//把第一个当做最远距离
        for(int i=0;i<A.size();i++){
            if(tempMax>=A.size()-1) return true;
            if(i>tempMax) return false;
            if(tempMax<(i+A[i])){
                //更新最远距离
                tempMax = i+A[i];
            }
            
            
        }
        return false;
    }
};
