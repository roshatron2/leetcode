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
        vector<int> copy;
        ListNode *cur = head;
        while(cur){
            copy.push_back(cur->val);
            cur = cur->next;
        }
        sort(copy.begin(),copy.end());
        cur = head;
        for(int i : copy){
            cur->val = i;
            cur = cur->next;
        }
        return head;
    }
};