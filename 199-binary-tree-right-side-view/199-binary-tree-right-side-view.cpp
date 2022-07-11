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
    vector<int> rightSideView(TreeNode* root) {
            
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        if(!root)
            return res;
        while(!q.empty()){
            int size = q.size();
            res.push_back(q.back()->val);
            for(int i = 0; i < size; i++){
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
        }
        return res;
    }
};