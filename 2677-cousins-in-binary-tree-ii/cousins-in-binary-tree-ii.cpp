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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;    
        vector<int> levels;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if(cur->left)
                    q.push(cur->left); 
                if(cur->right)
                    q.push(cur->right);
            }
            levels.push_back(sum);
        }

        q.push(root);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();

                int sibling_sum = 0;
                sibling_sum = cur->left ? cur->left->val : 0;
                sibling_sum += cur->right ? cur->right->val : 0;

                if(cur->left){
                    cur->left->val = levels[level + 1] - sibling_sum;
                    q.push(cur->left);
                }

                if(cur->right){
                    cur->right->val = levels[level + 1] - sibling_sum;
                    q.push(cur->right);
                }
            }
            level++;
        }
        root->val = 0;
        return root;
    }
};