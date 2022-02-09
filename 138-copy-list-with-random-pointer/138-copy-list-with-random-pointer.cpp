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
        unordered_map<Node*,Node*> map;
        if(!head)
            return head;
        Node* cur = head;
        while(cur){
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        Node* newHead = map[head];
        for(auto [k,v] : map){
            v->next = k->next ? map[k->next] : NULL;
            v->random = k->random ? map[k->random] : NULL;
        }
        return newHead;
    }
};