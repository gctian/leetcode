```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/jump-game
@Language: Markdown
@Datetime: 17-01-13 16:16
```

可以跳跃的最大长度，并不一定非要跳那么长。
先把第一个当做可以跳的最远距离，遍历数组，
如果当前i>最远距离，直接返回false,
如果最远距离以>=重点，返回true
如果当前可以跳的最远距离大于tempMax，则更新tempMax