/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node *cur = head;
        while(cur){
            Node *temp = new Node(cur->val);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }
        cur = head;
        while(cur){
            cur->next->random = cur->random ? cur->random->next : NULL;
            cur = cur->next->next;
        }
        Node *oldHead = head;
        Node *newHead = head->next;
        Node *dummy = new Node(0);
        dummy->next = newHead;
        while(oldHead and newHead){
            oldHead->next = newHead->next;
            newHead->next = newHead->next ? newHead->next->next : NULL;
            oldHead = oldHead->next;
            newHead = newHead->next;
        }
        return dummy->next;
    }
};