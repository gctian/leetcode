/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-lists
@Language: C++
@Datetime: 17-02-01 07:34
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        //生成要返回的新链表
        ListNode* res = new ListNode(-1);//next指向NULL
        //链表题最终返回头指针节点，所以新链表头结点不能动，遍历时候用一个临时指针
        ListNode* temp = res;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                //当前l1接到新链表后面
                temp->next = l1;
                l1 = l1->next;
                
            }else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        //l1 或者l2有一个为空,把另一个直接接到新链表后面
        if(l1==NULL){
            temp->next = l2;
        }else{
            temp->next = l1;
        }
        return res->next;
    }
};