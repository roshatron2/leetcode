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
    vector<int> preorder;
    unordered_map<int,int> indexMap;
    int i = 0;
    TreeNode* dfs(int l, int r){
        if(l > r){
            return nullptr;
        }
        int val = preorder[i++];
        TreeNode* node = new TreeNode(val);
        int index = indexMap[val];
        node->left = dfs(l,index - 1);
        node->right = dfs(index + 1, r);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i = 0; i < inorder.size(); i++){
            indexMap[inorder[i]] = i;
        }
        return dfs(0,preorder.size() - 1);
    }
};
