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
     
        ListNode* ret = NULL;
        ListNode* now = NULL;
        
        for (vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); iter++)
        {
            //printf("val: %d\n", (*iter)->val);
            if( (*iter) == NULL ) {
                lists.erase(iter);
                iter --;
            }
        }
        
        if( lists.size() == 0 )
        {
            return NULL;
        }
        
        make_heap(lists.begin(), lists.end(), cmp() );
        
        
        pop_heap(lists.begin(), lists.end(), cmp());
            
        ret = lists.back();
        now = ret;
        lists.pop_back();
        //printf("val: %d\n",temp->val);
        if( now->next != NULL )
        {
            lists.push_back(now->next);
            push_heap(lists.begin(), lists.end(), cmp());
        }
        
        while(lists.size())
        {
            pop_heap(lists.begin(), lists.end(), cmp());
            
            now->next = lists.back();
            now=now->next;
            lists.pop_back();
            //printf("val: %d\n",temp->val);
            if( now->next != NULL )
            {
                lists.push_back(now->next);
                push_heap(lists.begin(), lists.end(), cmp());
            }
        }
        
        return ret;
    }
};
