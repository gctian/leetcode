/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/reorder-array-to-construct-the-minimum-number
@Language: C++
@Datetime: 17-02-22 11:41
*/

bool cmp(string s1,string s2){
        return (s1+s2) < (s2+s1);
    }

class Solution {
    
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    
    string minNumber(vector<int>& nums) {
        // Write your code here
        int n = nums.size();
        vector<string> vec(n);
        if(n<1) return "";
        for(int i=0;i<n;i++){
            vec[i] = toString(nums[i]);
        }
        
        sort(vec.begin(),vec.end(),cmp);
        
        //有可能0在前面,如果有 0一定在前面
        int i;
        for(i=0;i<n;i++){
            if(vec[i]!="0") break;
        }
        //处理全是0的情况
        if(i==n) return "0";
        string str;
        for(;i<n;i++){
            str+=vec[i];
        }
        return str;
        
    }
    string toString(int n){
        stringstream ss;
        ss << n;
        return ss.str();
    }
};