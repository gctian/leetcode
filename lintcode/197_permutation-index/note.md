```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/permutation-index
@Language: Markdown
@Datetime: 17-01-17 16:00
```

如数字54321排列，考虑它前面的排列
第一个位置可能的数字1 2 3 4 5
当是1,2,3,4任意一个时候，都分别对应4！种情况。
当第一个位置是5，第二个位置可能是 1,2,3,4，
1,2,3，分别对应3!中情况。以此类推。