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
    bool dfs(TreeNode* root1, TreeNode* root2){
        if(!root1 and !root2){
            return true;
        }

        if(!root1 or !root2){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }
        return dfs(root1->left, root2->left) and dfs(root1->right, root2->right) 
        or dfs(root1->left, root2->right) and dfs(root1->right, root2->left);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};