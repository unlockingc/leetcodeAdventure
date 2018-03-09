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
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n = 1;
        
        if( head == NULL || head->next == NULL )
        {
            return head;
        }
        
        ListNode* first =  head;
        
        while( first->next!=NULL )
        {
            first = first->next;
            n ++;
        }
        
        int where = k > n? (n - k%n) : n - k;
        
        if( where == 0 )
        {
            return head;
        }
        
        first->next = head;
 
        
        first = head;
        int count = 1;
        while( count < where )
        {
            first = first->next;
            count ++;
        }
        
        ListNode* ret = first->next;
        first->next = NULL;
        return ret; 
        
    }
};