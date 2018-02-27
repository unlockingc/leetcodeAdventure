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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == NULL)
        {
            return l2;
        }
        else if(l2 == NULL)
        {
            return l1;
        }
        
        ListNode* start = (l1->val <= l2->val) ? l1 : l2;
        (l1->val <= l2->val) ? l1 = l1->next : l2 = l2->next;
        
        ListNode* ret = start;
        
        while( l1!=NULL && l2!=NULL )
        {
            start->next = (l1->val <= l2->val) ? l1 : l2;
            start = start->next;
            (l1->val <= l2->val) ? l1 = l1->next : l2 = l2->next;
        }
        
        if(l1 == NULL)
        {
            start->next = l2;
        }
        else
        {
            start->next = l1;
        }
        
        return ret;
    }
};