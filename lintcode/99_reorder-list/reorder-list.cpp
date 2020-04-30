/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/reorder-list
@Language: C++
@Datetime: 17-02-02 09:05
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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if(!head) return ;
        ListNode *slow=head,*fast=head->next;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }//slow是中点
        fast = slow->next;
        slow->next=NULL;
        //逆转fast开头的链表
        ListNode *pre = NULL;
        while(fast){
            ListNode *temp=fast->next;
            fast->next=pre;
            pre=fast;
            fast=temp;
        }//pre是逆转后的链表
        slow=head;fast=pre;
        //插入前半部分,合并,这时候的slow和fast都是当前节点
        while(fast&&slow){
            ListNode *lr=slow->next;
            ListNode *rr=fast->next;
            fast->next=lr;
            slow->next=fast;
            
            slow=lr;
            fast=rr;
            
        }
        
        
    }
};


