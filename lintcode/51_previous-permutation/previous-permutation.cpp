/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/previous-permutation
@Language: C++
@Datetime: 17-01-17 14:52
*/

bool cmp(int a,int b) {
	return a>b; //TRUE才交换 
}

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        //就是找右边第一个大于右边相邻数字的位置 
    	int size = nums.size();
    	if(size == 0) return nums;
    	//nums已经是一个全排列，全排列特点：右起递增左起递减，找到临界数
    	//如12354
    	int ld=-1;
    	for(int i=size-2; i>=0; i--) {
    		if(nums[i]>nums[i+1]) {
    			ld = i;//找到右起第一个大于右邻数字的位置 
    			break;
    		}
    	}
    	//-1表示是最小的全排列
    	if(ld == -1) {
    		//递减排列
    		sort(nums.begin(),nums.end(),cmp);
    		return nums;
    	}
    	//找到ld右边第一个小于nums[ld]的位置 
    	int rd ;
    	for(int i=size-1; i>ld; i--) {
    		if(nums[i] < nums[ld]) {
    			rd = i;
    			break;
    		}
    	}
    	//交换ld,rd位置的两个数字
    	int temp = nums[ld];
    	nums[ld] = nums[rd];
    	nums[rd] = temp;
    //	swap(nums[ld],nums[rd]);
    
    	//ld+1位置后的数字递减排列
    	sort(nums.begin()+ld+1,nums.end(),cmp);
    
    	return nums;
    }
};