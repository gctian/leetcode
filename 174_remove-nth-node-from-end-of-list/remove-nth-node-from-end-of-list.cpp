/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: C++
@Datetime: 17-02-01 06:51
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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if(!head){
        	return NULL;
		}
// 		ListNode* slow = new ListNode(-1);
// 		slow->next = head;
// 		ListNode* fast = head;
		
// 		ListNode* temp = slow;
		
// 		for(int i=0;i<n;i++){
// 			fast = fast->next;
// 		}
// 		while(fast!=NULL){
// 			temp = temp->next;
// 			fast = fast->next;
// 		}
// 		//此时slow->next是倒数第n个节点，执行删除
// 		temp->next = temp->next->next; 
		
// 		return slow->next;

        ListNode* res = new ListNode(-1);
        res->next = head;
        //因为是返回头结点，所以遍历的时候要有一个临时节点
        ListNode* temp = res;
        //先遍历head到第n的位置
        for(int i=0;i<n;i++){
            head = head->next;
        }
        //temp开始和head一起移动，直到head为空，此时temp->next即为要删除的节点
        while(head!=NULL){
            head = head->next;
            temp = temp->next;
        }
        //删除
        temp->next = temp->next->next;
        return res->next;
    }
};


