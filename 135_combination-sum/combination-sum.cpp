/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/combination-sum
@Language: C++
@Datetime: 17-02-11 02:38
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
     
    void dfs(vector<int> &candidates,vector<vector<int> > &res,vector<int> &cur,int target,int index) {
    	if(target==0) {
    		res.push_back(cur);
    	}
    	if(target<0) return ;
    	for(int i=index; i<candidates.size(); i++) {
    		
    		//如果当前和-候选数字<0 就return 
    		if(target < candidates[i]) return;
    		if(i!=index&&candidates[i]==candidates[i-1]) continue;
    		target = target - candidates[i];
    		cur.push_back(candidates[i]);
    		dfs(candidates,res,cur,target,i);
    		target += candidates[i];
    		cur.pop_back();
    	}
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int> > res;
        vector<int> cur;
        if(candidates.size()==0) return res;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,res,cur,target,0);  
        return res;
    }
    
    
};