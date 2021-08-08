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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *i = head;
        while(i){
            ListNode *mn = i;
            ListNode *j = i->next;
            while(j){
              if(j->val < mn->val){
                  mn = j;
              }  
              j = j->next;  
            }
            swap(i->val,mn->val);
            i = i->next;
        }
        return head;
    }
};