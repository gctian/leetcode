/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/longest-increasing-subsequence
@Language: C++
@Datetime: 17-02-13 06:08
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if(nums.size()<1) return 0;
        vector<int> dp(nums.size(),0);
        //dp[i]代表序列中以numsp[i]结尾的最长子序列
        dp[0] = 1;
        for(int i=1;i<nums.size();i++){
            int tempMax = 0;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(dp[j] > tempMax){
						tempMax = dp[j];
                    }
                }
            }
            dp[i] = tempMax + 1;
        }
        int res = 0;
        for(int i=0;i<dp.size();i++){
            if(dp[i]>res) res=dp[i];
        }
        return res;
    }
};
