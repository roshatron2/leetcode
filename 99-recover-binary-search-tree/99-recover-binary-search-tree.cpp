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
    void sort(vector<int> &arr){
        int n = nums.size();
        for (int i = n-1; i > 0; i--)
        {
            if (arr[i] < arr[i-1]){
                int j = i-1;
                while (j>=0 && arr[i] < arr[j])
                    j--;
 
                swap(arr[i], arr[j+1]);
                break;
            }
        }
    } 
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(nums);
        recover(root);
    }
};