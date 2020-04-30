```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: Markdown
@Datetime: 16-12-21 14:12
```

首先长度必须相等，不相等return false。然后要判断每一个字符出现次数是否相等，找到不相等字符或者出现次数不等return false

1， 先按字典大小排序，然后比较对应位置的字符是否相等，不相等return false

2，因为是比较的字符，所以想到字符的ASCII码，因为字符实际上也是int数值，每个字符都有一个对应的ASCII值。ASCII码一共有256个。因为一个字符占一个字节共8位，有0-255种情况。
因此设定一个256大小的int数组，第一个字符串每出现一个字符就在对应索引处加1，第二个字符串的字符在相应位置减一。如果最后这个数组都为0，说明全都相等，如果出现一个不为0的则不是。