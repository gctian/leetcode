/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/partition-array-by-odd-and-even
@Language: C++
@Datetime: 17-02-17 08:43
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n<1) return;
        
        int left=0;
        int right=n-1;
        
        while(left<right){
            //左边遇到第一个偶数就停止
            //这里面的while循环一定要加判断left<right,特殊情况是left,right挨着
            while(left<right&&nums[left]%2!=0) left++;
            //右边遇到第一个奇数就停止
            while(left<right&&nums[right]%2==0) right--;
            //交换
            int temp = nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            
            left++;
            right--;
        }
    }
};