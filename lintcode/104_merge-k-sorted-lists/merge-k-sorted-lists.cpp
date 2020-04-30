/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/merge-k-sorted-lists
@Language: C++
@Datetime: 17-02-16 07:57
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        int len = lists.size();
        if(len==0) return NULL;
        if(len==1) return lists[0];
        
        return mergeHelper(lists,0,len-1);
        
    }
    
    ListNode *mergeHelper(vector<ListNode *> &lists,int start,int end){
        if(start == end) {
            return lists[start];
        }

        int mid = (start + end) / 2;            
        ListNode* l1 = mergeHelper(lists, start, mid);
        ListNode* l2 = mergeHelper(lists, mid + 1, end);
        return mergeTwoLists(l1, l2);
    }
    
    
    ListNode *mergeTwoLists(ListNode *l1,ListNode *l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail=dummy;
        while(l1&&l2){
            if(l1->val < l2->val){
                tail->next=l1;
                l1=l1->next;
            }else{
                tail->next=l2;
                l2=l2->next;
            }
            tail = tail->next;
        }
        if(l1) tail->next=l1;
        if(l2) tail->next=l2;
        
        return dummy->next;
        
    }
};


