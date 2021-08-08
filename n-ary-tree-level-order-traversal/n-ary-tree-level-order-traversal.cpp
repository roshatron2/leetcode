/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public: 
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> row = {};
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node *cur = q.front();
                q.pop();
                row.push_back(cur->val);
                for(auto i : cur->children){
                    q.push(i);
                }
            }
            res.push_back(row);
        }
        return res;
    }
};