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
       ListNode *slow = head,*fast = head,*prev;
       while(n--){
           fast = fast->next;
       }
       while(fast){
           prev = slow;
           slow = slow->next;
           fast = fast->next;
       }
       if(prev)
           prev->next = slow->next;
       else
           head = head->next;
       delete slow;
       return head; 
    }
};