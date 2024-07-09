/**
 * @file 143.reorder_list.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.23
 * 
 * @copyright Copyright (c) 2024
 * 
 * 思路：fast-slow法二分链表，后半链表逆序，交叉合并前后两个链表
 * 注意：空链表，单节点链表，奇数个数的链表，偶数个数的链表
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
    void reorderList(ListNode *head) {
        if ( head == NULL )
            return; 
        //二分链表,tail follow mid
        ListNode *mid=head, *fast=head, *tail=NULL;
        while ( fast && fast->next ) {
            tail = mid;
            mid = mid->next;
            fast = fast->next->next;
        }       
        if ( fast ) {   //上面的二分链表，对于奇数个节点会导致后半比前半多一个节点，在此将多出的一个节点匀给前半
            tail = mid;
            mid = mid->next;
        }       
        tail->next = NULL; 
        //后半反转,tail follow mid, fast forward
        tail = NULL; 
        while ( mid ) { 
            fast = mid->next;
            mid->next = tail; 
            tail = mid;
            mid = fast; 
        }       
        mid = tail; 
        //后半插入前半, tail遍历左半，mid为待插入节点（右半），fast为下一个待插入节点（右半）
        tail = head; 
        while ( mid ) { 
            fast = mid->next;
            mid->next = tail->next;
            tail->next = mid;
            tail = mid->next;
            mid = fast; 
        }       
    }
};
