/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "null";
        }    
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    TreeNode* helper(stringstream& ss){
        string token;
        getline(ss, token, ',');
        if(token == "null"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(token));
        root->left = helper(ss);
        root->right = helper(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return helper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));