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
    ListNode* sortList(ListNode* head) {
        ListNode *i = head;
        if(!head or !head->next)
            return head;
        map<int,int> map;
        while(i){
            map[i->val]++;
            i = i->next;
        }
        i = head;
        for(auto [k,v] : map){
            for(int j = 0; j < v; j++){
                i->val = k;
                i = i->next;
            }
        }
        return head;
    }
};