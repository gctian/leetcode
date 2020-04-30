```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: Markdown
@Datetime: 17-01-03 12:24
```

位运算
1，先进行异或操作：相异为1，相同为0
2，统计一的个数：一个数n与n-1进行与操作，会使原来的数字n的二进制1的个数减一。
3，局部变量系统不会赋初始值0，是随机的上次栈里保存的值。
可以声明后赋值，但是不能只声明后面又进行运算。