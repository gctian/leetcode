/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/string-permutation
@Language: C++
@Datetime: 17-02-20 11:59
*/

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        // if(A=="" || B=="") return false;
        if(A.size()!=B.size()) return false;
        
        //哈希表，A字符串中的字符为key，该字符出现的次数为value
        map<char,int> m;
        for(int i=0;i<A.size();i++){
            m[A[i]]++;
        }
        for(int i=0;i<B.size();i++){
            m[B[i]]--;
        }
        map<char,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            if(it->second > 0) return false;
        }
        return true;
    }
};