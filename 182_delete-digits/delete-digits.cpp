/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/delete-digits
@Language: C++
@Datetime: 17-01-13 15:18
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
    	//每次删除当前最大的，直到删除K个
    	string temp = A;
    	while(k--){
    		int i =0;
    		while(i<temp.size()-1&&temp[i]<=temp[i+1]) i++;
    		//删除大于tempMax的数字
    		temp = temp.substr(0,i) + temp.substr(i+1);
    	}
    	int i;
    	for(i=0;temp[i]=='0';i++);
    	temp = temp.substr(i);
    	return temp;
    }
};
