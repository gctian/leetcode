/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/next-permutation
@Language: C++
@Datetime: 17-01-17 03:32
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if(size == 0) return nums;
        //nums已经是一个全排列，全排列特点：右起递增左起递减，找到临界数
        //如12354
        int ld=-1;
        for(int i=size-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ld = i;//找到右起第一个非递增数字
                break;
            }
        }
        //-1表示是最大的全排列
        if(ld == -1){
            //从小到大递增排列
            sort(nums.begin(),nums.end());
            return nums;
        }
        //找到右起第一个大于ld位置的数字
        int rd ;
        for(int i=size-1;i>=ld;i--){
            if(nums[i] > nums[ld]){
                rd = i;
                break;
            }
        }
        //交换ld,rd位置的两个数字
        int temp = nums[ld];
        nums[ld] = nums[rd];
        nums[rd] = temp;
        
        //ld+1位置后的数字升序递增排列
        sort(nums.begin()+ld+1,nums.end());
        
        return nums;
        
    }
};