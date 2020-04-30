/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: C++
@Datetime: 17-02-01 08:11
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head) return NULL;
        // ListNode* res = new ListNode(-1);
        // ListNode* temp = res;
        
        // while(head!=NULL){
        //     if(head->val == temp->val){
        //         head = head->next;
        //     }else{
        //         //temp->next=head是把head之后的节点都链接到temp->next
        //         temp->next = new ListNode(head->val);
        //         head = head->next;
        //         temp = temp->next;
        //     }
        // }
        // return res->next;
        
        //不构造新链表
        ListNode* node = head;
        while(node->next!=NULL){
            //当前节点和下一个节点的值一样,就跳过下一个节点
            if(node->val == node->next->val){
                node->next = node->next->next;
            }else{
                node = node->next;
            }
        }
        return head;
    }
};