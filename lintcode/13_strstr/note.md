```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/strstr
@Language: Markdown
@Datetime: 16-12-25 08:16
```

1,边界条件监测：source，target都为空；target为空字符串，应该返回0

2.**应该先判断为空，当时自己的顺序是
        int slen = strlen(source);
        int tlen = strlen(target);
        if (source == NULL || target == NULL) return -1;  
所以当传入null时，前两句就会先报错，还以为是指针空判断出错。**

3.指针空：p==NULL,p==nullptr


