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
    int mx = 0;
    vector<int> lefts;
    void dfs(TreeNode *root,int depth,int i){
        if(!root)
            return;
        if(depth == lefts.size()){
            lefts.push_back(i);
        }
        mx = max(mx,i - lefts[depth] + 1);
        dfs(root->left,depth + 1,(long long)i * 2 + 1);
        dfs(root->right,depth + 1, (long long)i * 2 + 2);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,0,0);
        return mx;    
    }
};