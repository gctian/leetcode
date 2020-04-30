/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/3sum
@Language: C++
@Datetime: 16-12-28 03:23
*/

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > ret;
        int size =nums.size();
        if(size==0) return ret;
        sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<=size-3;i++){
            //如果当前第一个大于0，直接break因为是递增顺序
            
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=size-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }else if(sum<0){
                    j++;
                }else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ret.push_back(temp);
//                    res.push_back({nums[i], nums[j], nums[j]});
                    //移动j，k，
//                    do{ ++j; } while( j < k && nums[j-1] == nums[j] );  
//                    do{ ++k; } while( j < k && nums[k-1] == nums[k] );  
                    while(j<k&&nums[j+1]==nums[j]) j++;
                    while(j<k&&nums[k-1]==nums[k]) k--;
                    //跳过相等
                    j++;k--;
                }
            }
        }
        return ret;
    }
};
