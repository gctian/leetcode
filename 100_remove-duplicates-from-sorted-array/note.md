```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: Markdown
@Datetime: 16-12-25 10:33
```

用两个变量，一个用来记录有效数字即不重复数字的长度，一个用来遍历原来数组，跳过重复元素

因为是排序数组，所以只要和前一个比较就可以了.