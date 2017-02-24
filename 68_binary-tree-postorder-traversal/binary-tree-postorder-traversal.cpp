/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 17-02-20 12:21
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
        
        // vector<int> left = postorderTraversal(root->left);
        // vector<int> right = postorderTraversal(root->right);
        // res.insert(res.end(),left.begin(),left.end());
        // res.insert(res.end(),right.begin(),right.end());
        // res.push_back(root->val);
        // return res;
        stack<TreeNode*> mystack;
        TreeNode *cur = root;
        TreeNode *lastVisit = NULL;
        while(cur || !mystack.empty()){
            while(cur){
                //入棧
                mystack.push(cur);
                cur = cur->left;
            }//遍历左子树
            //取出栈顶节点
            cur = mystack.top();
                //后续遍历中一个根节点被访问的前提是右子树为空，或右子树刚被访问过
                if(!cur->right || cur->right==lastVisit){
                    res.push_back(cur->val);
                    lastVisit = cur;
                    mystack.pop();
                    cur = NULL;
                    
                }else{
                    //遍历其右子树
                    cur = cur->right;
                }
            }
        return res;
    }
};