```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/maximum-product-subarray
@Language: Markdown
@Datetime: 17-02-15 08:38
```

相乘有可能是负数，与最大连续子数组和不同的是：有可能负负得正变成最大的。
故dp[i]表示以dp[i]结尾的乘积最大子序列。可能是三种情况：
dp[i-1]*num[i]
num[i]
num[i]<0,乘以前面最小的序列有可能变大