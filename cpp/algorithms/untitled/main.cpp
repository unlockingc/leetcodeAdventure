#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include <map>
#include <list>
#include <algorithm>
#include <time.h>
#include <memory.h>
#include <assert.h>
#include <unordered_map>

using namespace std;



//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct cmp
{
    bool operator()(const ListNode* a,const ListNode* b)
    {
        return a->val >= b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        for (vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); iter++)
        {
            printf("val: %d\n", (*iter)->val);
            if( (*iter)->val == 5 ) {
                lists.erase(iter);
                iter --;
            }
        }

        cout <<"================"<< endl;
        make_heap(lists.begin(), lists.end(), cmp() );

        while(lists.size())
        {
            pop_heap(lists.begin(), lists.end(), cmp());
            ListNode* temp = lists.back();
            lists.pop_back();
            printf("val: %d\n",temp->val);

            if( temp->next != NULL )
            {
                lists.push_back(temp->next);
                push_heap(lists.begin(), lists.end(), cmp());
            }
        }
        return NULL;
    }
};



int main() {
    vector<ListNode*> hehe;
    ListNode* a,*b,*c,*d, *e;
    a = new ListNode(1);
    b = new ListNode(2);
    c = new ListNode(3);
    d = new ListNode(4);
    e = new ListNode(5);

    a->next = b;
    hehe.push_back(e);
    hehe.push_back(d);
    hehe.push_back(a);
    hehe.push_back(c);
    Solution sol;
    sol.mergeKLists(hehe);
    return 0;
}