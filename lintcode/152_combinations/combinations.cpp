/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/combinations
@Language: C++
@Datetime: 17-02-08 11:32
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {  
        // write your code here  
        vector<vector<int> > ret;  
        vector<int> cur;  
        // combine(cur,1,n,k,ret);  
        backtrack(n,k,cur,ret,1);
        return ret;  
    }  
    void combine(vector<int> cur,int index,int n,int k,vector<vector<int> >&ret)  
    {  
        if(cur.size()==k)  
        {  
            ret.push_back(cur);  
            return;  
        }  
        if(index>n||cur.size()>k)  
            return;  
        cur.push_back(index);
        combine(cur,index+1,n,k,ret);  
        cur.pop_back();  
        combine(cur,index+1,n,k,ret);  
    }
    
    void backtrack(int n, int k, vector<int> temp, vector<vector<int> > &res,int start){
        if (k == 0){//所有的找完之后将这个数组进入二维数组中
            res.push_back(temp);
            return;
        }
        else{
            for (int i=start; i<=n; i++){
                temp.push_back(i);
                backtrack(n, k-1, temp, res, i+1);//回溯法找到满足的元素
                temp.pop_back();//回溯，弹出上一个满足的元素
            }
        }
    }
};