/*# *******************************************************
  # Author       : Vigoroushui
  # Last modified: 2019-08-14 11:26
  # Email        : vigoroushui@gmail.com
  # Filename     : mergeTwoSortedLists_2.cc
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
//遍历+尾插
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *head=new ListNode(0);
        ListNode *res=head;
        while(l1&&l2)
        {
            if(l1->val>l2->val)
            {
                res->next=l2;
                l2=l2->next;
            }else{
                res->next=l1;
                l1=l1->next;
            }
            res=res->next;
            res->next=NULL;
        }
        if(l1)
            res->next=l1;
        if(l2)
            res->next=l2;
        res=head->next;
        delete head;
        return res;
    }
};