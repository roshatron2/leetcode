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
    vector<int> res;
    int max_level = -1;
    void dfs(TreeNode *root,int level){
        if(!root)
            return;
        if(level > max_level){
            res.push_back(root->val);
            max_level = level;
        }
        dfs(root->right,level + 1);
        dfs(root->left,level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return res;
        dfs(root,0);
        return res;
    }
};