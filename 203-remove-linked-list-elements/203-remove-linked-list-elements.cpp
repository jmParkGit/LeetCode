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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prevNode=nullptr;
        ListNode* nextNode=nullptr;
        ListNode* myHead=nullptr;
        
        if(head==nullptr)
            return head;
        
        while(!prevNode && head) {
            if(head->val==val) {
                ListNode* temp=head;
                head=head->next;
                delete(temp);
                continue;
            }
            
            myHead=head;
            prevNode=head;
            nextNode=head->next;
        }
        
        while(nextNode) {
            if(nextNode->val == val) {
                ListNode* temp=nextNode;
                nextNode=nextNode->next;
                prevNode->next=nextNode;
                delete(temp);
                continue;
            }
            prevNode=nextNode;
            nextNode=nextNode->next;            
        }
        
        return myHead;
    }
};