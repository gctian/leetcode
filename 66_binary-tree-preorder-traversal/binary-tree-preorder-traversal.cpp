/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 17-02-06 08:56
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
        
        // vector<int> leftv = preorderTraversal(root->left);
        // vector<int> rightv = preorderTraversal(root->right);
        // res.push_back(root->val);
        // res.insert(res.end(),leftv.begin(),leftv.end());
        // res.insert(res.end(),rightv.begin(),rightv.end());
        // return res;
        
        TreeNode *temp = root;
			stack<TreeNode*> mystack;
			while(temp || !mystack.empty()) {
				while(temp) {
					res.push_back(temp->val);
					mystack.push(temp);
					temp = temp->left;
				}//左子树遍历完 
				//访问栈顶元素
				TreeNode *top = mystack.top(); 
				//删除栈顶
				mystack.pop();
				//访问右子数，接着循环 
				temp = top->right; 
			}
			return res;
    }
};
