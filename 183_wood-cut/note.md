```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/wood-cut
@Language: Markdown
@Datetime: 17-01-02 15:52
```

1，原来想着以最小的为参考，每段最大长度也不过是原来最小的木材。但是如果K=1，就切成一段，则这一段最大长度是最大的木材。所以应该以最大长度木材为准。
2，按照mid切分，如果count>=K,说明切小了，应该增大切的长度，另left=mid，而不是left=mid+1,为了不跳过最佳长度，=K是说明在=K时候去试着增大长度，看能否找到更大的切分长度。如果count<K,说明切长度太大了，应该减小，right=mid-1;
while循环终止条件是left+1<right，加1是避免死循环，left+1=right的时候，mid=left，如果count=K再次赋值时left仍然是K，这样就陷入了死循环。
3, rigtt=mid,避免跳过最佳值，对应N个数分N段的情况，这时候以最小值的数做切分。
4，编程时候一个基础：
**21行：int sum=0;当时写了int sum;以为会默认赋值为0.
只有全局变量或静态变量系统才会赋默认值0，对于局部变量没有初始化的时候，系统不会初始化为0，而是随机赋值，在这里是保留了上次栈里的值。**
5，int mid =left+(right-left)/2;//而不是(left+right)/2
应该避免使用后者，因为当int值处于int上节边缘时，left+right就会越界了，此时的left+right是一个负数。而前者就不会。想使用后者也可以，将left，right，mid声明为long long
6,最后返回不是left而是getCount(L, left) >= k ? left : 0;因为有一种情况是while循环结束了，都没有找到合适长度使得count>=K,这时候应该返回0，因为是以最终的left为参考，所以考虑最后的left是否满足条件。
