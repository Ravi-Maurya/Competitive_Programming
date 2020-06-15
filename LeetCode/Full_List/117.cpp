/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* getnext(Node* root){
        Node* curr = root->next;
        while(curr){
            if(curr->left)
                return curr->left;
            if(curr->right)
                return curr->right;
            curr = curr->next;
        }
        return NULL;
    }
    
    Node* connect(Node* root) {
        Node* curr = root;
        if(!root)
            return NULL;
        curr->next = NULL;
        while(curr){
            Node* tmp = curr;
            while(tmp){
                if(tmp->left){
                    if(tmp->right)
                        tmp->left->next = tmp->right;
                    else
                        tmp->left->next = getnext(tmp);
                }
                if(tmp->right)
                    tmp->right->next = getnext(tmp);
                tmp = tmp->next;
            }
            if(curr->left)
                curr = curr->left;
            else if(curr->right)
                curr = curr->right;
            else
                curr = getnext(curr);
        }
        return root;
    }
};