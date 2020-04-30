/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/binary-tree-inorder-traversal
@Language: C++
@Datetime: 17-02-06 09:59
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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
        
        // vector<int> left = inorderTraversal(root->left);
        // vector<int> right = inorderTraversal(root->right);
        // res.insert(res.end(),left.begin(),left.end());
        // res.push_back(root->val);
        // res.insert(res.end(),right.begin(),right.end());
        // return res;
        stack<TreeNode*> mystack;
        TreeNode* cur = root;
        while(cur || !mystack.empty()){
            while(cur){
                mystack.push(cur);
                cur = cur->left;
            }
            if(!mystack.empty()){
                cur = mystack.top();
                res.push_back(cur->val);
                mystack.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};