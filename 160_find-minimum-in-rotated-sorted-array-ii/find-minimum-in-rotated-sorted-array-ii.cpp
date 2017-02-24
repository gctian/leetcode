/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 17-01-02 03:42
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int size=num.size();
        if(size==0) return 0;
        int left=0,right=size-1;
        while(left<right){
            int mid=left+(right-left)/2;
            //mid>right:当前mid处于第一个递增数组，最小值一定在后面【mid+1,right】
            if(num[mid]>num[right]){
                left=mid+1;
            }else if(num[mid]<num[right]){
                right=mid;
            }else{
                //mid == right:说明第二个数组的最后若干个个是相等的，最小的可能是相等的数字
                //也可能在其前面，总之right--一定是对的。
                right--;
            }
        }
        return num[right];
    }
};