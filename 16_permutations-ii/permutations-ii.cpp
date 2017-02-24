/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/permutations-ii
@Language: C++
@Datetime: 17-02-12 08:00
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int> > ret;
        if(nums.size()==0){
            ret.push_back(vector<int>());
            return ret;
        }
        dfs(nums,ret,0,nums.size());
        return ret;
        
    }
    bool visited(vector<int> nums,int start,int end){
        for(int i=start;i<end;i++){
            if(nums[i]==nums[end])
                return true;
        }
        
        return false;
    }
    void dfs(vector<int> &nums,vector<vector<int> > &ret,int k,int n){
        if(k==n){
            ret.push_back(nums);
            return;
        }
        for(int j=k;j<n;j++){
            if(visited(nums,k,j)) continue;
            swap(nums[j],nums[k]); //第K位排列好了
            dfs(nums,ret,k+1,n);//继续排第K+1位
            swap(nums[j],nums[k]);//原数组上进行的操作，所以要交换回来恢复状态
        }
    }
};