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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        priority_queue<int> pq;
        while(!q.empty()){
            TreeNode *cur = q.front();
            pq.push(cur->val);
            q.pop();
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        int n = pq.size();
        int i = 0;
        while(i < n - k){
            pq.pop();
            i++;
        }
        return pq.top();
    }
};
