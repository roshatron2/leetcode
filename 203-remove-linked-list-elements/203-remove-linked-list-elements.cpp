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
        ListNode *dummy = new ListNode(0,head);
        ListNode *cur = dummy,*next;
        while(cur and cur->next){
            if(cur->next->val == val){
                next = cur->next;
                while(next and next->val == val){
                    next = next->next;
                }
                cur->next = next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};