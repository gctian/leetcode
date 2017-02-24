```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/word-break
@Language: Markdown
@Datetime: 17-02-15 16:33
```

1 是可以不止一个空格切分
2 S[0]前面可以有一个空格切分，S[len-1]后面可以有一个空格。
故i循环的范围是0...len
3 dp[i]表示字符串前i个字符能否被切分，i是从0开始，dp[0]就表示空字符，这里假设字典中也有空字符
如果前i个字符不能被切分，则假设字符s[i-1]后有一个空格，如果子串S[i....i+k]在字典里面出现
则设置dp[i+k]=true，也就是说s[i-1]后有一个空格，s[i+k]后有一个空格，这两个空格切分的子串出现在字典中。
k是字典中每一个可能的字符串长度。故需要遍历字典。