```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: Markdown
@Datetime: 16-12-30 03:32
```

因为查找target第一次出现的位置，所以当查找到target的时候，
不能马上返回索引，因为前面有可能也存在target数字。
数组是升序排序的，所以应该往查找到的左半部分继续查找。
前面如果还有，一定会再找到的。