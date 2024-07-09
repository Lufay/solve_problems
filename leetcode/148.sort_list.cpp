/**
 * @file 148.sort_list.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.20
 * 
 * @copyright Copyright (c) 2024
 * 
 * 思路：归并排序，用递归确保constant space complexity，而实现递归找链表中间位置就用到fast-slow法（一个指针走1步，一个走2步）
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
    ListNode *mergeList(ListNode *la, ListNode *lb) {
        ListNode *res = new ListNode(0), *p = res;
        while( la && lb ) {
            if ( la->val < lb->val ) {
                p->next = la;
                la = la->next;
            }       
            else {  
                p->next = lb;
                lb = lb->next;
            }       
            p = p->next;
        }       
        p->next = la ? la : lb;
        p = res->next;
        delete res;
        return p;
    }
    ListNode *sortList(ListNode *head) {
        if ( head == NULL || head -> next == NULL )
            return head;
        ListNode *mid = head, *fast = head, *head_tail = NULL; 
        while( fast && fast->next ) {
            head_tail = mid;
            mid = mid->next;
            fast = fast->next->next;
        }       
        head_tail->next = NULL; 
        return mergeList(sortList(head), sortList(mid));
    }
};
