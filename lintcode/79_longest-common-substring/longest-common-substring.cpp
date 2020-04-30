/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/longest-common-substring
@Language: C++
@Datetime: 16-12-25 08:12
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        if(A.size()==0 || B.size()==0) return 0;
        
        int maxLength = 0;
        for(int i=0;i<A.size();i++){
            
            for(int j=0;j<B.size();j++){
                //A的当前字符遇到B中相等的字符，就开始比较当前当前相等子串
                if(A[i] == B[j]){
                    //判断当前相等子串长度,k=1判断下一个字符是否相等，因为当前字符已经相等
                    //所以从1开始.
                    //循环条件除了对应字符相等，还有判断其中一个的字符是否相等，有可能同时到达末尾
                    int k;
                    for(k=1;(A[i+k]==B[j+k])&&B[j+k]!='\0';k++);
                    
                    if(k>maxLength) maxLength = k;
                }
            }
        }
        return maxLength;
    }
};
