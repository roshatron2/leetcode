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
    vector<string> res;
    void dfs(TreeNode *root,string cur){
        if(!root)
           return;
        cur += to_string(root->val) + "->";
        if(!root->left and !root->right){
            cur.resize(cur.size() - 2);
            res.push_back(cur); 
        }
        dfs(root->left,cur);
        dfs(root->right,cur);
    } 
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return res;
    }
};
// changed the position of second if condition

