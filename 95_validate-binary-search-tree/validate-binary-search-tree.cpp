/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/validate-binary-search-tree
@Language: C++
@Datetime: 17-02-07 04:39
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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        
        // return isBST(root,LONG_MIN,LONG_MAX);
        
        vector<int> res = preOrder(root);
        if(res.size()==0) return true;
        for(int i=0;i<res.size()-1;i++){
            if(res[i]>=res[i+1]) return false;
        }
        return true;
    }
    
    bool isBST(TreeNode *root ,long lmin,long lmax){
        if(!root) return true;
        if(root->val <= lmin || root->val >= lmax) return false;
        bool left = isBST(root->left,lmin,root->val);
        bool right = isBST(root->right,root->val,lmax);
        return left&&right;
    }
    vector<int> preOrder(TreeNode* root){
        
        vector<int> res;
        if(!root) return res;
        vector<int> left = preOrder(root->left);
        vector<int> right = preOrder(root->right);
        res.insert(res.end(),left.begin(),left.end());
        res.push_back(root->val);
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
};