/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/maximum-subarray
@Language: C++
@Datetime: 17-02-15 07:27
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if(n<1) return 0;
        vector<int> dp(n,0);
        dp[0]=nums[0];
        //dp[i]表示以nums[i]结尾的数组的最大子数组和
        //但是整个数组中最大子数组和可能是某个dp[j]
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
        }
        int res=dp[0];
        for(int i=1;i<n;i++){
            if(dp[i]>res) res=dp[i];
        }
        return res;
    }
};
