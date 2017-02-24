```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/convert-sorted-list-to-balanced-bst
@Language: Markdown
@Datetime: 17-02-03 04:58
```

高度平衡的二叉树，也就是高度最小的二叉树。

1，找到中点，中点作为root
2，中点左边递归，中点右边递归。中点左边需要知道中点的前一个节点，
因此可以设置一个dummy节点。