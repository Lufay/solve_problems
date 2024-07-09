/**
 * @file 147.insertion_sort_list.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.21
 * 
 * @copyright Copyright (c) 2024
 * 
 * 思路：二重循环，外层遍历插入点，内层寻找插入位置。这里我采用的方式是并不剪断链表，而是找到插入位置，将插入结点移交插入位置
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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *cur=head, *pcur=NULL;
        head = new ListNode(0);
        head->next = cur;
        for(pcur=cur,cur=cur->next; cur; pcur=cur,cur=cur->next) {  //使用前置指针pcur
            for(ListNode *pp=head,*p=pp->next; p != cur; pp=p,p=p->next) {  //同样是前置指针pp
                if(cur->val < p->val) { //找到插入位置
                    pcur->next = cur->next;
                    cur->next = p;
                    pp->next = cur;
                    cur=pcur;
                    break;  
                }       
            }       
        }       
        cur = head->next;
        delete head;
        return cur;
    }
};
