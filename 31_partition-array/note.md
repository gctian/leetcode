```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/partition-array
@Language: Markdown
@Datetime: 16-12-29 03:24
```

类似于快排：
1，首尾双指针，外层循环从前、后分别遍历，指针相撞终止。
2，左指针循环直到>=K就停止，否则+1
      右指针循环直到<K就停止，否则-1
3，交换左右指针停止位置的数字，分别++,--。
4, 返回right位置,那个位置应该是K在的位置
5,注意边界情况，left<=right,有一种情况是，交换之后left++,
right--之后指向同一位置，这时候应该继续判断当前位置和K的关系

==================
以一个数字划分开大小，就是左边都小于K，右边都大于等于K，并不要求排序只是划分开。