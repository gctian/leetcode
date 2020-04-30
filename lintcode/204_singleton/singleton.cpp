/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/singleton
@Language: C++
@Datetime: 17-02-16 12:14
*/

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* instance;
    static Solution* getInstance() {
        // write your code here
        if(instance==NULL){
            instance =  new Solution();
        }
        return instance;
    }
};
//c++中全局static变量的引用
Solution* Solution::instance=NULL;