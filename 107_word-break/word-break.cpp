/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/word-break
@Language: C++
@Datetime: 17-02-15 16:33
*/

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        int n = s.size();
        //dp[i]表示s的前i个字符能否被切分
        vector<bool> dp(n+1,false);
        //以后这种情况在0处都设置为正确情况，假设结果字符串前有一个空字符
        dp[0]=true;
        
        for(int i=0;i<=n;i++){
            //假设s[i-1]后有一个空格
            if(!dp[i])//如果前i个字符可以被切分直接返回
                continue;
            //前i个不能切分，假设i后有一个空格切分,往后再看i+k个字符看这段是否出现在字典中
            //k是字典中每一个单词的长度
            unordered_set<string>::iterator it;
            for(it=dict.begin();it!=dict.end();it++){
                string temp = *it;
                int k = temp.size();
                if(i+k > n) continue;
                if(dict.count(s.substr(i,k))){
                    dp[i+k]=true;//此处也可以直接return
                }
            }
        }
        return dp[n];
    }
};