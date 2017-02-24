/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: C++
@Datetime: 16-12-21 14:12
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        int asize = s.size();
        int bsize = t.size();
        if (asize != bsize) return false;
        int asc[256] = {0};
        for(int i=0; i<asize; i++){
            asc[s[i]]++;
            asc[t[i]]--;
        }
        
        for(int i=0;i<256;i++){
            if(asc[i] !=0 ){
                return false;
            }
        }
        
        return true;
    }
};