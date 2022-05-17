/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> map;
    void dfs(TreeNode* original,TreeNode* cloned){
        if(!original){
            return;
        } 
        map[original] = cloned;
        dfs(original->left,cloned->left);
        dfs(original->right,cloned->right);
    }
    TreeNode* search(TreeNode* root,TreeNode* target){
        if(!root)
            return root;
        if(root == target)
            return map[root];
        TreeNode* left = search(root->left,target);
        TreeNode* right = search(root->right,target);
        if(!left)
            return right;
        if(!right)
            return left;
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original,cloned);
        return search(original,target);
    }
};