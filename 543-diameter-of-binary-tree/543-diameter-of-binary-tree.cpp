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
    int max_diameter = 0;
    int maxDepth(TreeNode *root){
        if(!root)
            return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        int cur = maxDepth(root->left) + maxDepth(root->right);
        return max(cur,max(ld,rd));
    }
};