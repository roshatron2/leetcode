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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next)
            return head;
        int len = 0;
        ListNode *cur = head,*prev;
        while(cur){
            len++;
            cur = cur->next;
        }
        cur = head;
        
        k = k % len;
        if(k == 0)
            return head;
        for(int i = 0; i < len - k; i++){
            prev = cur;
            cur = cur->next;
        }
        ListNode* newhead = cur;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = head;
        prev->next = NULL;
        return newhead;
    }
};