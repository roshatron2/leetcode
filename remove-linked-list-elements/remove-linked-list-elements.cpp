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
        ListNode *prev = NULL,*dummyHead = new ListNode(0,head);
        if(!head){
            return head;
        }
        ListNode *cur = dummyHead;
        prev = cur;
        while(cur){
            if(cur->val == val){
               prev->next = cur->next; 
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return dummyHead->next;
    }
};