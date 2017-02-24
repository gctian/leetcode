```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: Markdown
@Datetime: 17-01-02 02:50
```

旋转排序数组：把一个递增的排序数组的前若干个元素放到最后一个元素的后面，这样其实是分成两个递增的子数组。
理论上第一个子数组的第一个元素应该大于等于第二个子数组的最后一个元素，最小元素应该是第二个子数组的第一个元素。**否则的话则是没有旋转**。
跟正常的二分法一样，设前后两个指针，left指向第0个，right指向最后一个，如果mid>left,（**没有重复元素**）说明mid处于第一个子数组，应该往mid右边查找。如果mid<left,说明mid处于第二个数组，应该让right=mid继续查找。因为有可能是mid刚好处于最小元素位置。