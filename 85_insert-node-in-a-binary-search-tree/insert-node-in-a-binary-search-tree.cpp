/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/insert-node-in-a-binary-search-tree
@Language: C++
@Datetime: 17-02-06 07:17
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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        // if(!root) return node;
        // if(node->val > root->val){
        //     root->right = insertNode(root->right,node);
        // }else{
        //     root->left = insertNode(root->left,node);
        // }
        // return root;
        
        //非递归,要寻找插入位置
        //cur用来遍历，last记录插入的位置
        if(!root){
            return node;
        }
        TreeNode *cur = root;
        TreeNode *last=NULL;
        while(cur){
            last = cur;
            if(cur->val > node->val) cur = cur->left;
            else cur = cur->right;
        }//找到插入的位置
        if(last){
            if(node->val > last->val) //作为右孩子
                last->right = node;
            else
                last->left = node;
        }
        
        return root;
        
    }
};