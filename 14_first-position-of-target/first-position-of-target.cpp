/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 16-12-30 03:32
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int low=0,high=array.size()-1;
        int result =-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(array[mid]==target){
                if(result<0) result = mid;
                if(result>0&&mid<result) result=mid;
                // low=low;
                high=mid-1;
            }
            
            if(array[mid]>target) high=mid-1;
            if(array[mid]<target) low=mid+1;
        }
        return result;
    }
};