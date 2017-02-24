/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/partition-array
@Language: C++
@Datetime: 16-12-29 03:24
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int size = nums.size();
        if(size==0) return 0;
        int left = 0;
        int right = size-1;
        while(left<=right){
            //循环，两个终止条件，必须要写left<=right
            while(left<=right&&nums[left]<k) left++;
            while(left<=right&&nums[right]>=k) right--;
            if(left<=right){
                int temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
                left++;
                right--;
            }
        }
        return left;
    }
};