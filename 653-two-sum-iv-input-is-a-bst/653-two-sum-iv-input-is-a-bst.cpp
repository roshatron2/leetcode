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
    void inorder(TreeNode *root){
        if(!root)
            return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
       inorder(root);
       int l = 0,r = nums.size() - 1;
       while(l < r){
          int sum = nums[l] + nums[r];
          if(sum < k){
              l++;
          } else if(sum > k){
              r--;
          } else {
              return true;
          }
       }
       return false;
    }
};