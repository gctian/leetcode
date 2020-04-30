/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/remove-node-in-binary-search-tree
@Language: C++
@Datetime: 17-02-08 03:26
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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(!root) return NULL;
        TreeNode *dumpy = new TreeNode(-1);
        dumpy->left = root;
        //temp用于遍历寻找删除节点，farther来记录删除节点的双亲节点
        TreeNode *temp = root,*farther = dumpy;
        while(temp&&temp->val!=value){
            farther = temp;
            if(temp->val > value){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }//找到要删除的节点temp
        if(!temp) return root; //要删除的点不存在
        if(temp->left==NULL && temp->right==NULL){
            if(farther->left == temp) farther->left = NULL;
            else farther->right = NULL;
        }else if(temp->left == NULL){
            if(farther->left == temp) farther->left = temp->right;
            else farther->right = temp->right;
        }else if(temp->right == NULL){
            if(farther->left == temp) farther->left = temp->left;
            else farther->right = temp->left;
        }else{
            //左右子树都不为空
            //右子树的左子树为空
            if(temp->right->left==NULL){
                if(farther->left == temp) farther->left = temp->right;
                else farther->right = temp->right;
                
                temp->right->left = temp->left;
            }else{
                farther = temp->right;
                TreeNode *cur = temp->right->left;
                while(cur->left=NULL){
                    farther = cur;
                    cur = cur->left;
                }
                temp->val = cur->val;
                farther->left = cur->right;
            }
        }
        return dumpy->left;
        
    }
};