/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/maximum-subarray-ii
@Language: C++
@Datetime: 17-02-15 08:06
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        //分成两半
        int n = nums.size();
        if(n<1) return 0;
        vector<int> left(n,0);//0...n-1
        vector<int> right(n,0);//n-1...0
        
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        
        for(int i=1;i<n;i++) left[i]=max(left[i-1]+nums[i],nums[i]);
        for(int i=n-2;i>0;i--) right[i]=max(right[i+1]+nums[i],nums[i]);
        
        int res=INT_MIN;//表示int最小的负整数
        for(int i=0;i<n-1;i++){//最少包含一个数
            for(int j=n-1;j>i;j--){
                int temp = left[i]+right[j];
                if(temp>res) res=temp;
            }
        }
        return res;
    }
};
