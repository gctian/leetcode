/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 17-02-16 09:13
*/

class MinStack {
private:
    stack<int> s1;//作为数据栈，正常栈的操作
    stack<int> s2;//作为最小栈，保持和s1的同步入栈出站操作，站内元素个数一致
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        s1.push(number);
        if(s2.empty()){
            s2.push(number);
        }else{
            s2.push(number<s2.top()?number:s2.top());
        }
    }

    int pop() {
        // write your code here
        int res = s1.top();
        s2.pop();
        s1.pop();
        return res;
    }

    int min() {
        // write your code here
        return s2.top();
    }
};
