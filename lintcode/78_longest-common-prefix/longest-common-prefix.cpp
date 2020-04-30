/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/longest-common-prefix
@Language: C++
@Datetime: 16-12-25 07:36
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
      if (strs.size() == 0) return "";
      //默认第一个是最长前缀
      string ret = strs[0];
      //和后面每个元素进行比较
      for(int i=0;i<strs.size();i++){
          string temp = ret;//每次都和ret进行比较
          string current = strs[i];
          ret = "";//用于存储本次比较的结果
          for(int j=0;j<current.size()&&j<temp.size();j++){
              if(temp[j] == current[j]){
                  //添加相同元素
                  ret+=temp[j];
              }else{
                  break;
              }
          }
      }
      
      return ret;
    }
};