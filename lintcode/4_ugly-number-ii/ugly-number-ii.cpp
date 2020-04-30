/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/ugly-number-ii
@Language: C++
@Datetime: 17-02-16 11:39
*/

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        if(n==1) return 1;
        vector<int> res;
        res.push_back(1);
        
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        
        int m2=res[index2]*2;
        int m3=res[index3]*3;
        int m5=res[index5]*5;
        
        while(res.size()!=n){
            while(m2 <= res[res.size()-1]){
                index2++;
                m2 = res[index2]*2;
            }
            while(m3 <= res[res.size()-1]){
                index3++;
                m3 = res[index3]*3;
            }
            while(m5 <= res[res.size()-1]){
                index5++;
                m5 = res[index5]*5;
            }
            res.push_back(min(min(m2,m3),m5));
        }
        return res[n-1];
        // return method2(n);
    }
    
    int method2(int n){
        queue<int> q2;
        queue<int> q3;
        queue<int> q5;
        
        int count = 1;
        int val = 1;
        while(count<n){
            q2.push(val*2);
            q3.push(val*3);
            q5.push(val*5);
            
            int temp = min(min(q2.front(),q3.front()),q5.front());
            if(temp==q2.front()){
                q2.pop();
            }
            if(temp==q3.front()){
                q3.pop();
            }
            if(temp==q5.front()){
                q5.pop();
            }
            count++;
            val = temp;
        }
        
        return val;
        
    }
};