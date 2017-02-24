/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/subtree
@Language: C++
@Datetime: 17-02-20 07:23
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if(!T2) return true;//T2空
        if(!T1) return false;//T1空，T2不空
        
        //如果一样，返回true
        if(isEqual(T1,T2)){
            return true;
        }
        
        //不一样，要么是左子树的子树要么是右子树的子树
        // return isSubtree(T1->left,T2) || isSubtree(T1->right,T2);
        if(isSubtree(T1->left,T2))  
            return true;  
        if(isSubtree(T1->right,T2))  
            return true;  
        return false;
        
    }
    
    //这是判断是否一样
    bool isEqual(TreeNode *t1,TreeNode *t2){
        if(!t1&&!t2) return true;//都为空返回true
        if(!t1) return false;//有一个为空
        if(!t2) return false;
        
        if(t1->val != t2->val) return false;
        
        return isEqual(t1->left,t2->left)&&isEqual(t1->right,t2->right);
        return false;
    }
    
};