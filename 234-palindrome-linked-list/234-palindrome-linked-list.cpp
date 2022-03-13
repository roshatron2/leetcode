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
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        stack<int> st;
        while(cur){
            st.push(cur->val);
            cur = cur->next;
        }
        cur = head;
        while(cur){
            if(st.top() != cur->val){
                return false;
            }
            st.pop();
            cur = cur->next;
        }
        return true;
    }
};