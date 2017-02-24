```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/find-peak-element
@Language: Markdown
@Datetime: 17-01-03 09:34
```

1，遍历整个数组，直接判断也可以但是复杂度是O(n)
用二分法可以优化，
如果A[mid]<A[mid-1] 则在【r,mid-1】一定会存在一个峰值
如果A[mid]<A[mid+1] 则在【mid+1,right】一定会存在一个峰值
2，
left=1,right=size-1,因为第0个和最后一个肯定不是。
最后返回的时候要判断left和right位置的大小，因为有可能left或者right一直处于1或size-2的位置。
3，最后的else：left=mid也可以，right=mid也可以。


