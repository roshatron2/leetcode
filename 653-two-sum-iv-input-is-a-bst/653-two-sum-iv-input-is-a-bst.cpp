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
    unordered_set<int> set;
    bool found = false;
    void dfs(TreeNode *root,int k){
       if(!root)
           return;
        dfs(root->left,k);
        int complement = k - root->val;
        if(set.find(complement) != set.end()){
            found = true;
        }
        set.insert(root->val);
        dfs(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
       dfs(root,k);
       return found;
    }
};

/*
set - 2 3 4  


*/