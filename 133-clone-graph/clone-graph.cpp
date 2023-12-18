/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* dfs(Node* node){
        Node* copy = new Node(node->val);
        map[node] = copy;
        for(Node* nei : node->neighbors){
            if(map[nei]){
                copy->neighbors.push_back(map[nei]);
            } else {
                copy->neighbors.push_back(dfs(nei));
            }
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        return dfs(node);
    }
};