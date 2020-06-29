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
    char token = ' ';
    void serialize(TreeNode* root, ostringstream& OSS) {
        if(!root){
            OSS << '#' << token;
            return;
        }
        OSS << root->val << token;
        serialize(root->left,OSS);
        serialize(root->right,OSS);
        return;
    }
    TreeNode* deserialize(istringstream& ISS){
        string res;
        ISS >> res;
        if(!res.compare("#"))
            return nullptr;
        TreeNode* root = new TreeNode(stoi(res));
        root->left = deserialize(ISS);
        root->right = deserialize(ISS);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream OSS;
        serialize(root, OSS);
        return OSS.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ISS(data);
        return deserialize(ISS);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));