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
        unordered_map<ListNode*,bool> map;    
        ListNode *cur = head;
        while(cur){
            if(map.count(cur)){
                return cur;
            }
            map[cur] = true;
            cur = cur->next;
        }
        return NULL; 
    }
};