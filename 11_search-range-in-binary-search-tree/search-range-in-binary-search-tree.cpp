/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/search-range-in-binary-search-tree
@Language: C++
@Datetime: 17-02-07 09:12
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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        vector<int> insort = inorder(root);
        if(insort.size()==0) return res;
        for(int i=0;i<insort.size();i++){
            if(insort[i]>=k1&&insort[i]<=k2){
                res.push_back(insort[i]);
            }
        }
        return res;
    }
    vector<int> inorder(TreeNode* root){
        vector<int> res;
        if(!root) return res;
        vector<int> left = inorder(root->left);
        vector<int> right = inorder(root->right);
        res.insert(res.end(),left.begin(),left.end());
        res.push_back(root->val);
        res.insert(res.end(),right.begin(),right.end());
        
        return res;
    }
};