/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal
@Language: C++
@Datetime: 17-02-06 07:52
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > res;
			if(!root) return res;

			queue<TreeNode*> Q;
			Q.push(root);

			while(!Q.empty()) {
				//当前队列共有多少个节点 
				int len = Q.size();
				vector<int> level;
				while(len--){
					//访问队首元素，层中最左边元素。 
					TreeNode *temp = Q.front(); 
					level.push_back(temp->val);
					//将其左右孩子入队
					if(temp->left)  Q.push(temp->left);
					if(temp->right) Q.push(temp->right);
					//从队中删除,pop删除队列的第一个元素。 
					Q.pop();
				}//该层节点访问完
				res.push_back(level) ;
			}
			return res;
    }
};
