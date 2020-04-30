/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/kth-largest-element
@Language: C++
@Datetime: 17-02-22 17:22
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int process(vector<int> &nums,int left,int right) {

	int key = nums[left];
	int i=left,j=right;
	//左边放>=key的数，故遇到<key就停止
	while(i<j) {
		//先从右边开始，找到第一个大的 
		while(i<j && nums[j]<=key) j--;
		//找到后赋值到上一个空的地方 
		nums[i] = nums[j];

		while(i<j && nums[i]>=key) i++;
		nums[j] = nums[i];

	}
	//放置基准元素
	nums[i] = key;
	return i;
}
 
int search(vector<int> &nums,int left,int right,int k){
//	if(left==right) return 100;
	if(left<=right){
	
    	//返回此区间划分一次后的基准元素的位置
    	int i = process(nums,left,right);
    	if(i-left+1 == k) return nums[i];
    	else if(i-left+1 > k) return search(nums,left,i-1,k);
    	
    	else return search(nums,i+1,right,k-(i-left+1));
	}
 
}

int kthLargestElement(int k, vector<int> nums) {
	// write your code here
	int n=nums.size();
	if(n<1) return 0;

	return search(nums,0,n-1,k);
}
};