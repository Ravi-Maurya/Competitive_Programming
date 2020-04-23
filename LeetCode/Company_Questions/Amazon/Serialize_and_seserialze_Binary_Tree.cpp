class Codec {
private:

    char ourToken = ' '; // All streams are seperated by tokens (which can be 
    // either spaces, tabs, or new lines. Here we are using a space;
    
    void serializeHelper(TreeNode* root, ostringstream& OSS) {
        if (!root) {
            OSS << '#' << ourToken; // Chase with a space (ourToken)
            return;
        }
        
        OSS << root->val << ourToken;
        serializeHelper(root->left, OSS);
        serializeHelper(root->right, OSS);
        return;
    }
    
    TreeNode* deserializeHelper(istringstream& ISS) {
        string nodeHolder; // Holds either # or a number, in string form
        ISS >> nodeHolder; // Take first string (that isn't ourToken) from stream
        // and put it into nodeHolder;
        if (!nodeHolder.compare("#")) return nullptr; // If nodeHolder is "#" then a node doesn't exist there
        TreeNode* newNode = new TreeNode(stoi(nodeHolder));
        newNode->left = deserializeHelper(ISS);
        newNode->right = deserializeHelper(ISS);
        return newNode;
    }
    
public:

    string serialize(TreeNode* root) {
        ostringstream OSS;
        serializeHelper(root, OSS);
        // cout << OSS.str() << endl;
        return OSS.str();
    }

    TreeNode* deserialize(string data) {
        istringstream ISS(data); // Seed the stream with our data string.
        return deserializeHelper(ISS);
    }
};