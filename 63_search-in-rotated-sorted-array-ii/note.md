```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array-ii
@Language: Markdown
@Datetime: 17-01-03 08:31
```

跟1的区别是：要区分A[mid] > < =A[left]，分开讨论
大于小于和1是一样的，=时候，不能确定该往哪个区间，这时候就让left递增顺序查找。