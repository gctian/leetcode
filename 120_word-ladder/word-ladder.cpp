/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/word-ladder
@Language: C++
@Datetime: 17-02-12 12:27
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
       if(start=="" || end=="") return 0;
        if(start==end) return 1;
        queue<string> Q;
        Q.push(start);
        map<string,int> count;
        count[start] = 1;
        dict.erase(start);
        
        while(!Q.empty()){
            string cur = Q.front();
            Q.pop();
            int len = cur.size();
            int dist = count[cur];
            for(int i=0;i<len;i++){
            	string temp = cur;//每次替换时候都要保证是原来的单词 
            	
                for(char c='a';c<='z';c++){
                	
                    if(temp[i] == c){
                        continue;//继续从temp的下一个字符开始匹配
                    }else{
                        temp[i] = c;    
                    }
                    if(temp == end) return dist+1;
                    if(dict.find(temp)!=dict.end()){//替换后的字符串在字典里面
                        Q.push(temp);
                        dict.erase(temp);
                        count[temp] = dist+1;
                    }
                }
            }
        }
        
        return 0;
    }
};