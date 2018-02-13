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
        ListNode* root = new ListNode(0);
        int temp_sum;
        int carry = 0;

        ListNode* ans = root;
        while( l1 || l2 || carry ) {
            temp_sum = carry;
            if (l1) {
                temp_sum += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                temp_sum += l2 -> val;
                l2 = l2 -> next;
            }
            ans -> next = new ListNode(temp_sum % 10);
            ans = ans -> next;
            carry = temp_sum / 10;
        }
        return root -> next;
    }
};
