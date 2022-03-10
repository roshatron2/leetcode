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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> odd,even;
        ListNode *cur = head;
        int i = 1;
        while(cur){
            if(i % 2 == 0){
                even.push_back(cur->val);
            } else {
                odd.push_back(cur->val);
            }
            cur = cur->next;
            i++;
        }
        cur = head;
        for(int i : odd){
            cur->val = i;
            cur = cur->next;
        }
        for(int i : even){
            cur->val = i;
            cur = cur->next;
        }
        return head;
    }
};