/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/subsets-ii
@Language: C++
@Datetime: 17-02-11 08:38
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
     
    void backtrack(vector<vector<int> > &ret,vector<int> &cur,vector<int> &S,int k,int start){
        if(k==0){
            ret.push_back(cur);
            return;
        }
        for(int i=start;i<S.size();i++){
            if(i!=start&&S[i]==S[i-1]) continue;
            cur.push_back(S[i]);
            backtrack(ret,cur,S,k-1,i+1);
            cur.pop_back();
        }
        
    }
    vector<vector<int> > subsetsWithDup( vector<int> &S) {
        // write your code here
        vector<vector<int> > ret;
    	if(S.size()==0){
    	    ret.push_back(vector<int>());
    	    return ret;
    	}
    	sort(S.begin(),S.end());
    	vector<int> cur;
    	for(int i=0;i<=S.size();i++){
    	    backtrack(ret,cur,S,i,0);    
    	}
    	return ret;
    }
    
    
};
