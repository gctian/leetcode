```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: Markdown
@Datetime: 16-12-30 03:08
```

√x<=(x+1)/2 ，由于C++中/的特征，区间上界稍微放大到x/2+1；下界设为0即可。

最后是返回high