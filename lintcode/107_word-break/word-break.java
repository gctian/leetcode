/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/word-break
@Language: Java
@Datetime: 17-02-15 16:09
*/

public class Solution {
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    public boolean wordBreak(String s, Set<String> dict) {  
        if(s == null || s.length() == 0) return true;  
          
        boolean[] res = new boolean[s.length() + 1];  
        res[0] = true;  
  
        for(int i = 0; i < s.length(); i++) {  
            if(!res[i])  
                continue;  
            else {  
                for(String str : dict) {  
                    int end = i + str.length();  
                    if(end > s.length()) continue;  
                    if(s.substring(i, end).equals(str))  
                        res[end] = true;  
                }  
            }  
        }  
        return res[s.length()];  
    }  
}