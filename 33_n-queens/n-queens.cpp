/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/n-queens
@Language: C++
@Datetime: 17-02-08 07:05
*/

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    //用于检验放置是否正确,冲突返回FALSE
bool check(vector<int> &cur,int k,int i) {
	for(int i=0; i<k; i++) {
		if(cur[i] == cur[k]) return false;
		if(abs(i-k) == abs(cur[i]-cur[k])) return false;
	}

	return true;
}

void show(int *a) {
	for(int i=0; i<8; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
vector<string> getResult(vector<int> &choice) {
	vector<string> res;
	int size = choice.size();
	for(int i=0; i<size; i++) {
		string temp(size,'.');
		temp[choice[i]] = 'Q';
		res.push_back(temp);
	}
	return res;
}

//用于放置第k个皇后的位置
void design(vector<vector<string> > &res,vector<int> &cur ,int k,int n) {
	if(k==n ) {
		res.push_back(getResult(cur));
	} else {

		//在第k行选一个位置
		for(int i=0; i<n; i++) {
			cur[k] = i;//把第K个皇后放置在k行第J列 ；
			//检验当前的放置是否会和前面的皇后冲突
			if(check(cur,k,i)) {//不冲突
				design(res,cur,k+1,n);
			}
		}
	}
}


vector<vector<string> > solveNQueens(int n) {
	// write your code here
	vector<vector<string> > res;
	vector<int> cur(n);
	design(res,cur,0,n);

	return res;
}
};
