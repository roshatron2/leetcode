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
    vector<vector<int>> paths;
    void dfs(TreeNode *root,vector<int> path){
        if(!root)
            return;
        if(!root->left and !root->right){
            path.push_back(root->val);
            paths.push_back(path);
            return;
        }
        path.push_back(root->val);
        dfs(root->left,path);
        dfs(root->right,path);
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root,{});
        int sum = 0;
        for(auto row : paths){
            int cur = 0;
            for(auto i : row){
                cur = cur * 2 + i;
            }
            sum += cur;
        }
        return sum;
    }
};