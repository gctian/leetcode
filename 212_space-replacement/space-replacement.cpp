/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: C++
@Datetime: 17-02-16 13:35
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char str[], int length) {
        // Write your code here
        int spaceNum = 0;
    	for(int i=0;i<length;i++){
    		if(str[i]==' ')	{
    			spaceNum++;
    		}	
    	}
    	int newLength = length + spaceNum * 2;
    	int i=length-1;
    	int j=newLength-1;
    	while(i<j){
    		if(str[i] == ' '){
    			str[j--]='0';
    			str[j--]='2';
    			str[j--]='%';
    		}else{
    			str[j--] = str[i];
    		}
    		i--;
    	}
    	
    	return newLength;
    }
};  