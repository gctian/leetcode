/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/longest-consecutive-sequence
@Language: C++
@Datetime: 17-02-16 05:19
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        int n = num.size();
        if(n<1) return 0;
        unordered_set<int> s(num.begin(),num.end());
        
        int res = 0;
        //O(n)遍历数组
        for(int i=0;i<n;i++){
            int pre = num[i]-1;
            int next = num[i]+1;
            s.erase(num[i]);
            
            while(s.count(pre)) s.erase(pre--);
            while(s.count(next)) s.erase(next++);
            
            //while循环结束说明pre+1,next-1都是在数组里面,num[i]在中间
            //这一个连续序列的长度是next-1-(pre+1)+1=next-pre-1
            res = max(res,next-pre-1);
        }
        return res;
    }
};