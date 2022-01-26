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
    void dfs(TreeNode *root,vector<int> &nums){
        if(!root)
            return;
        dfs(root->left,nums);
        nums.push_back(root->val);
        dfs(root->right,nums);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1,nums2,res;
        dfs(root1,nums1);
        dfs(root2,nums2);
        int i = 0,j = 0;
        while(i < nums1.size() and j < nums2.size()){
            if(nums1[i] < nums2[j]){
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size()){
            res.push_back(nums1[i++]);
        }
        while(j < nums2.size()){
            res.push_back(nums2[j++]);
        }
        return res;
    }
};