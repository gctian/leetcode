```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/longest-common-prefix
@Language: Markdown
@Datetime: 16-12-25 07:36
```

1 默认把第一个当做最长前缀，然后和第二个比较，得到新的最长前缀。再让这个更新后的前缀和第三个比较，再去更新，以此循环。