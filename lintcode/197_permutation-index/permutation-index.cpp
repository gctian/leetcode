/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/permutation-index
@Language: C++
@Datetime: 17-01-17 16:00
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        int size = A.size();
        if (size==0) return 0;
        
        long long num = 1;//最少是1
        int a[size];//记录每一位后面有多少个小于该位数字的数
        a[size-1] = 0;
        for(int i=0;i<size-1;i++){
            //统计i后面小于A[i]的个数
            int count = 0;
            for(int j=i+1;j<size;j++){
                if(A[j]<A[i]){
                    count++;
                }
            }
            a[i]=count;
        }
        long long base = 1,c=1;
        for(int i=size-2;i>=0;i--){
            base*=c++;
            num += base * a[i];
        }
        return num;
    }
};