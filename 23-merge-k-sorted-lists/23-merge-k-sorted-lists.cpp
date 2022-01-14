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
    struct cmp {
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto list : lists) {
            if(!list) continue;
            pq.push(list);
        }
        if(pq.empty())
            return NULL;
        ListNode *dummy = new ListNode(0), *tail = dummy;
        while (!pq.empty()) {
            ListNode *top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;
            if (top and top->next) {
                pq.push(top->next);
            }
        }
        return dummy->next;
    }
};