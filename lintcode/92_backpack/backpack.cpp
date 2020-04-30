/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/backpack
@Language: C++
@Datetime: 17-02-15 04:08
*/

class Solution {
    int bestw=0;
    int cw=0;
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        if(A.size()==0) return 0;
        
        //回溯
        // dfs(A,m,0);
        // return bestw;
     
        //动态规划   
        // vector<vector<int> > dp(A.size()+1,vector<int>(m+1,0));
        // for(int i=1;i<=A.size();i++){
        //     for(int j=1;j<m+1;j++){
        //         if(j>=A[i-1]){
        //             dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i-1]]+A[i-1]);
        //         }else{
        //             dp[i][j]=dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[A.size()][m]; 
        int f[m+1];
        for(int i=0;i<=m;i++) f[i]=0;
        for(int i=1;i<=A.size();i++){
            for(int j=m;j>0;j--){
                if(j>=A[i-1]){
                    f[j]=max(f[j],f[j-A[i-1]]+A[i-1]);
                }else{
                    f[j]=f[j];
                }
            }
        }
        return f[m];
        
    }
    void dfs(vector<int> w,int cap,int index){
        if(index>=w.size()) {
            //index从0开始，故index=len时已经计算了0...-1到达叶节点了
            if(cw>bestw) bestw=cw;
            return;
        }
        if(cw+w[index]<=cap){//进入左子树搜索
            cw+=w[index];
            dfs(w,cap,index+1);
            cw-=w[index];
        }
        //搜索右子树，加入剪枝(限定)函数
        //如果当前背包重量+剩余节点的总重量<=当前最好就不搜索
        if(bound(w,index+1)>bestw)
            dfs(w,cap,index+1);
    }
    //上界函数，用于搜索右子树的剪枝，返回当前背包重量+剩余节点的总重量
    int bound(vector<int> w,int level){
        int temp=cw;
        while(level<w.size()){
            temp+=w[level];
            level++;
        }
        return temp;
    }
};