```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal
@Language: Markdown
@Datetime: 17-02-06 07:52
```

1，用一个队列去存储每一层的节点。
2，若对不空，依次访问队中节点加入到vector中
3 将其左右孩子入队，并从队列中删除该节点。