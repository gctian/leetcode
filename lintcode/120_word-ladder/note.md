```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/word-ladder
@Language: Markdown
@Datetime: 17-02-12 12:27
```

1，queue记录待处理的字符串，初始时加入sstart入队
2，map记录start到每个字符串的距离,初始时map[start]=1
3，队列不空时循环，每次取出一个对头元素，循环其每一个字符，每一个字符都试图循环替换成a-z中的任何一个，
	如果替换后的新字符串==end,直接返回count+1
	如果当前字符和要替换的字符相等，则continue视图替换成下一个字符。
	如果新字符串在字典中可以找到，说明当前改变可以走一步，则把新字符串入队，新字符串的map值为原来的字符串距离+1；同时在字典中删除新字符串。
4：比如start = abc ;
	替换字符a，若新字符串==bbc且字典中存在,则bbc入队，map[bbc]=map[abc]+1，dict.erase(bbc);
	继续循环，若又找到zbc且存在,同样也是zbc入队，map[zbc]=map[abc]+1，dict.erase(zbc);