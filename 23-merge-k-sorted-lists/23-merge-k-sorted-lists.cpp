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
    struct cmp{
        bool operator()(ListNode *a,ListNode *b){
            return a->val > b->val;
        }
    };        
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto head : lists){
            if(!head) continue;
            pq.push(head);
        }
        ListNode *tail = new ListNode(0);
        ListNode *dummy = tail;
        while(!pq.empty()){
            ListNode *cur = pq.top();
            pq.pop();
            tail->next = cur;
            tail = tail->next;
            if(cur->next) pq.push(cur->next);
        }
        return dummy->next;
    }
};