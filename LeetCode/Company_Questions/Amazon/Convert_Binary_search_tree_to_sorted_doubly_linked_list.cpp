class Solution {
    Node* pre = NULL;
    public:
    void inorder(Node root) {
        if(!root)
            return;
        inorder(root->left);
        pre->right = root;
        root->left = pre;
        pre = root;
        inorder(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return NULL;
        Node* sentinel = new Node(0);
        pre = sentinel;
        inorder(root);
        sentinel->right->left = pre;
        pre->right = sentinel->right;
        return sentinel->right;
    }
};