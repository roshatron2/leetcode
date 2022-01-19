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
        unordered_set<ListNode*> set;
        ListNode *cur = head;
        
        while(cur){
            if(set.find(cur) != set.end()){
                return cur;
            }
            set.insert(cur);
            cur = cur->next;
        }
        return NULL;
    }
};