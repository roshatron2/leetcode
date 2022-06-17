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
    int count = 0;
    string dfs(TreeNode *root){
       if(!root){
           return "ok";
       } 
       string left = dfs(root->left);
       string right = dfs(root->right);
       
       if(left == "not_covered" or right == "not_covered"){
           count++;
           return "covered";
       }
       if(left == "covered" or right == "covered"){
           return "ok";
       }
       return "not_covered";
    }
    int minCameraCover(TreeNode* root) {
       string base = dfs(root); 
       if(base == "not_covered") count++;
       return count;
    }
};