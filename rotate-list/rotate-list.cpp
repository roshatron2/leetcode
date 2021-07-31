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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *cur = head;
        if(!head)
            return head;
        vector<int> copy;
        while(cur){
            copy.push_back(cur->val);
            cur = cur->next;
        }
        k = k % copy.size();
        rotate(copy.begin(),copy.begin() + copy.size() - k,copy.end());
        cur = head;
        int i = 0;
        while(cur){
            cur->val = copy[i++];
            cur = cur->next;
        }
        return head;
    }
};