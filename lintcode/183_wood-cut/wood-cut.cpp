/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/wood-cut
@Language: C++
@Datetime: 17-01-02 15:52
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        //O(n log Len), Len为 n 段原木中最大的长度,肯定是对最大长度的原木进行二分查找
        int size= L.size();
        if(size==0) return 0;
        //找到最大值
        int max=L[0];
        for(int i=1;i<size;i++){
            if(L[i]>max) max=L[i];
        }
        int left=1,right=max;
        
        while(left+1<right){
            int sum=0;
            int mid=left+(right-left)/2;
            // for(int i=0;i<size;i++){
            //     sum+=L[i]/mid;
            // }
            sum = getCount(L,mid);
            if(sum>=k){
                //切小了,=K时候也改变left，视图寻找K相等时最大的段
                left=mid;
            }else{
                //切大了
                right=mid;
            }
        }
        return  getCount(L, left) >= k ? left : 0;
        // return left;
    }
    private:
        int getCount(vector<int> L,int len){
            int sum=0;
            for (int num : L)
                sum += num / len;
            return sum;
        }
};