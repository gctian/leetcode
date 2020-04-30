```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: Markdown
@Datetime: 16-12-22 15:37
```

思路：依然是哈希，其实就是根据一个key，去映射value，看这个value值是否相同，相同则为，同一个。但这里与上一个映射ASCII字符的哈希不同，ASCII只能映射单个字符，这里应该把每一个字符串当做key，首先应该把每个字符串进行排序，这样乱序的字符串排序后是一样的，把排序后的每一个字符串当做key，出现次数当做value。最后再循环这个字典，如果key值大于1则说明是乱序。

***关于17行为什么要定义temp =s
因为sort函数排序会改变原字符串，所以要定义temp，对temp排序，再考虑原字符串s是否一样