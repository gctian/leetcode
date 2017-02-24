/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/gas-station
@Language: C++
@Datetime: 17-01-11 08:53
*/

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int begin = 0;
        int currentGas = 0;
        int totalGas = 0;
        int totalCost = 0;
        for(int i=0;i<gas.size();i++){
            currentGas += gas[i];
            totalGas += gas[i];
            totalCost += cost[i];
            
            if(currentGas < cost[i]){
                //换下一个出发点
                begin = i+1;
                currentGas = 0;
            }else{
                //可以出发
                currentGas -= cost[i];
            }
            
        }
        if(totalGas >= totalCost) return begin;
        else return -1;
        
    }
};