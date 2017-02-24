```
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-arrays
@Language: Markdown
@Datetime: 16-12-25 11:57
```

不要用sort函数

1.0版本：不熟悉vector用法
for(i=0,j=0;i<A.size()||j<B.size();){
            if(i>=A.size()){
                ret.push_back(B[j]);
                j++;
                continue;
            }
            if(j>=B.size()){
                ret.push_back(A[i]);
                i++;
                continue;
            }
            if(A[i]<=B[j]){
                ret.push_back(A[i]);
                i++;
            }else{
                ret.push_back(B[j]);
                j++;
            }
        }