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
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next){
            return NULL;
        }              
        ListNode *slow = head,*fast = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                // if(fast != slow)
                //     return NULL;

                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};