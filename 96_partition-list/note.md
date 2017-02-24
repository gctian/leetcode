```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/partition-list
@Language: Markdown
@Datetime: 17-02-01 08:49
```

ListNode *p=head;
是将head之后的链表都赋值给p;
但是如果赋值操作之后还有操作p的语句，如p-val,
p->next=new ListNode()则此时p是指当前的head节点。
所以smallTail不用写next=NULL,因为后面用到了smallTail->next
但是largeTail->next=NULL必须写，不然是把head之后的节点都拿过来了.