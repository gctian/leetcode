/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: C++
@Datetime: 17-02-06 03:49
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return depth(root)!=-1;
    }
    
    int depth(TreeNode *root){
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        
        //-1不是平衡二叉树
        if(left==-1 || right==-1 || abs(left-right)>1)
            return -1;
        //是平衡二叉树
        return max(left,right)+1;
    }
};