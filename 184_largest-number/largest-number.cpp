/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/largest-number
@Language: C++
@Datetime: 17-01-12 03:43
*/

bool cmp(string s1,string s2){
        return (s1+s2) > (s2+s1);
    }
class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
     
    string toString(int a){
        stringstream ss;
        ss << a;
        return ss.str();
    }
    string largestNumber(vector<int> &num) {
        // write your code here
        vector<string> s_num(num.size());
        for(int i=0;i<num.size();i++){
            s_num[i] = toString(num[i]);
        }
        //使用冒泡排序机制，只不过比较规则变成 s1+s2 > s2+s1,满足就交换两个数s1,s2
        sort(s_num.begin(), s_num.end(), cmp);
        string ret;
        for(int i=0;i<s_num.size();i++){
            ret += s_num[i];
        }
        //以0开头的字符串就返回0
        return ret[0]=='0'?"0":ret;
    }
};