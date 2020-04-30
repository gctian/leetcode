```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/update-bits
@Language: Markdown
@Datetime: 17-01-04 16:40
```

思路：让m=i->j位都变成0，其它保持不变，然后将n左移i位，与m相加。
重点：如何实现让m=i->j位都变成0，其它保持不变。
都变成0就应该想到与操作，和0与变0，和1与不变。
所以构造mask：i->j为是0，其它位是1.然后mask&n
如何构造mask：反过来构造i->j为是1，其它位是0.
如果二进制数：001110 (1->3是1的二进制数),利用相减去构造。
                         +000010  
						 --------------
						   010000