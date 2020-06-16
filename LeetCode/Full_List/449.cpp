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
    void serialize(TreeNode* root, ostringstream& OSS){
        if(!root){
            OSS<< '#' << ' ';
            return;
        }
        OSS<< root->val << ' ';
        serialize(root->left,OSS);
        serialize(root->right,OSS);
        return;
    }
    string serialize(TreeNode* root) {
        ostringstream OSS;
        serialize(root,OSS);
        return OSS.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(istringstream& ISS){
        string node;
        ISS >> node;
        if(!node.compare("#"))
            return nullptr;
        TreeNode* root = new TreeNode(stoi(node));
        root->left = deserialize(ISS);
        root->right = deserialize(ISS);
        return root;
    }
    TreeNode* deserialize(string data) {
        istringstream ISS(data);
        return deserialize(ISS);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));