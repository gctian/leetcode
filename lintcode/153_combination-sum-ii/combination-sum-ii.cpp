/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/combination-sum-ii
@Language: C++
@Datetime: 17-02-10 10:38
*/

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int> > res;
        if (num.size()==0) return res;
        vector<int> cur;
        sort(num.begin(),num.end());
        dfs(num,res,cur,target,0);
        return res;
    }
    void dfs(vector<int> &num, vector<vector<int> > &res,vector<int> &cur,int target,int start){
        if(target==0) {
            res.push_back(cur);
            // return;
        }
        if(target<0) return;
        for(int i=start;i<num.size();i++){
            if(i!=start&&num[i]==num[i-1]) continue;
            target-=num[i];
            cur.push_back(num[i]);
            dfs(num,res,cur,target,i+1);
            target+=num[i];
            cur.pop_back();
        }
    }
};