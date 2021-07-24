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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3,*cur;
        ListNode *dummyHead = new ListNode(0);
        l3 = dummyHead;
        int carry = 0,x,y;
        
        while(l1 or l2){
            x = l1 ? l1->val : 0;
            y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            cur = new ListNode(sum % 10);
            l3->next = cur;
            l3 = cur;
            cur = cur->next;
            carry = sum / 10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry){
            cur = new ListNode(carry);
            l3->next = cur;
        }
        return dummyHead->next;
    }
};