/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/sort-list
@Language: C++
@Datetime: 17-02-02 13:39
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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *mergeList(ListNode *left,ListNode *right){
        if(left==NULL) return right;
        if(right==NULL) return left;
        ListNode *res=new ListNode(-1);
        ListNode *tail=res;
        while(left&&right){
            if(left->val < right->val){
                tail->next=left;
                left=left->next;
            }else{
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        if(left) tail->next=left;
        if(right) tail->next=right;
        return res->next;
    }
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(!head) return NULL;
        if(head->next==NULL) return head;
        ListNode *slow=head,*fast=head->next;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=slow->next;
        slow->next=NULL;
        
        //左右两边递归
        ListNode *left=sortList(head);
        ListNode *right=sortList(fast);
        //归并
        ListNode *res=mergeList(left,right);
        return res;
    }
};


