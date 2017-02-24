/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: C++
@Datetime: 17-01-02 02:50
*/

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if(size==0) return 0;
        int left=0,right=size-1;
        
        while(left<right){
            //说明排序数组没有旋转
            if(nums[left]<nums[right]){
                return nums[left];
            }
            int mid=(left+right)/2;
            //>=不是考虑到重复，而是mid，left重合时候
            if(nums[mid]>=nums[left]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return nums[right];
        
    }
};