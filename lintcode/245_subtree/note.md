```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/subtree
@Language: Markdown
@Datetime: 17-02-20 07:23
```

如果T2是T1的子树：
1：T2空，不管T1空或者不空，肯定是
2：T1空，肯定不是
3：T1，T2都非空：
		T1,T2完全一样
		T2是T1左子树的子树
		T2是T1右子树的子树