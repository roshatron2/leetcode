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
    int max_sum = INT_MIN;
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int left_max = max(dfs(root->left),0);
        int right_max = max(dfs(root->right),0);
        max_sum = max(max_sum, root->val + left_max + right_max);
        return root->val + max(left_max, right_max);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};