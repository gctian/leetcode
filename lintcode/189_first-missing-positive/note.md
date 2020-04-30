```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/first-missing-positive
@Language: Markdown
@Datetime: 16-12-29 03:28
```

我的思路：先排序，然后找到第一个整数的位置，判断如果大于1就返回1，否则从那个位置开始遍历，如果后一个-前一个大于1就停止，说明最小整数应该是前一个+1。

别人思路：
