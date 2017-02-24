/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/binary-representation
@Language: C++
@Datetime: 17-01-06 07:24
*/

#include <strstream>
class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    void reverse(string& str) {
    	int len=str.size();
    	for(int i=0,j=len-1; i<j; i++,j--) {
    		char temp = str[i];
    		str[i] = str[j];
    		str[j] = temp;
    	}
    }

    string toString(int num) {
    	stringstream ss;
    	ss << num;
    	return ss.str();
    }
    
    string binaryRepresentation(string n) {
    	// write your code here
    	//截取整数部分
    	int int_num = atoi(n.c_str()) ;
    	string int_str = "";
    	//整数部分是0
    	if(int_num==0) int_str+="0";
    	while(int_num>0) {
    //		char ch[2];
    //		itoa(int_num % 2,ch,10); //赋值一个字符，大小应该是2
    		int_str+= toString(int_num%2);
    		int_num /= 2;
    	}
    	reverse(int_str);
    
    	//截取小数部分
    	double point = atof(n.substr(n.find("."),n.size()-n.find(".")).c_str()) ;
    //	double point=0.64355;
    	//小数部分为0
    	if(point == 0) return int_str;
    	string point_str="";
    	while(true) {
    		if(point_str.size()>32) return "ERROR";
    		double temp = point * 2;
    		if(temp == 1.0) {
    			point_str+="1";
    			break;
    		} else if(temp > 1) {
    			point_str+="1";
    			point = temp - 1;
    		} else {
    			point_str+="0";
    			point=temp;
    		}
    	}
    
    	return int_str+"."+point_str;
    }
};
