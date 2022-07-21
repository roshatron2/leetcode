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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *start = head,*end = head,*beforeStart;
        if(left == right)
            return head;
        left--;
        while(left--){
           beforeStart = start;
           start = start->next; 
        }
        while(right--){
            end = end->next;
        }
        ListNode *cur = start,*prev = beforeStart,*next;
        while(cur != end){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if(beforeStart)
            beforeStart->next = prev;
        else
            head = prev;
        start->next = next;
        return head;
    }
};