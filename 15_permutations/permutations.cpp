/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/permutations
@Language: C++
@Datetime: 17-02-12 07:01
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    void dfs(vector<int> &nums,vector<vector<int> > &ret,int k,int n){
        if(k==n){
            ret.push_back(nums);
            return;
        }
        for(int j=k;j<n;j++){
            swap(nums[j],nums[k]);
            dfs(nums,ret,k+1,n);
            swap(nums[j],nums[k]);
        }
    }
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int> > ret;
        if(nums.size()==0) {
            ret.push_back(vector<int>());
            return ret;
        }
        dfs(nums,ret,0,nums.size());
    }
};
