# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-11 16:36
# Email        : vigoroushui@gmail.com
# Filename     : addTwoNumbers.cc
# Description  : watch the question in problem.md
# ******************************************************

/*整体思路：不考虑对齐补零，l1、l2链表相应结点的值存于sum中（判断非空后累加）,
 * 若sum>=10则将进位标识设为true,并在访问下一次结点时，++sum，否则为false。
 * 考虑最后一位的进位。*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode(0);//存放结果的链表头指针
        ListNode* p3=l3;//遍历结果链表
        bool flag=false;//进位标志
        int sum;
        while(l1!=NULL||l2!=NULL)
        {
            sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(flag)
                ++sum;
            p3->next=new ListNode(sum%10);
            p3=p3->next;
            flag=sum>=10?true:false;
        }
        if(flag)
            p3->next=new ListNode(1);
        return l3->next;
    }
};



