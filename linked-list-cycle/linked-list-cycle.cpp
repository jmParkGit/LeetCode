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
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool> m;
        ListNode* mHead=head;
        bool ret=false;
        
        if(head == nullptr)
            return ret;
        
        m.insert({mHead,true});
        mHead=mHead->next;
        while(mHead)
        {
            if(m.find(mHead)!=m.end())
            {
                ret=true;
                break;
            }
            
            m.insert({mHead,true});
            mHead=mHead->next;
        }
        
        return ret;
    }
};