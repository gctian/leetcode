/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/intersection-of-two-linked-lists
@Language: C++
@Datetime: 17-02-21 14:09
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if(headA==NULL || headB==NULL) return NULL;
        
        int k1=0,k2=0;
        ListNode *tempA=headA;
        ListNode *tempB = headB;
        while(tempA){
            k1++;
            tempA=tempA->next;
        }
        while(tempB){
            k2++;
            tempB=tempB->next;
        }
        
        tempA = headA;
        tempB = headB;
        
        
        int ab=k1-k2;
        if(ab<0){
            while(ab) {
                tempB=tempB->next;
                ab++;
            }
        }else{
            while(ab) {
                tempA=tempA->next;
                ab--;
            }
        }
        
        while(tempA && tempB){
            if(tempA->val == tempB->val){
                return tempA;
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};