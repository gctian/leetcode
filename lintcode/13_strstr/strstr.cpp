/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 16-12-25 08:16
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (source == NULL || target == NULL) return -1;  
        int slen = strlen(source);
        int tlen = strlen(target);
        if(tlen==0) return 0;
        int i=0,j=0;
        for(i;i<slen;i++){
            for(j=0;j<tlen;j++){
                 if(source[i+j]!=target[j]) break;
            }
            //找到target最后
            if(j==tlen){
                return i;
                break;
            }
        }
        return -1;
    }
};
