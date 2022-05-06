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
    vector<vector<int>> res;
    int target;
    void dfs(TreeNode *root,int sum,vector<int> cur){
       if(!root)
            return;
       sum += root->val;
       cur.push_back(root->val);
       if(sum == target and !root->left and !root->right){
           res.push_back(cur);
           return;
       }
       dfs(root->left,sum,cur);
       dfs(root->right,sum,cur);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       this->target = targetSum;
       dfs(root,0,{});
       return res;
    }
};