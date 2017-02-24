/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: C++
@Datetime: 16-12-22 15:37
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        map<string,int> dict;
        for(string s:strs){
            sort(s.begin(),s.end());
            dict[s]++;
        }
        vector<string> ret;
        for(string s:strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            if(dict[temp]>1){
                ret.push_back(s);
            }
        }
        return ret;
    }
};
