/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: C++
@Datetime: 16-12-25 10:33
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0) return 0;
        int length =1;//第一个不重复
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[length]=nums[i];
                length++;
            }
        }
        
        return length;
    }
};