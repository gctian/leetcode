```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/delete-digits
@Language: Markdown
@Datetime: 17-01-13 15:18
```

1，注意这是在原地删除，不是把剩余数字重新组合。
2，删除数字是任意，并不是删除连续的K个。
3，最后输出不能有前缀0
4,假如三个数字组合最小，最小的一定满足 百位数<=十位数<=个位数。由此受到启发，若原来数字中前一个>后一个则删除前一个，直到删除K个数字。剩下的应该就是最小的数字。但是要注意边界情况，**比如剩下的是以若干个0开头的就要把0去掉**