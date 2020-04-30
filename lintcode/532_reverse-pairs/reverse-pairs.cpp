/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/reverse-pairs
@Language: C++
@Datetime: 17-02-21 11:44
*/

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        // int n = A.size();
        // if(n==0) return 0;
        // int count = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(A[j]<A[i]) count++;
        //     }
        // }
        // return count;
        if(A.size()==0) return 0;
        long long count = 0;
        divide(A,0,A.size()-1,count);
        return count;
        
    }
    
    //划分start...end的序列
    void divide(vector<int> &A,int start,int end,long long &count){
        if(start==end) return;
        int mid = start+(end-start)/2;
        
        divide(A,start,mid,count);
        divide(A,mid+1,end,count);
        //合并start...end区间，两边已经有序
        combine(A,start,end,count);
        
    }
    
    void combine(vector<int> &A,int start,int end,long long &count){
        int mid = start+(end-start)/2;
        //新数组存储合并后的序列
        int len = end-start+1;
        int temp[len];
        
        //l,r两个指针分别指向左边的尾部和右边的尾部
        int l=mid;
        int r = end;
        int k =len-1;
        while(l>=start&&r>=mid+1){
            if(A[l] > A[r]){
                count += r-mid;//共有这么多个逆序对，r-(mid+1)+1
                temp[k--] = A[l--];
            }else{
                temp[k--] = A[r--];
            }
        }
        while(l>=start) temp[k--] = A[l--];
        while(r>=mid+1) temp[k--] = A[r--];
        
        //再把这段放回原数组
        for(l=start,k=0;k<end-start+1;k++){
            A[l+k] = temp[k];
        }
        
    }
};