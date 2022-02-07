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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root)
            return res;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> row = {};
            for(int i = 0; i < size; i++){
                TreeNode *cur = q.front();
                q.pop();
                if(cur) row.push_back(cur->val);
                if(cur->left) 
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(level % 2){
                reverse(row.begin(),row.end());
            }
            res.push_back(row);
            level++;
        }
        return res;
    }
};