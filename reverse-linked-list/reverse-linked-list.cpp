/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<ListNode*> stk;
        ListNode* myHead=head;
        ListNode* ret;
        
        if(head==nullptr)
            return head;
        
        //set node to stack
        while(myHead) {
            stk.push_back(myHead);
            myHead=myHead->next;
        }
        
        //reverse Linked List
        myHead=stk.back();
        stk.pop_back();
        ret=myHead;
        while(!stk.empty()) {
            myHead->next=stk.back();
            stk.pop_back();
            
            myHead=myHead->next;
        }
        myHead->next=nullptr;
        
        return ret;
    }
};