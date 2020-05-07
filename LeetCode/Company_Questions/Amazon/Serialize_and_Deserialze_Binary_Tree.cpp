class Codec {
private:

    char ourToken = ' ';
    void serializeHelper(TreeNode* root, ostringstream& OSS) {
        if (!root) {
            OSS << '#' << ourToken;
            return;
        }
        
        OSS << root->val << ourToken;
        serializeHelper(root->left, OSS);
        serializeHelper(root->right, OSS);
        return;
    }
    
    TreeNode* deserializeHelper(istringstream& ISS) {
        string nodeHolder;
        ISS >> nodeHolder;
        
        if (!nodeHolder.compare("#"))
            return nullptr;
        TreeNode* newNode = new TreeNode(stoi(nodeHolder));
        newNode->left = deserializeHelper(ISS);
        newNode->right = deserializeHelper(ISS);
        return newNode;
    }
    
public:

    string serialize(TreeNode* root) {
        ostringstream OSS;
        serializeHelper(root, OSS);
        return OSS.str();
    }

    TreeNode* deserialize(string data) {
        istringstream ISS(data);
        return deserializeHelper(ISS);
    }
};