```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: Markdown
@Datetime: 17-01-05 16:32
```

**(a * b) % p = (a % p * b % p) % p  **

原来a^n % b

1. 如果n 为奇数可以转化为 (a^(n/2) * a^(n/2) *  a ) %b = ((a^(n/2)%b * a^(n/2)%b)%b * (a)%b) %b

2 . 如果n 为偶数可以转化为   (a^(n/2) * a^(n/2) ) %b = (a^(n/2)%b * a^(n/2)%b)%b 

用递归，每次分半，结束条件n=0,1时候。