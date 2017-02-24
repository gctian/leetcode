```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/o1-check-power-of-2
@Language: Markdown
@Datetime: 17-01-03 12:38
```

位运算：
假如K是2的幂次方：则K的二进制一定是10000....
K-1就是01111.......
因此 10000...
       &01111...
	   ----------
	     00000.....

**赋值运算符==优先级高于位运算赋**