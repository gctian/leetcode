/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/first-bad-version
@Language: C++
@Datetime: 17-01-03 08:46
*/

/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        if(n==1) return 1;
        int left=1,right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            if(SVNRepo::isBadVersion(mid)){
                //mid是错误版本，则mid之后肯定不是第一个
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return right;
    }
};
