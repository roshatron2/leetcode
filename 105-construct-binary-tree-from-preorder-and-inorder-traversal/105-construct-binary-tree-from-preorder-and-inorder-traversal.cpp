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
    unordered_map<int,int> map;
    int p = 0;
    TreeNode* arrayToTree(vector<int> preorder,int left,int right){
        if(left > right)
            return NULL;
        int rootIdx = map[preorder[p]];
        TreeNode *root = new TreeNode(preorder[p++]);
        root->left = arrayToTree(preorder,left,rootIdx - 1);
        root->right = arrayToTree(preorder,rootIdx + 1,right);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return arrayToTree(preorder,0,preorder.size() - 1);
    }
};