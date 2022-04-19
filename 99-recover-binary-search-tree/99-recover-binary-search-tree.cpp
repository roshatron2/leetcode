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
    vector<int> nums;
    int pos = 0;
    void inorder(TreeNode *root){
        if(!root)
            return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    void recover(TreeNode *root){
        if(!root)
            return;
        recover(root->left);
        root->val = nums[pos++];
        recover(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(nums.begin(),nums.end());
        recover(root);
    }
};