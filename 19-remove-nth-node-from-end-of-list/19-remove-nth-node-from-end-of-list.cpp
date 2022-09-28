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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *cur = head;
        while(cur){
            cur = cur->next;
            len++;
        }
        cur = head; 
        ListNode *prev;
        for(int i = 0; i < len - n; i++){
            prev = cur;
            cur = cur->next;
        }
        if(prev)
            prev->next = cur->next;
        else
            head = head->next;
        delete cur;
        return head;
    }
};
/*
1->2
len = 2
cnt = 2 - 2 - 1 = -1
*/
