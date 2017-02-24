/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 17-01-09 02:58
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if(size==0) return 0;
        int ret = nums[0];
        int count = 1;
        for(int i=1;i<size;i++){
            if(count>0){
                if(nums[i] == ret) count++;
                else count--;
            }else{
                ret = nums[i];
            }
        }
        return ret;
    }
};
