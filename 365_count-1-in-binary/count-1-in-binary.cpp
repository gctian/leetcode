/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/count-1-in-binary
@Language: C++
@Datetime: 17-02-17 06:55
*/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int count=0;
        //n与n-1进行与操作，一定会把右起第一个1变成0，有多少个1就可以进行多少次这样的与操作
        while(num){
            //最后一位是1
                count++;
                num=num&(num-1);
        }
        return count;
    }
};