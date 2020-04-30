```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/reorder-list
@Language: Markdown
@Datetime: 17-02-02 09:05
```

1，快慢指针找到中点
2，中点之后链表逆转
3，逆转的后半部分链表逐个插入前半部分


=============找到链表中点
①slow=head,fast=head
while(fast&&fast->next){}
当循环终止，fast不为空说明奇数，slow是中点
fast为空说明偶数个，slow是中点下一个
②slow=head,fast=head->next;
while(fast&&fast->next){}
fast为空说明奇数，slow刚好是中点
fast不为空说明偶数，slow是中点偏左

不管是奇数还是偶数，只要找中点操作就采取②方法。