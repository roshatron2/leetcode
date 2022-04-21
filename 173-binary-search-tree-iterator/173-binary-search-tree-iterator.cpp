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
class BSTIterator {
    stack<TreeNode*> stack;
    void inorder(TreeNode *root){
        while(root){
            stack.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
      inorder(root); 
    }
    int next(){
        TreeNode *cur = stack.top();
        int val = cur->val;
        stack.pop();
        cur = cur->right;
        inorder(cur);
        return val;
    }
    
    bool hasNext() {
       return !stack.empty(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */