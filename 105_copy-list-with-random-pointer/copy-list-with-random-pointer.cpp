/*
@Copyright:LintCode
@Author:   tiangc
@Problem:  http://www.lintcode.com/problem/copy-list-with-random-pointer
@Language: C++
@Datetime: 17-02-06 03:11
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if (!head) return NULL;
        //建立新链表同时，记录原链表和新链表节点的对应关系
        RandomListNode *res = new RandomListNode(head->label);
        RandomListNode *tail = res;
        map<RandomListNode*,RandomListNode*> m;
        m[head] = res;
        RandomListNode *cur = head->next;
        while(cur){
            //新节点
            RandomListNode *temp = new RandomListNode(cur->label);
            //新链表添加节点
            tail->next = temp;
            //对应关系
            tail = tail->next;
            m[cur] = tail;
            
            cur = cur->next;
            
        }//新链表建立完成
        
        // tail = res;
        // cur = head;
        // //遍历新链表添加random指针
        // while(tail){
        //     tail->random = m[cur->random];
        //     tail = tail->next;
        //     cur = cur->next;
        // }
        
        while(head){
            m[head]->random = m[head->random];
            head = head->next;
        }
        return res;
        
    }
};