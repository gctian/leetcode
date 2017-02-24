/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/convert-sorted-list-to-balanced-bst
@Language: C++
@Datetime: 17-02-03 04:58
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(!head) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *slow=dummy,*fast=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }//slow是中点的前驱节点
        TreeNode *root = new TreeNode(slow->next->val);
        //分两半
        fast=slow->next->next;
        slow->next=NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast);
        return root;
    }
};


