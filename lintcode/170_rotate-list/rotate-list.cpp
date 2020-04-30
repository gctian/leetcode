/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/rotate-list
@Language: C++
@Datetime: 17-02-02 04:08
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(!head) return NULL;
        ListNode *fast = head,*slow = head;//快慢指针
        
        //注意K大于链表长度的情况
        ListNode *temp = head;//用于求长度的遍历
        int len = 0;
        while(temp) {
            len++;
            temp = temp->next;
        }
        k = k % len;
        for(int i=0;i<k;i++){
            fast = fast->next;
        }
        //两个指针一起走
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        fast = slow->next;
        slow->next = NULL;
        
        return fast;
    }
};