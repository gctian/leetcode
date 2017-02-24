/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/binary-tree-path-sum
@Language: C++
@Datetime: 17-02-20 08:46
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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int> > res;
        vector<int> cur;
        
        if(!root) return res;
        
        cur.push_back(root->val);
        
        dfs(root,res,cur,target);
        
        return res;
        
    }
    
    void dfs(TreeNode *root,vector<vector<int> > &res,vector<int> cur,int target){
        if(root->left==NULL&&root->right==NULL){
            if(target == root->val){
                res.push_back(cur);
            }
            return;
        }
        if(root->right){
            cur.push_back(root->right->val);
            dfs(root->right,res,cur,target-root->val);
            cur.pop_back();//相当于回溯
        }
        if(root->left){
            cur.push_back(root->left->val);
            dfs(root->left,res,cur,target-root->val);
            cur.pop_back();
        }
    }
};