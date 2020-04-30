/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-preorder-and-inorder-traversal
@Language: C++
@Datetime: 17-02-07 09:04
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if(preorder.size()==0||inorder.size()==0) return NULL;
        return buildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
        
    }
    TreeNode *buildTree(vector<int>::iterator prebegin,vector<int>::iterator preend,
                        vector<int>::iterator inbegin,vector<int>::iterator inend){
        if(prebegin == preend )  return NULL;
        TreeNode *root = new TreeNode(*prebegin);
        vector<int>::iterator mid = find(inbegin,inend,*prebegin);
        int leftLen = mid - inbegin;
        root->left = buildTree(prebegin+1, prebegin+1+leftLen,inbegin,mid);
        root->right = buildTree(prebegin+1+leftLen, preend,mid+1,inend);
        
        return root;
    }
};