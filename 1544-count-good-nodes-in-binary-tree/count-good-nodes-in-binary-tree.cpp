/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;    
        q.push({root, INT_MIN});
        int good_nodes = 0;
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            TreeNode* cur = p.first;
            int max_value = p.second;
            cout << cur->val << " " << max_value << endl;
            q.pop();
            if(cur->val >= max_value){
                good_nodes++;
            }
            if(cur->left){
                max_value = max(cur->val, max_value); 
                q.push({cur->left, max_value});
            }
            if(cur->right){
                max_value = max(cur->val, max_value); 
                q.push({cur->right, max_value});
            }
        }
        return good_nodes;
    }
};