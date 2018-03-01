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
    ListNode* reverse(ListNode* head) {
        ListNode *pre, *cur, *next;
        pre = NULL;
        cur = head;

        if (head == NULL || head->next == NULL)
            return head;
        while(cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *list, *tail, *ret, *temp, *cur;

        if (head == NULL || head->next == NULL || k == 1)
            return head;
        ret = NULL;
        tail = NULL;
        cur = head;

        int ik = 0;
        while(cur != NULL) {
            ik ++;
            if (ik % k == 1) {
                list = cur;
                cur = cur->next;
            } else if (ik % k == 0) {
                temp = cur->next;
                cur->next = NULL;
                if (ret == NULL) {
                    ret = reverse(list);
                } else
                    tail->next = reverse(list);
                tail = list;
                cur = temp;
            } else {
                cur = cur->next;
            }
        }
        if (ik % k != 0 && tail != NULL)
            tail->next = list;
        else if (ik % k != 0 && tail == NULL)
            return head;

        return ret;
    }
};
