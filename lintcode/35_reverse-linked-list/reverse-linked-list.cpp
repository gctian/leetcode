/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/reverse-linked-list
@Language: C++
@Datetime: 17-02-01 13:01
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(!head) return NULL;
        ListNode *pre=NULL;
        ListNode *temp=NULL;
        while(head){
            temp=head;
            head=head->next;
            temp->next=pre;
            //ć´ć°pre
            pre=temp;
        }
        return pre;
    }
};
