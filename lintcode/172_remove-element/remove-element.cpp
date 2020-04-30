/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 16-12-25 09:16
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int size = A.size();
        if (size==0) return 0;
        //设定两个指针，一个在前一个在后
        int left=0,right=size-1;
        while(left<=right){
            //找到后，因为要删除而且可以改变元素顺序，所以把right赋值给left
            if(A[left]==elem){
                A[left]=A[right];
                right--;
            }else{
                left++;
            }
        }
        A.erase(A.begin()+right+1,A.end());
        return A.size();
    }
};