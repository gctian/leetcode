/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/3sum-closest
@Language: C++
@Datetime: 16-12-28 03:56
*/

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int size = nums.size();
        int sum;
        // if(size<3){
        //     for(int i=0;i<nums.size();i++){
        //         sum+=nums[i];
        //     }
        //     return sum;
        // }
        sort(nums.begin(),nums.end());
        int closest = nums[0]+nums[1]+nums[2];
        int mindiff = abs(closest-target);
        for(int i=0;i<size-2;i++){
            int j=i+1;
            int k=size-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(sum-target);
                if(diff<mindiff){
                    mindiff = diff;
                    closest = sum;
                }
                if(diff==0) return sum;
                if(sum<target) j++;
                if(sum>target) k--;
            }
        }
        return closest;
    }
};
