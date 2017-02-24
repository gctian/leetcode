/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/maximum-product-subarray
@Language: C++
@Datetime: 17-02-15 08:38
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int n = nums.size();
        if(n<1) return 0;
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        dp1[0]=nums[0];
        dp2[1]=nums[0];
        for(int i=1;i<n;i++){
            dp1[i]=max(dp1[i-1]*nums[i],max(nums[i],nums[i]*dp2[i-1]));
            dp2[i]=min(dp2[i-1]*nums[i],min(nums[i],nums[i]*dp1[i-1]));
        }
        int ret=dp1[0];
        for(int i=1;i<n;i++){
            ret=max(ret,dp1[i]);
        }
        return ret;
    }
};