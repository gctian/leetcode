/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: C++
@Datetime: 16-12-26 15:11
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> ret;
        int size = nums.size();
        if(size==0) return ret;
        
        int i,j;
        for(i=0;i<size;i++){
            for(j=i+1;j<size;j++ ){
                if((nums[i]+nums[j])==target){
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    break;
                }
            }
        }
        return ret;
    }
};
