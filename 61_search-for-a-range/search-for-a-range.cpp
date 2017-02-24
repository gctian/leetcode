/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/search-for-a-range
@Language: C++
@Datetime: 17-01-03 07:39
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        //log(n)复杂度肯定是二分查找
        vector<int> ret;
        int size=A.size();
        if(size==0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int l=0,r=size-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(A[mid]<target){
                l=mid+1;
            }else{
            	r=mid;
			}
        }
        //有可能找不到
        if(A[l]==target){
		    ret.push_back(l);
		}else{
		    ret.push_back(-1);
		    ret.push_back(-1);
		    return ret;
		}
		//搜索右区间
        l=0;
        r=size-1;
        while(l+1<r){
        	int mid=l+(r-l)/2;
            if(A[mid]>target){
                r=mid-1;
            }else{
            	//往后面找是否还有target数字 
            	l=mid;
			}
		}
		if(A[r]==target){
		    ret.push_back(r);
		}else if(A[l]==target){
		    ret.push_back(l);
		}else{
		    ret.push_back(-1);
		    ret.push_back(-1);
		    return ret;
		}
		
        return ret;
    }
};