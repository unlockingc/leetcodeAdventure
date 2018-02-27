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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ret = head;
        ListNode** array;
        array = new ListNode*[n + 1];
        
        int end = -1;
        while( head != NULL )
        {    
            end ++;   
            array[end%(n + 1)] = head;
            
            head = head->next;
        }
        
        if( end == ( n - 1 ) )
        {
            ret = array[0]->next;
            free(array[0]);
            
        }
        else
        {
            array[(end + 1)%(n + 1)]->next = array[(end + 2)%(n + 1)]->next;
            free(array[(end + 2) %(n + 1)]);
        }
        
        
        /*for( int i = end + 1; i < end + n + 1; i ++ )
        {
            printf("%d\t", array[i%(n + 1)] -> val);
        }
        
        printf("\nstart: %d\t end: %d\n",(end + 1)%(n + 1),end%(n + 1));
        */
        
        free(array);
        return ret;
    }
};