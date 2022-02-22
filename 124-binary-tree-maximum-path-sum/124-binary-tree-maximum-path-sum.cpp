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
    int mx = INT_MIN;
    int dfs(TreeNode *root){
        if(!root)
            return 0;
        int leftMax = max(dfs(root->left),0);
        int rightMax = max(dfs(root->right),0);
        mx = max(mx,root->val + leftMax + rightMax);
        return root->val + max(leftMax,rightMax);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};