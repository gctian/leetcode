/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 16-12-21 16:13
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int asc[256] = {0};
        
        for(int i=0;i<A.size();i++){
            asc[A[i]]++;
        }
        
        for(int i=0;i<B.size();i++){
            asc[B[i]]--;
        }
        
        for(int i=0;i<256;i++){
            //说明B中的某个字符在A中没有出现过
            if(asc[i] <0 ){
                return false;
            }
        }
        
        return true;
    }
};
