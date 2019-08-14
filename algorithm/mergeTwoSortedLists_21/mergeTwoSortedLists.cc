/*# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-14 11:23
# Email        : vigoroushui@gmail.com
# Filename     : mergeTwoSortedLists.cc
# Description  : watch the question in problem.md
# *******************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(NULL==l1)
            return l2;
        if(NULL==l2)
            return l1;
        if(l1->val>l2->val)
        {
            l2->next=mergeTwoLists(l1, l2->next);
            return l2;
        }else{
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
    }
};