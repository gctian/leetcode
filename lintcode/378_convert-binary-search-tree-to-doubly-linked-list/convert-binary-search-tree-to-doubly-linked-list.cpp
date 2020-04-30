/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/convert-binary-search-tree-to-doubly-linked-list
@Language: C++
@Datetime: 17-02-20 13:03
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        // DoublyListNode* head = new DoublyListNode(-1);
        // if(!root) return NULL;
        
        // TreeNode *cur=root;
        // TreeNode *pre = NULL;
        // stack<TreeNode*> s;
        // while(cur || !s.empty()){
        //     while(cur){
        //         s.push(cur);
        //         cur=cur->left;
        //     }//一直遍历，直到左子树为空
        //     if(!s.empty()){
        //         TreeNode* temp = s.top();
        //         head->next = new DoublyListNode(temp->val);
        //         if(pre)
        //             head->prev = new DoublyListNode(pre->val);
                
        //         pre=temp;
                
        //         //如果存在右子树就接着遍历
        //         if(temp->right){
        //             cur = temp->right;
        //         }
        //     }
        // }
        // return head->next;
        
        //用递归
        if(!root) return NULL;
        DoublyListNode *mid = new DoublyListNode(root->val);
        DoublyListNode *dummy = new DoublyListNode(-1);
        
        //返回的是一个链表
        DoublyListNode* left = bstToDoublyList(root->left);
        DoublyListNode* right = bstToDoublyList(root->right);
        if(left){//左子树返回不为空
            //left只是链表的头指针，需要遍历到链表的最后
            dummy->next = left;
            while(left->next){
                left = left->next;
            }
            left->next = mid;
            mid->prev = left;
            
        }else{
            //左子树为空
            dummy->next = mid;
        }
        
        if(right){
            mid->next = right;
            right->prev = left;
        }
        return dummy->next;
    }
};


