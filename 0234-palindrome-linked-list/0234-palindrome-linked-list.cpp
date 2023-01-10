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
private:
    vector<int> stk;
public:
    bool isPalindrome(ListNode* head) {
        ListNode* myHead=head;

        while(myHead) {
            stk.push_back(myHead->val);
            myHead = myHead->next;
        }

        if(1 == stk.size()) {
            return true;
        }

        for(int i=0; i<stk.size()/2; i++) {
            if(stk[i] != stk[stk.size()-1-i]){
                return false;
            }
        }

        return true;
    }
};