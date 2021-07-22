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
    void BFS(Node *node,unordered_map<Node*,Node*> &map){
        queue<Node*> q;
        unordered_map<Node*,bool> visited;
        visited[node] = true;        
        q.push(node);
        while(!q.empty()){
            Node *cur = q.front();
            map[cur] = new Node(cur->val);
            q.pop();
            for(auto i : cur->neighbors){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        unordered_map<Node*,Node*> map;
        BFS(node,map);
        for(auto [k,v] : map){
            for(auto i : k->neighbors){
                v->neighbors.push_back(map[i]);
            }
        }
        return map[node];
        
    }
};