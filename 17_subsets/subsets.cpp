/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/subsets
@Language: C++
@Datetime: 17-02-08 11:52
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	vector<vector<int> > ret;
    	if(nums.size()==0){
    	    ret.push_back(vector<int>());
    	    return ret;
    	}
    	sort(nums.begin(),nums.end());
    	vector<int> cur;
    	for(int i=0;i<=nums.size();i++){
    	    backtrack(ret,cur,nums,i,0);    
    	}
    	return ret;
    	
    }
    
    void backtrack(vector<vector<int> > &ret,vector<int> &cur,vector<int> &nums,int k,int start){
        if(k==0){
            ret.push_back(cur);
            return;
        }
        for(int i=start;i<nums.size();i++){
            cur.push_back(nums[i]);
            backtrack(ret,cur,nums,k-1,i+1);
            cur.pop_back();
        }
        
    }
};