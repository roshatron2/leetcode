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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left,right,depth;
        left = minDepth(root->left);
        right = minDepth(root->right);
        if(left == 0)
            depth = right;
        else if(right == 0)
            depth = left;
        else
            depth = min(left,right);
        return 1 + depth;
        
        
        
    }
};