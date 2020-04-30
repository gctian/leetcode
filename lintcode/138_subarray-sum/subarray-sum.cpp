/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/subarray-sum
@Language: C++
@Datetime: 16-12-25 09:46
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        vector<int> ret;
        int size=nums.size();
        if(size==0) return ret;
        int sum;
        for(int i=0;i<size;i++){
            //每一次外循环时都让sum重置为0
            sum=0;
            for(int j=i;j<size;j++){
                sum+=nums[j];
                if(sum==0){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};